#include "ImageLoader.hpp"
#include <iostream>

int main()
{
    std::cout << "Image Loader Test" << std::endl;

    ImageLoader loader;

    loader.load("images/cat.jpg", ColorMode::GRAYSCALE);
    loader.imageInfo();
    loader.printPixel(10, 10);
    loader.printMatrixPreview();

    return 0;
}
