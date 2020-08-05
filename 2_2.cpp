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

	Mat img = imread("ss.jpg");
	bitwise_not(img, img);	//원본 반전시켜서 다시 원본에 저장한 후 출력
	imshow("img", img);
	bitwise_not(img, img);

	Mat img_s = img;		//대입문 : 값 복사가 아닌 참조. img 값이 바뀌면 img_s도 바뀐다.
	imshow("img_s", img_s);		


	Mat img2 = img.clone();		//참조가 아닌 값 복사임.
	imshow("img2", img2);


	Rect r(img.cols / 4, img.rows / 4, img.cols / 4 * 2, img.rows / 4 * 2);
	cout << r << endl;


	Mat img5 = img(r).clone();	// Rect r 만큼만 img5에 복사
	imshow("img5", img5);

	Mat cimg;					//원본 복사, 원본 반전시켜도 영향x
	img.copyTo(cimg);
	imshow("cimg", cimg);

	Mat cimg2;
	img(r).copyTo(cimg2);		//Rect r 만큼만 복사하기
	imshow("cimg2", cimg2);


	Mat cimg3(Size(img.cols * 2, img.rows), img.type());	//가로 크기 두배해서 Mat 생성 
	cimg3.setTo(255);		//흰색으로 초기화
	img.copyTo(cimg3(Range::all(), Range(0, img.cols)));					//cimg3의 절반 왼쪽에는 img, 오른쪽에는 img2 복사
	img2.copyTo(cimg3(Range::all(), Range(img2.cols, img2.cols * 2)));
	imshow("cimg3", cimg3);


	Mat roi(img, r);			//원본에서 r만큼 참조한 것
	//invert
	bitwise_not(roi, roi);
	imshow("roi", roi);
	imshow("img", img);			//img 에서 r만큼 반전되어서 출력



	waitKey(0);

	return 0;

}