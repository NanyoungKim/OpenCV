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


int main()
{
	Mat img(500, 500, CV_8UC3);
	img.setTo(255);


	///////////////////////////////////////////////////
	//line example
	cv::Point pt(300, 300);
	line(img, Point(10, 10), pt, CV_RGB(255, 0, 0), 2);	//10,10에서 300,300까지 선 긋는 것 / 2는 선의 굵기
	line(img, Point(300, 10), Point(30, 300), Scalar(255, 0, 0), 2);	//스칼라 색 순서는 BGR
	///////////////////////////////////////////////////


	///////////////////////////////////////////////////
	//Circle example
	circle(img, Point(250, 250), 100, CV_RGB(0, 255, 0), 3);		//중심이 250,250 / 반지름 100
	cv::Point center(400, 400);
	circle(img, center, 300, Scalar(255, 255, 0), 10);
	circle(img, Point(40, 40), 10, Scalar(255, 0, 0), -1);		//-1은 원에 색이 칠해진다
	///////////////////////////////////////////////////


	///////////////////////////////////////////////////
	//rectangle example
	rectangle(img, Rect(10, 10, 200, 200), CV_RGB(255, 0, 0), 2);	//10,10에서 시작, width = 200, height = 200
	rectangle(img, Rect(Point(40, 40), Point(400, 400)), Scalar(255, 0, 0), 10);
	///////////////////////////////////////////////////


	/////////////////////////////////////////////////// 
	//ellipse example 1
	ellipse(img, Point(100, 100), Size(100, 50), 0, 0, 360, CV_RGB(255, 0, 0));		//장축 100, 단축 50 / 360도이므로 타원 전체를 그림
	ellipse(img, Point(100, 100), Size(100, 50), 30, 0, 360, CV_RGB(0, 255, 0));	//30도 기울어짐
	ellipse(img, Point(100, 100), Size(100, 50), 60, 0, 360, CV_RGB(0, 0, 255));	//60도 기울어짐

	ellipse(img, Point(300, 300), Size(100, 50), 0, 0, 180, CV_RGB(255, 0, 0));
	ellipse(img, Point(300, 300), Size(100, 50), 30, 0, 270, CV_RGB(0, 255, 0));
	ellipse(img, Point(300, 300), Size(100, 50), 60, 0, 360, CV_RGB(0, 0, 255));
	
	///////////////////////////////////////////////////

	/////////////////////////////////////////////////// 
	//ellipse example 2
	//사각형을 회전시키는 rotatedRect
	RotatedRect rRect = RotatedRect(Point2f(300, 300), Size2f(300, 100), 30);	//사각형 중심 = (300,300)  , 가로 = 300, 세로 = 100 , 30도회전
	ellipse(img, rRect, CV_RGB(255, 0, 0));			//위에서 만든 사각형에 fit 되는 타원이 그려진다.

	//draw rect and inside rect in RotatedRect
	Point2f vertices[4];
	rRect.points(vertices);
	for (int i = 0; i < 4; i++)
		line(img, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0));

	Rect brect = rRect.boundingRect();
	rectangle(img, brect, Scalar(255, 0, 0));
	///////////////////////////////////////////////////


	

	imshow("show0", img);
	waitKey(0);

	return 0;
}