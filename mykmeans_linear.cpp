#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <algorithm>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

struct User {
  int chosenX;
  int chosenY;
  Mat skinImg; //img containing desired background/skin color
  Mat destImg; //img to edit background & replace w/ skin color
  Vec3b chosenColor;
  bool colorPicked;
};

//checks whether the values in 2 vecs are equal
int areEqual(Vec3b vec1, Vec3b vec2) {
  return (vec1[0]==vec2[0] && vec1[1]==vec2[1] && vec1[2]==vec2[2]);
}

//finds the max number of vecs that are equal and returns it. 
//if none are the same as eachother then returns null
Vec3b findMaxCommon(Vec3b v1, Vec3b v2, Vec3b v3, Vec3b v4) {

  bool v1v2 = areEqual(v1, v2);
  bool v1v3 = areEqual(v1, v3);
  bool v1v4 = areEqual(v1, v2);
  bool v2v3 = areEqual(v1, v3);
  bool v2v4 = areEqual(v1, v2);
  bool v3v4 = areEqual(v1, v3);

  if (v1v2 && v1v3 && v1v4) { //all equal
    return v1;
  } else if ((v1v2 && v1v3) || (v1v2 && v1v4) || (v1v3 && v1v4)) { //3 are equal (all including v1)
    return v1;
  } 

  if (v2v3 && v2v4) {
    return v2;
  } 

  //just pairs 
  if (v1v2 || v1v3 || v1v4) {
    return v1;
  } else if (v2v3 || v2v4) {
    return v2;
  } else if (v3v4) {
    return v3;
  }
  return v1; //no matching pairs: default is v1
}

void CallBackFunction2(int event, int x, int y, int s, void* user) {
  
  if (event == EVENT_LBUTTONDOWN) {
    std::cout<<"mouse clicked - this position : (" << x << " , " << y << ") " << std::endl; 
    ((struct User*)user)->chosenColor = (((struct User*)user)->destImg).at<Vec3b>(y,x); 
    std::cout<<"color here : "<< ((struct User*)user)->chosenColor << std::endl; 
    ((struct User*)user)->chosenX = x;
    ((struct User*)user)->chosenY = y;
    ((struct User*)user)->colorPicked = true;
  }
  return;
}

void replaceBackground(Mat clusteredImg, Mat src, Vec3b backgroundColor, Vec3b newColor, String imgName) {
    
  Mat new_image = clusteredImg;

  //remove backgroundColor
  int leftX = src.rows-1;
  for( int y = 0; y < src.rows; y++ ) {
    //starting from left side
    for( int x = 0; x < src.cols; x++ ) { 
      if (areEqual(new_image.at<Vec3b>(y,x), backgroundColor)) {
        new_image.at<Vec3b>(y,x)[0] = newColor[0];
        new_image.at<Vec3b>(y,x)[1] = newColor[1];
        new_image.at<Vec3b>(y,x)[2] = newColor[2];
      } else {
        leftX = x;
        break;
      }
    }
    //not background
    //check from other side of row now
    //starting from right side 
    int difference = 0;
    for (int z = src.cols-1; z >= leftX; z-- ) {
      if (areEqual(new_image.at<Vec3b>(y,z), backgroundColor)) {
        new_image.at<Vec3b>(y,z)[0] = newColor[0];
        new_image.at<Vec3b>(y,z)[1] = newColor[1];
        new_image.at<Vec3b>(y,z)[2] = newColor[2];
      } else {
        //found other side of object 
        difference = z - leftX;
        break;
      }
    }
    //fill in between the difference w/ src image 
    // for (int i = leftX; i < leftX+difference; i++ ) {
    //   new_image.at<Vec3b>(y,i) = src.at<Vec3b>(y,i);
    // }
  }

  //resize image
  cv::Size newSize;
  int new_width = std::min(600, src.size().width);
  newSize.width = new_width;
  newSize.height = new_width * src.size().height / src.size().width;

  resize(new_image, new_image, newSize);

  User* u = new User();
  u->destImg = new_image;

  namedWindow(imgName, 1);
  setMouseCallback(imgName, CallBackFunction2, u);

  imshow(imgName, new_image );
}


