#include <iostream>
#include <png++/png.hpp>
#include "image.h"
#include "pixel.h"

using std::cout, std::endl;

image to_gray(const image& input) {
    image img(input.width(), input.height());
    for(int y = 0; y < input.height(); ++y)
        for(int x = 0; x < input.width(); ++x) {
            pixel pix = input(x,y);
            float gray = (pix.r + pix.g + pix.b) / 3.0f;
            pixel gray_pixel(gray, gray, gray);
            img(x,y) = gray_pixel;
        }
    return img;
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    try {
        std::string filename(argv[1]);
        image img_gray = to_gray(image(filename));
        img_gray.save();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        throw;
    }
    return 0;
}
