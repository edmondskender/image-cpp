//
// Created by edmond on 20.12.24.
//
#include "image.h"
#include "pixel.h"
#include <png++/png.hpp>


image::image(int w, int h) : w(w), h(h), data(new pixel[w*h]) {};

image::image(const std::string& filename) {
    png::image<png::rgb_pixel> image(filename);
    w = image.get_width();
    h = image.get_height();
    data = new pixel[w * h];
    for(int y = 0; y < h; ++y)
        for(int x = 0; x < w; ++x) {
            data[y * w + x] = image.get_pixel(x,y);
        }
}

image::~image() {
    delete[] data;
}

image::image(const image &other) : w(other.w), h(other.h) {
    data = new pixel[w * h];
    for(int y = 0; y < h; ++y) {
        for(int x = 0; x < w; ++x) {
            data[y * w + x] = other.data[y * w + x];
        }
    }
}

image& image::operator=(const image &other) {
    if(this != &other) {
        w = other.w;
        h = other.h;

        delete[] data;
        data = new pixel[w * h];

        for(int y = 0; y < h; ++y)
            for(int x = 0; x < w; ++x)
                data[y * w + x] = other.data[y * w + x];
    }
    return *this;
}

image::image(image &&other) : w(other.w), h(other.h), data(other.data) {
    other.data = nullptr;
    other.w = other.h = 0;
}

image &image::operator=(image &&other) {
    if(this != &other) {
        w = other.w;
        h = other.h;

        delete[] data;
        data = other.data;

        other.data = nullptr;
        other.w = other.h = 0;
    }
    return *this;
}

int image::width() const {
    return w;
}

int image::height() const {
    return h;
}

pixel& image::operator()(int x, int y) {
    return data[y * w + x];
}

const pixel& image::operator()(int x, int y) const {
    return data[y * w + x];
}

void image::save() {
    png::image<png::rgb_pixel> image(w,h);
    for(int y = 0; y < h; ++y)
        for(int x = 0; x < w; ++x) {
            pixel pixel = data[y * w + x];
            png::rgb_pixel pix(pixel.r, pixel.g, pixel.b);
            image.set_pixel(x,y,pix);
        }
    image.write("output.png");
    std::cout << "Image saved" << std::endl;
}









