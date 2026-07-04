// PixelPrinter.hpp
#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

class PixelPrinter
{
public:
    virtual ~PixelPrinter() = default;
    virtual void print(const cv::Mat& image, int row, int col) const = 0;
};

class GrayScalePixelPrinter : public PixelPrinter
{
public:
    void print(const cv::Mat& image, int row, int col) const override
    {
        uchar pixel = image.at<uchar>(row, col);
        std::cout << static_cast<int>(pixel) << " ";
    }
};

class RGBPixelPrinter : public PixelPrinter
{
public:
    void print(const cv::Mat& image, int row, int col) const override
    {
        cv::Vec3b pixel = image.at<cv::Vec3b>(row, col);
        std::cout << "(" << static_cast<int>(pixel[0]) << " " << static_cast<int>(pixel[1]) << " "
                  << static_cast<int>(pixel[2]) << ")" << " ";
    }
};

class RGBAPixelPrinter : public PixelPrinter
{
public:
    void print(const cv::Mat& image, int row, int col) const override
    {
        if (image.depth() != CV_8U)
        {
            std::cerr << "Unsupported pixel depth for RGBA printing." << std::endl;
            return;
        }

        cv::Vec4b pixel = image.at<cv::Vec4b>(row, col);
        std::cout << "(" << static_cast<int>(pixel[0]) << " " << static_cast<int>(pixel[1]) << " "
                  << static_cast<int>(pixel[2]) << " " << static_cast<int>(pixel[3]) << ")" << " ";
    }
};
