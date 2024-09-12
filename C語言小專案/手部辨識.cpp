#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    // 開啟攝像頭
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        cout << "Error: Cannot open camera" << endl;
        return -1;
    }

    // 創建一個窗口
    namedWindow("Hand Gesture Recognition", WINDOW_AUTOSIZE);

    // 設置捕獲區域的大小
    Rect region_of_interest(300, 100, 300, 300);

    while (true) {
        Mat frame;
        cap >> frame;

        // 檢查視訊是否還在運行
        if (frame.empty()) {
            cout << "Error: Cannot read frame" << endl;
            break;
        }

        // 顯示原始視訊
        imshow("Hand Gesture Recognition", frame);

        // 提取捕獲區域
        Mat roi = frame(region_of_interest);

        // 顯示捕獲區域
        imshow("ROI", roi);

        // 等待按鍵輸入
        char key = waitKey(1);
        if (key == 27) // ESC 鍵退出
            break;
    }

    // 釋放資源
    cap.release();
    destroyAllWindows();

    return 0;
}
