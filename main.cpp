#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

int main(int argc, char **argv)
{
    int SquareX = 7;
    int SquareY = 10;
    int BlockSize = 100;
    uchar LowColor = 0;

    if(argc > 2)
    {
        SquareX = atoi(argv[1]);
        SquareY = atoi(argv[2]);
    }
    if(argc > 3)
    {
        BlockSize = atoi(argv[3]);
    }
    if(argc > 4)
    {
        LowColor = static_cast<uchar>(atoi(argv[4]));
    }

    cv::Mat Image(cv::Size(SquareX * BlockSize, SquareY * BlockSize), CV_8UC1, cv::Scalar::all(0));
    for(int Y = 0; Y < SquareY * BlockSize; Y++)
    {
        uchar* PixelPtr = Image.ptr<uchar>(Y);
        for(int X = 0; X < SquareX * BlockSize; X++)
        {
            bool bFillWhite = ((X/BlockSize + Y/BlockSize) % 2 == 0);
            if(bFillWhite)
            {
                PixelPtr[X] = 255;
            }
            else
            {
                PixelPtr[X] = LowColor;
            }
        }
    }
    std::string Title = "Image_";
    Title += std::to_string(Image.rows);
    Title += "x" + std::to_string(Image.cols);

    cv::imshow(Title, Image);
    cv::waitKey(0);

    cv::imwrite(Title + ".png", Image);

    return 0;
}
