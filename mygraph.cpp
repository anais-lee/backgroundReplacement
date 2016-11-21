#include "mygraph.h"



struct VisitedArray {
  int size;
  bool *array;
};

//CONSTRUCTOR: creates graph (w/ edges bw all adjacent pixels) from image matrix
MyGraph::MyGraph(Mat src_image, Mat clustered_img, Vec3b backgroundColor, Vec3b newColor) {
	this->v = clustered_img.rows * clustered_img.cols; //set num verts 
	this->destImg = clustered_img;
	this->srcImg = src_image;
	this->backgroundColor = backgroundColor;
	this->newColor = newColor;
	list<int> newlist;

	adj.push_back(newlist);

	adj.push_back(newlist);
	// std::cout << "v:" << this->v <<std::endl;
	for (int i = 0; i < this->v; i++) {
		adj.push_back(newlist);
	}

	int maxVertIdx = (destImg.rows-1)*(destImg.cols-1); 

	//fill in adj matrix
	for( int y = 0; y < destImg.rows; y++ ) {
	    //starting from left side
	    for( int x = 0; x < destImg.cols; x++ ) { 
	    	//add all surrounding pixels 
	    	int currVert = y*destImg.cols + x; 

	    	int leftTop = (y-1)*destImg.cols + (x-1); //x-1, y-1
	    	int middleTop = (y-1)*destImg.cols + x; //x, y-1
			int rightTop = (y-1)*destImg.cols + (x+1); //x+1, y-1
			int leftCenter = y*destImg.cols + (x-1); //x-1, y
			int rightCenter = y*destImg.cols + (x+1); //x+1, y
			int leftBottom = (y+1)*destImg.cols + (x-1); //x-1, y+1
			int middleBottom = (y+1)*destImg.cols + x; //x, y+1
			int rightBottom = (y+1)*destImg.cols + x+1; //x+1, y+1

	    	if (x == 0 && y == 0) { //left top corner
	    		adj[currVert].push_back(rightCenter);
	    		adj[currVert].push_back(rightBottom);
	    		adj[currVert].push_back(middleBottom);
	    	} else if (x == destImg.cols-1 && y == 0) { //right top corner
	    		adj[currVert].push_back(leftCenter);
	    		adj[currVert].push_back(leftBottom);
	    		adj[currVert].push_back(middleBottom);
	    	} else if (x == destImg.cols-1 && y == destImg.rows-1) { //right bottom corner
	    		adj[currVert].push_back(middleTop);
	    		adj[currVert].push_back(leftTop);
	    		adj[currVert].push_back(leftCenter);
	    	} else if (x == 0 && y == destImg.rows-1) { //left bottom corner
	    		adj[currVert].push_back(rightCenter);
	    		adj[currVert].push_back(rightBottom);
	    		adj[currVert].push_back(middleBottom);
	    	} else if (x == 0) { //flush to left
	    		adj[currVert].push_back(middleTop);
	    		adj[currVert].push_back(rightTop);
	    		adj[currVert].push_back(rightCenter);
	    		adj[currVert].push_back(rightBottom);
	    		adj[currVert].push_back(middleBottom);
	    	} else if (y == 0) { //flush to top
	    		adj[currVert].push_back(leftCenter);
	    		adj[currVert].push_back(leftBottom);
	    		adj[currVert].push_back(middleBottom);
	    		adj[currVert].push_back(rightBottom);
	    		adj[currVert].push_back(rightCenter);
	    	} else if (x == destImg.cols-1) { //flush to right
				adj[currVert].push_back(middleTop);
	    		adj[currVert].push_back(leftTop);
	    		adj[currVert].push_back(leftCenter);
	    		adj[currVert].push_back(leftBottom);
	    		adj[currVert].push_back(middleBottom);
	    	} else if (y == destImg.rows-1) { //flush to bottom
	    		adj[currVert].push_back(leftCenter);
	    		adj[currVert].push_back(leftTop);
	    		adj[currVert].push_back(middleTop);
	    		adj[currVert].push_back(rightTop);
	    		adj[currVert].push_back(rightCenter);
	    	} else { //everything else
	    		adj[currVert].push_back(leftTop);
	    		adj[currVert].push_back(middleTop);
	    		adj[currVert].push_back(rightTop);
	    		adj[currVert].push_back(leftCenter);
	    		adj[currVert].push_back(rightCenter);
	    		adj[currVert].push_back(leftBottom);
	    		adj[currVert].push_back(middleBottom);
	    		adj[currVert].push_back(rightBottom);	    	
	    	}

	    }
	}

}

