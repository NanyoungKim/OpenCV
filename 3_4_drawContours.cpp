

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


	namedWindow("show1", 0);
	namedWindow("threshold", 0);
	namedWindow("contours", 0);

	Mat img;
	img = imread("ss.jpg");

	cvtColor(img, img, CV_RGB2GRAY);	//rbg2gray�� �÷� ������

	imshow("show1", img);

	
	threshold(img, img, 128, 255, CV_THRESH_BINARY);	//������ 128�ȼ� ���� ũ�� 255��, �ƴϸ� 0���� �ٲ�
	imshow("threshold", img);//����ȭ �� ��� �Ѹ��� 
	//����ȭ�� �ؾ� findContours() �� �� ����

	
	Mat dst = Mat::zeros(img.rows, img.cols, CV_8UC3);	//�̹��� �÷��� ����

	vector< vector< Point> > contours;
	vector< Vec4i> hierarchy;


	//�̹������� �ܰ����� ���� ������ contours ������ �ִ´�.
	findContours(img.clone(), contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
				//���纻 �� �ְ� ������ img�� ������ ������ �ٲ����


	//ex 1)
	//drawContours(dst, contours, -1, CV_RGB(255, 0, 0), 1, 8, hierarchy); //-1�� �ܰ��� ��ü�� �׷���, �β�1, Ÿ����8, ��������
	
	
	
	// iterate through all the top-level contours,
	// draw each connected component with its own random color
	//ex 2) : ������� ���� �ٸ��� �����ϱ� -> for�� ���
	/*int idx = 0;
	for (; idx >= 0; idx = hierarchy[idx][0])			//������������ �ڽ��� �ڽ� ���� idx ������ �ݺ��ؼ� ��
	{
		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		//drawContours(dst, contours, idx, color, FILLED, 8, hierarchy);
		drawContours(dst, contours, idx, color, 1, 8, hierarchy);
	}
	
	
	
	//ex3: drawContours() ���� �ʰ� �׸���
	for (int i = 0; i < contours.size(); ++i)
	{
		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		for (int j = 0; j < contours[i].size() - 1; ++j)
		{
			line(dst, contours[i][j], contours[i][j + 1], color, 1);
		}
		line(dst, contours[i][0], contours[i][contours[i].size() - 1], color, 1);

	}
	*/
	
	
	//ex4 : ���� ���� ���� �׸���
	for (int i = 0; i < contours.size(); ++i)
	{

		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		//drawContours(dst, contours, idx, color, FILLED, 8, hierarchy);
		drawContours(dst, contours, i, color, 1, 8, hierarchy);
	}


	//imshow("show3", img);
	imshow("contours", dst);




	

	waitKey(0);

	return 0;
}