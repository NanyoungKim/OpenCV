

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

	cvtColor(img, img, CV_RGB2GRAY);	//rbg2gray로 컬러 컨버터

	imshow("show1", img);

	
	threshold(img, img, 128, 255, CV_THRESH_BINARY);	//영상값을 128픽셀 보다 크면 255로, 아니면 0으로 바꿈
	imshow("threshold", img);//이진화 된 결과 뿌리기 
	//이진화를 해야 findContours() 쓸 수 있음

	
	Mat dst = Mat::zeros(img.rows, img.cols, CV_8UC3);	//이번엔 컬러로 만듦

	vector< vector< Point> > contours;
	vector< Vec4i> hierarchy;


	//이미지에서 외곽선에 대한 정보를 contours 변수에 넣는다.
	findContours(img.clone(), contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
				//복사본 안 넣고 원본값 img를 넣으면 원본값 바꿔버림


	//ex 1)
	//drawContours(dst, contours, -1, CV_RGB(255, 0, 0), 1, 8, hierarchy); //-1은 외곽선 전체를 그려라, 두께1, 타입은8, 계층구조
	
	
	
	// iterate through all the top-level contours,
	// draw each connected component with its own random color
	//ex 2) : 컨투어마다 색상 다르게 지정하기 -> for문 사용
	/*int idx = 0;
	for (; idx >= 0; idx = hierarchy[idx][0])			//계층구조에서 자신의 자식 값이 idx 값으로 반복해서 들어감
	{
		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		//drawContours(dst, contours, idx, color, FILLED, 8, hierarchy);
		drawContours(dst, contours, idx, color, 1, 8, hierarchy);
	}
	
	
	
	//ex3: drawContours() 쓰지 않고 그리기
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
	
	
	//ex4 : 계층 구조 없이 그리기
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