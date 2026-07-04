#include "ImageLoader.hpp"
#include <iostream>

int main()
{
    std::cout << "Image Loader Test" << std::endl;

    ImageLoader loader;
    bool loaded = loader.load("images/cat.jpg", ColorMode::GRAYSCALE);
    if (!loaded)
    {
        std::cerr << "Failed to load image." << std::endl;
        return 1;
    }
    loader.imageInfo();
    loader.printPixel(10, 10);
    loader.printMatrixPreview();

    return 0;
}
