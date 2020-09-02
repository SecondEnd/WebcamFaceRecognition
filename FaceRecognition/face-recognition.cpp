#include <iostream>
#include <stdlib.h>
#include <opencv2\opencv.hpp>
#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

int main() {

	VideoCapture cap;

	if (!cap.open(0)) {
		return 0;
	}

	for (;;) {
		Mat frame;
		cap >> frame;
		if (frame.empty()) break;

		CascadeClassifier faceRecognition;
		if (!faceRecognition.load("C:\\Programming\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml")) {
			cout << "\nThere was a problem reading a file";

		}
		

		vector<Rect> faces;
		faceRecognition.detectMultiScale(frame, faces);

		for (int i = 0; i < faces.size(); i++) {
			Point point1(faces[i].x, faces[i].y);
			Point point2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width));
			rectangle(frame, point1, point2, Scalar(255, 0, 0), 1, 8, 0);
		}

		imshow("This is you", frame);

		if (waitKey(10) == 27) break;
	}


	return 0;
}