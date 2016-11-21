#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
using namespace cv;


class MyGraph {

	int v; //num verts
	vector< list< int > > adj;  //ptr to array containing adj lists 
	Mat destImg;
	Mat srcImg;
	Vec3b backgroundColor;
	Vec3b newColor;

	public:
		MyGraph (Mat src_image, Mat clustered_img, Vec3b backgroundColor, Vec3b newColor); //constructor; v=num verts
		void addEdge(int v, int w); //adds edge to graph
		Mat BFS(int s); //returns list of reachable verts from this start vert, s
		Mat BFS_ReplaceBackground();
};