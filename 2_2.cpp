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
	bitwise_not(img, img);	//���� �������Ѽ� �ٽ� ������ ������ �� ���
	imshow("img", img);
	bitwise_not(img, img);

	Mat img_s = img;		//���Թ� : �� ���簡 �ƴ� ����. img ���� �ٲ�� img_s�� �ٲ��.
	imshow("img_s", img_s);		


	Mat img2 = img.clone();		//������ �ƴ� �� ������.
	imshow("img2", img2);


	Rect r(img.cols / 4, img.rows / 4, img.cols / 4 * 2, img.rows / 4 * 2);
	cout << r << endl;


	Mat img5 = img(r).clone();	// Rect r ��ŭ�� img5�� ����
	imshow("img5", img5);

	Mat cimg;					//���� ����, ���� �������ѵ� ����x
	img.copyTo(cimg);
	imshow("cimg", cimg);

	Mat cimg2;
	img(r).copyTo(cimg2);		//Rect r ��ŭ�� �����ϱ�
	imshow("cimg2", cimg2);


	Mat cimg3(Size(img.cols * 2, img.rows), img.type());	//���� ũ�� �ι��ؼ� Mat ���� 
	cimg3.setTo(255);		//������� �ʱ�ȭ
	img.copyTo(cimg3(Range::all(), Range(0, img.cols)));					//cimg3�� ���� ���ʿ��� img, �����ʿ��� img2 ����
	img2.copyTo(cimg3(Range::all(), Range(img2.cols, img2.cols * 2)));
	imshow("cimg3", cimg3);


	Mat roi(img, r);			//�������� r��ŭ ������ ��
	//invert
	bitwise_not(roi, roi);
	imshow("roi", roi);
	imshow("img", img);			//img ���� r��ŭ �����Ǿ ���



	waitKey(0);

	return 0;

}