

#include <iostream>
#include <opencv2\opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib, "opencv_core2413d.lib")
#pragma comment(lib, "opencv_imgproc2413d.lib")
#pragma comment(lib, "opencv_highgui2413d.lib")
//#pragma comment(lib, "opencv_video2413d.lib")
#else
#pragma comment(lib, "opencv_core2413.lib")
#pragma comment(lib, "opencv_imgproc2413.lib")
#pragma comment(lib, "opencv_highgui2413.lib")
//#pragma comment(lib, "opencv_video2413.lib")#endif
#endif

using namespace std;
using namespace cv;

int main(int, char){

	Mat img(500, 500, CV_8UC3);
	img.setTo(255);

	/*
	///////////////////////////////////////////////////
	//polylines example 1
	vector< Point> contour;
	contour.push_back(Point(50, 50));
	contour.push_back(Point(300, 50));
	contour.push_back(Point(350, 200));
	contour.push_back(Point(300, 150));
	contour.push_back(Point(150, 350));
	contour.push_back(Point(100, 100));

	const Point *pts = (const cv::Point*) Mat(contour).data;
	int npts = Mat(contour).rows;

	std::cout << "Number of polygon vertices: " << npts << std::endl;
	// draw the polygon
	polylines(img, &pts, &npts, 1, false, Scalar(0, 255, 0), 3);		//npts는 나타낼 점의 개수, 1은 폴리라인 한 개 그린다는 것 


	//polylines example 2
	contour.clear();
	contour.push_back(Point(400, 400));
	contour.push_back(Point(250, 250));
	contour.push_back(Point(50, 300));

	pts = (const cv::Point*) Mat(contour).data;
	npts = Mat(contour).rows;
	polylines(img, &pts, &npts, 1, true, Scalar(255, 0, 0));		//true는 끝점과 시작점 연결해서 닫히게 만듦
	///////////////////////////////////////////////////
	
	*/




	//polylines example 3
	vector< Point> contour;
	contour.push_back(Point(50, 50));
	contour.push_back(Point(300, 50));
	contour.push_back(Point(350, 200));
	contour.push_back(Point(300, 150));
	contour.push_back(Point(150, 350));
	contour.push_back(Point(100, 100));

	const Point *pts = (const cv::Point*) Mat(contour).data;
	int npts = Mat(contour).rows;

	std::cout << "Number of polygon vertices: " << npts << std::endl;
	// draw the polygon
	//polylines(img, &pts, &npts, 1, false, Scalar(0, 255, 0), 3);		//npts는 나타낼 점의 개수, 1은 폴리라인 한 개 그린다는 것 

	//polylines example 4
	vector< Point> contour2;
	contour2.push_back(Point(230, 220));
	contour2.push_back(Point(10, 50));
	contour2.push_back(Point(50, 200));
	contour2.push_back(Point(200, 150));

	const Point *pts2 = (const cv::Point*) Mat(contour2).data;
	int npts2 = Mat(contour2).rows;
	const Point *n_pts[2] = { pts, pts2 };
	int n_npts[2] = { npts, npts2 };

	//두개의 폴리라인을 한번에 그림
	polylines(img, n_pts, n_npts, 2, false, Scalar(0, 255, 0));		//true는 끝점과 시작점 연결해서 닫히게 만듦
	///////////////////////////////////////////////////
	imshow("show2", img);

	for (int i = 0; i < contour.size()-1; ++i){
		line(img, contour[i], contour[i + 1], CV_RGB(255, 0, 0), 2);
	}
	line(img, contour[contour.size() - 2], contour[contour.size() - 1], CV_RGB(255, 0, 0), 2);


	imshow("show3", img);




	/*색상이 채워진 다각형
	///////////////////////////////////////////////////
	//fillConvexPoly example 1  
	cv::Point ptss[4];
	ptss[0] = cv::Point(100, 100);
	ptss[1] = cv::Point(150, 200);
	ptss[2] = cv::Point(300, 300);
	ptss[3] = cv::Point(400, 100);

	cv::fillConvexPoly(img, ptss, 4, cv::Scalar(0, 0, 200));
	///////////////////////////////////////////////////
	*/

	

	

	imshow("show0", img);
	waitKey(0);

	return 0;
}
