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
	namedWindow("img", 0);

	imshow("img", img);
	waitKey(0);


	//imwrite("new_img.jpg", img);
	//imwrite("new_img.png", img);
	//imwrite("new_img.bmp", img);
	//imwrite("new_img.tif", img);

	Mat img2;
	Sobel(img, img2, CV_8U, 1, 0);
	//imwrite("sobel_img.png", img2);

	vector< Mat > rgbMat(3);
	split(img, rgbMat);
	imwrite("r.jpg", rgbMat[2]);
	imwrite("g.jpg", rgbMat[1]);
	imwrite("b.jpg", rgbMat[0]);






	//video
	VideoCapture capture(".\\rhinos.avi");
	Mat frame;

	int askFileTypeBox = 0;		//-1로 하면 코텍 박스 띄움. 
	int Color = 1;
	Size S = Size((int)capture.get(CV_CAP_PROP_FRAME_WIDTH), (int)capture.get(CV_CAP_PROP_FRAME_HEIGHT));	//원본과 가로 세로 같게
	

	VideoWriter outVideo;								//원본과 같게					
	outVideo.open(".\\outVideo.avi", askFileTypeBox, capture.get(CV_CAP_PROP_FPS), S, Color);

	if (!capture.isOpened()){
		printf("AVI file can not open.\n");
		return 0;
	}


	namedWindow("w");
	while (1){
		capture >> frame;
		if (frame.empty())
			break;

		outVideo << frame;			// = outVideo.write(frame)
		imshow("w", frame);
		if (waitKey(10) > 0)
			break;
	}



	destroyAllWindows();
	return 0;

}