void myKmeans(User* u) {
  Vec3b newColor = u->chosenColor;

  Mat src = u->destImg;
  Mat samples(src.rows * src.cols, 3, CV_32F);
  for( int y = 0; y < src.rows; y++ )
    for( int x = 0; x < src.cols; x++ )
      for( int z = 0; z < 3; z++)
        samples.at<float>(y + x*src.rows, z) = src.at<Vec3b>(y,x)[z];

  int clusters = 5;
  Mat labels;
  int attempts = 5;
  Mat centers;
  kmeans(samples, clusters, labels, TermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 10000, 0.0001), attempts, KMEANS_PP_CENTERS, centers );
  
  Mat new_image( src.size(), src.type());

  for( int y = 0; y < src.rows; y++ ) {
    for( int x = 0; x < src.cols; x++ )
    { 
      int cluster_idx = labels.at<int>(y + x*src.rows,0);
      new_image.at<Vec3b>(y,x)[0] = centers.at<float>(cluster_idx, 0);
      new_image.at<Vec3b>(y,x)[1] = centers.at<float>(cluster_idx, 1);
      new_image.at<Vec3b>(y,x)[2] = centers.at<float>(cluster_idx, 2);
    }
  }

  //determine background color(s) and remove 
  Vec3b colorTopLeft = new_image.at<Vec3b>(0,0);
  Vec3b colorTopRight = new_image.at<Vec3b>(0, src.cols-1);
  Vec3b colorBottomLeft = new_image.at<Vec3b>(src.rows-1, 0);
  Vec3b colorBottomRight = new_image.at<Vec3b>(src.rows-1, src.cols-1);

  Vec3b backgroundColor = findMaxCommon(colorTopLeft, colorTopRight, colorBottomLeft, colorBottomRight);

  std::cout << "top:" << colorTopLeft << " " << colorTopRight << std::endl;
  std::cout << "bottom:" << colorBottomLeft << " " << colorBottomRight << std::endl;
  std::cout << "determined background-color: " << backgroundColor << std::endl;

  replaceBackground(new_image, src, backgroundColor, newColor, "new image");
}

void CallBackFunction(int event, int x, int y, int s, void* user) {
  
  if (event == EVENT_LBUTTONDOWN) {
    std::cout<<"mouse clicked - position : (" << x << " , " << y << ") " << std::endl; 
    ((struct User*)user)->chosenColor = (((struct User*)user)->skinImg).at<Vec3b>(y,x); 
    ((struct User*)user)->chosenX = x;
    ((struct User*)user)->chosenY = y;
    ((struct User*)user)->colorPicked = true;

    myKmeans((struct User*)user);
  }
  return;
}




int main( int argc, char** argv)
{
  User* u = new User();
  u->colorPicked = false;

  Mat destImg = imread( argv[1], 1 );
  Mat skinImg = imread (argv[2], 1);
  u->skinImg = skinImg; 
  u->destImg = destImg;

  namedWindow("pick skincolor", 0);
  setMouseCallback("pick skincolor", CallBackFunction, u);
  imshow("pick skincolor", skinImg);

  // maybe perform gaussian blur on the outline of the foreground? 
  // 1. find outline
  // 2. gaussian blur 
  // 3. what about the pockets? 
  // 
  // issue with custom color picking: different lighting in personal photos - hard to determine skin tone 
  // have presets? 

  //FINDING LOOPS:
  // fill in background w/ replacement color by doing BFS from corner that is the determined background color 
  // while doing BFS, put pixel coords that are not background color into a list. (non-background pixels list)
  // 
  // then iterate through all un-replaced/non-background pixels, and for each of these, perform BFS to see if the clump of background color pixels 
  // are larger than, say, 81 square pixels (9x9pi). while doing this BFS, add each to a temporary list of coords. 
  // if clump is large enough, remove all coords in temp list from the list of non-background pixels. Fill non-background pixels with
  // pixels from src image, and all clumps of bakground in the foreground w/ the chosen background color


  waitKey( 0 );
}





