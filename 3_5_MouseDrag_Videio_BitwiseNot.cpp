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
using namespace std;
using namespace cv;

bool selectObject = false;
Rect selection;
Point origin;
int trackObject = 0;
Mat image;


static void onMouse(int event, int x, int y, int, void*)
{
	if (selectObject)
	{
		selection.x = MIN(x, origin.x);
		selection.y = MIN(y, origin.y);
		selection.width = std::abs(x - origin.x);
		selection.height = std::abs(y - origin.y);

		selection &= Rect(0, 0, image.cols, image.rows);
	}

	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:		//마우스 왼쪽 버튼 누르면 선택됨
		origin = Point(x, y);
		selection = Rect(x, y, 0, 0);
		selectObject = true;
		break;
	case CV_EVENT_LBUTTONUP:		//마우스 왼쪽 버튼 뗀 상태
		selectObject = false;
		if (selection.width > 0 && selection.height > 0)
			trackObject = -1;
		break;
	}
}


int main(void)
{


	VideoCapture cap(0);
	//VideoCapture cap("vtest.avi");
	Mat frame;
	namedWindow("Demo", 0);
	setMouseCallback("Demo", onMouse, 0);

	for (;;)
	{

		cap >> frame;
		if (frame.empty())
			break;

		frame.copyTo(image);


		if (selectObject && selection.width > 0 && selection.height > 0)
		{
			Mat roi(image, selection);
			bitwise_not(roi, roi);				//선택된 영역 반전시키기
			printf("%d %d %d %d\n", selection.x, selection.y, selection.width, selection.height);
		}

		imshow("Demo", image);

		if (waitKey(10) > 10)
			break;
	}

	return 0;
}
