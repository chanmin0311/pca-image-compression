#include "ImageLoader.hpp"

bool ImageLoader::isValidCoord(int row, int col) const
{
    return row >= 0 && row < image_.rows && col >= 0 && col < image_.cols;
}

bool ImageLoader::load(const std::string& imagePath, ColorMode mode)
{
    mode_ = mode;
    int cvMode = cv::IMREAD_COLOR;
    switch (mode_)
    {
        case ColorMode::GRAYSCALE:
            cvMode = cv::IMREAD_GRAYSCALE;
            printer_ = std::unique_ptr<PixelPrinter>(std::make_unique<GrayScalePixelPrinter>());
            break;
        case ColorMode::RGB:
            cvMode = cv::IMREAD_COLOR;
            printer_ = std::unique_ptr<PixelPrinter>(std::make_unique<RGBPixelPrinter>());
            break;
        case ColorMode::RGBA:
            cvMode = cv::IMREAD_UNCHANGED;
            printer_ = std::unique_ptr<PixelPrinter>(std::make_unique<RGBAPixelPrinter>());
            break;
    }
    image_ = cv::imread(imagePath, cvMode);
    return !image_.empty();
}

void ImageLoader::imageInfo() const
{
    std::cout << "Width: " << image_.cols << "\nheight: " << image_.rows
              << "\nChannels: " << image_.channels()
              << "\nType: " << cv::typeToString(image_.type()) << std::endl;
}

void ImageLoader::printPixel(int row, int col) const
{
    if (!isValidCoord(row, col))
    {
        std::cerr << "Pixel coordinates out of bounds." << std::endl;
        return;
    }
    printer_->print(image_, row, col);
    std::cout << std::endl;
}

void ImageLoader::printMatrixPreview() const
{
    std::cout << "Matrix Preview (first 10 rows and columns)" << std::endl;
    for (int i = 0; i < std::min(10, image_.rows); ++i)
    {
        for (int j = 0; j < std::min(10, image_.cols); ++j)
        {
            printer_->print(image_, i, j);
        }
        std::cout << std::endl;
    }
}