//checks whether the values in 2 vecs are equal
int areEqual(Vec3b vec1, Vec3b vec2) {
  return (vec1[0]==vec2[0] && vec1[1]==vec2[1] && vec1[2]==vec2[2]);
}

//returns the index of unvisited if it exists 
//returns -1 otherwise (if no unvisted vertices are left)
int containsUnvisited(VisitedArray* visited, int start) {

	std::cout<<"starting index for checking unvisited: " <<start <<std::endl;

	for (int i = 0; i < visited->size; i++) {
		if (!visited->array[i]) {
			std::cout<<"now returning vert " << i << " to check"<<std::endl;
			return i;
		}
	}
	return -1;
}

//returns the new image with background replaced
Mat MyGraph::BFS(int s) {

//approach 1
	//check 50x50 pixel blocks and see if theyre all background color. 
	//if so, then found loop. perform bfs starting from center of this block.

//another approach
	//if 2 corners equal and other 2 are equal, background is gradient. run 2x BFS starting on each side
	
	//otherwise, run BFS from any background corner. 
	//check row/col of pixels on each edge checking for background pixels. 
	//if found, run bfs starting from this. if area > threshold, fill in. (leg holes)

	list<int>::iterator i;

	VisitedArray* visited = new VisitedArray();
	visited->size = v;
	visited->array = new bool[v];
	
	for (int i = 0; i < v; i++) {
		visited->array[i] = false; //set all visited = false;
	}

	list<int> nonBackground;
	list<int> reachable;

	bool doneFirstIteration = false;
	list<int> queue;

	int areMorePixels = containsUnvisited(visited, 0); //should return 0
	int start = 1;
	int numVisited = 0;

	while (areMorePixels != -1) {
		s = areMorePixels; //for first, this should be 0
		std::cout<<"s here: " << s <<std::endl;
		
		int y = s / destImg.cols;
		int x = s % destImg.cols;

		if (!areEqual(destImg.at<Vec3b>(y,x), backgroundColor)) { //if not a background color
			nonBackground.push_back(s);
			visited->array[s] = true;
			numVisited++;
			start++;
			if (numVisited <= this->v) {
				areMorePixels = containsUnvisited(visited, start);
				continue;
			} else {
				break; //no more left
			}
			
		} else {
			reachable.push_back(s);//add start vert to list of reachable
			queue.push_back(s);
		}

		while (!queue.empty()) {
			visited->array[s] = true;
			// std::cout<<"visited->array[s]: " << visited->array[s] << std::endl;
			s = queue.front();
			// std::cout<<"just popped: " << s <<"; queue size now:" << queue.size() << std::endl;
			queue.pop_front(); //dequeue vert

			int y = s / destImg.cols;
			int x = s % destImg.cols;
			
			for (i = adj[s].begin(); i != adj[s].end(); ++i) { //iterate through neighbors

				int y = *i / destImg.cols;
				int x = *i % destImg.cols;
				// std::cout<<"neighbor" << *i <<std::endl;
				// std::cout<<"neighbor is visited already: " << visited[*i] <<std::endl;
				// std::cout<<"background color: " << backgroundColor <<std::endl;
				// std::cout<<"color at this neighbor: " << destImg.at<Vec3b>(y,x) <<std::endl;
				// std::cout<<"0's neighbor is same as backgroundcolor " << areEqual(destImg.at<Vec3b>(y,x), backgroundColor)<<std::endl;
				if (!visited->array[*i] && areEqual(destImg.at<Vec3b>(y,x), backgroundColor)) { //if not visited, mark visited & add to queue
					// std::cout<<"adding to queue now & marking as visited: " << *i << std::endl;
					visited->array[*i] = true;
					queue.push_back(*i);
					// std::cout<<"queue size:" << queue.size() << std::endl;
					reachable.push_back(*i); //add to list of reachable from this start vert

				} else if (!visited->array[*i] && !areEqual(destImg.at<Vec3b>(y,x), backgroundColor)) {
					//if not a background color, keep doing bfs and 
					visited->array[*i] = true; //visited, but DONT add to queue
					//and dont add to reachable, add to non backgrounds instead 
					nonBackground.push_back(*i);
				} 
			}

		}
		//if area reachable from this starting point is large enough, 
		//replace it all with background color
		if (reachable.size() > 1500) {
			std::cout<<"should get here twice"<<std::endl;
			list<int>::iterator z;
			for (z = reachable.begin(); z != reachable.end(); ++z) {
				//for all verts in this reachable region, replace it in the image w/ backgroud color
				int y = *z / destImg.cols;
				int x = *z % destImg.cols;
				destImg.at<Vec3b>(y,x)[0] = newColor[0];
				destImg.at<Vec3b>(y,x)[1] = newColor[1];
				destImg.at<Vec3b>(y,x)[2] = newColor[2];
			}
			reachable.clear();
		}

		//check if there are more pixels 
		//std::cout<<"next vertex to check if visited: "<<start<<std::endl;
		areMorePixels = containsUnvisited(visited, s);
		y = areMorePixels / destImg.cols;
		x = areMorePixels % destImg.cols;
		std::cout<<"this vert: " <<x << ", " << y << std::endl;
	

		// std::cout << "there are more pixels! " << (areMorePixels != -1) <<std::endl;

	}

	//after BFS's are all done, replace the nonBackground pixels with the original image pixels
	for (i = nonBackground.begin(); i != nonBackground.end(); ++i) { //iterate through neighbors
		// std::cout<<"replacing non background w/ src img pixels now"<<std::endl;
		int y = *i / destImg.cols;
		int x = *i % destImg.cols;
		destImg.at<Vec3b>(y,x)[0] = srcImg.at<Vec3b>(y,x)[0];
		destImg.at<Vec3b>(y,x)[1] = srcImg.at<Vec3b>(y,x)[1];
		destImg.at<Vec3b>(y,x)[2] = srcImg.at<Vec3b>(y,x)[2];
	}

	return destImg;
}

Mat MyGraph::BFS_ReplaceBackground() {
	std::cout << "doing background bfs's" <<std::endl;
	Mat final_image;
	//choose starting point to replace background correctly
	if (areEqual(destImg.at<Vec3b>(0,0), backgroundColor)) {
		std::cout<<"chose leftop" <<std::endl;
		final_image = BFS(0);
	} else if (areEqual(destImg.at<Vec3b>(0,destImg.cols-1), backgroundColor)) {
		std::cout<<"chose topright" <<std::endl;
		final_image = BFS(0*destImg.cols + (destImg.cols-1));
	} else if (areEqual(destImg.at<Vec3b>(destImg.rows-1,destImg.cols-1), backgroundColor)) {
		std::cout<<"chose bottomright" <<std::endl;
		final_image = BFS((destImg.rows-1)*destImg.cols + (destImg.cols-1));
	} else if (areEqual(destImg.at<Vec3b>(destImg.rows-1, 0), backgroundColor)) {
		std::cout<<"chose leftop" <<std::endl;
		final_image = BFS((destImg.rows-1)*destImg.cols + 0);
	}
	return final_image;
}



void MyGraph::addEdge(int v, int w) {
}




