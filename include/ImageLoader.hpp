// ImageLoader.hpp
#pragma once

#include "PixelPrinter.hpp"
#include <opencv4/opencv2/opencv.hpp>
#include <string>

enum class ColorMode
{
    GRAYSCALE,
    RGB,
    RGBA
};

class ImageLoader
{
public:
    bool load(const std::string& imagePath, ColorMode mode = ColorMode::RGB);
    void imageInfo() const;
    void printPixel(int row, int col) const;
    void printMatrixPreview() const;

private:
    cv::Mat image_;
    ColorMode mode_ = ColorMode::RGB;
    std::unique_ptr<PixelPrinter> printer_;

    bool isValidCoord(int row, int col) const;
};
