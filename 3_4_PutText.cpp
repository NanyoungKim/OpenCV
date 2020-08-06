

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

	Mat img;
	img = imread("ss.jpg");
	
	//이미지에 텍스트 넣기
	///////////////////////////////////////////////////
	//textout example 1
	char TestStr[100];
	sprintf_s(TestStr, "total time : %lf sec", 0.001);
	putText(img, TestStr, Point(10, 250), CV_FONT_NORMAL, 1, Scalar(0, 0, 0), 1, 1); //OutImg is Mat class;
	//문자열 시작위치(10,250), 폰트 종류, 글자 크기, 글자 색, 두께, 폰트 타입(라인, 점선,,,등)
	///////////////////////////////////////////////////
	

	//PutText 두번째 방법(참고) -> Mat 클래스 쓰기 전 IplImage 클래스 썼었음. 
	/*
	///////////////////////////////////////////////////
	//textout example 1
	char TestStr[100];
	sprintf_s(TestStr, "total time : %lf sec", 0.001);
	putText(img, TestStr, Point(10, 250), CV_FONT_NORMAL, 1, Scalar(0, 0, 0), 1, 1); //OutImg is Mat class;
	///////////////////////////////////////////////////
	*/



	imshow("show0", img);
	waitKey(0);

	return 0;
}
