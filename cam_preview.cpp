#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    int CAM_ID = 0;
    Mat frame1;
    //open the CAM
    VideoCapture cap(CAM_ID); //카메라 생성

    //Check that the camera is opened
    if(!cap.isOpened()){ //카메라 열렸는지 확인
        printf("Can't open the CAM(%d)\n",CAM_ID);
        return -1;
    }

    // get the CAMERA resolution
    //이미지 해상도 얻기
    double width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    printf("size = [%f, %f]\n",width, height);

    // create window & change the window size
    //윈도우 생성 및 사이즈 변경
    namedWindow("CAM_Window", 0);
    resizeWindow("CAM_Window", 1280, 720);

    while(1){
        //read the camera image
        //카메라에서 이미지 얻어오기
        cap >> frame1;

        //show the camera image
        //얻어온 이미지를 윈도우에 표시
        imshow("CAM_Window", frame1);

        //wait keyboard input until 10ms
        //10ms 동안 키입력 대기
        if(waitKey(10) >= 0) break;
    }

    //close window
    //윈도우 종료
    destroyWindow("CAM_Window");
    return 0;
}
