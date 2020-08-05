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

	namedWindow("img", 0);
	namedWindow("img2", 0);

	Mat img = imread("ss.jpg");
	Mat img2;
	flip(img, img2, 1);
	//qSobel(img, img2, img.depth(), 1, 0);
	imshow("img", img); //show
	imshow("img2", img2);

	waitKey(0);	//키 입력 값을 기다리는 것. (0이라 무한대, 단위는 ms)

	destroyAllWindows();

	return 0;



}