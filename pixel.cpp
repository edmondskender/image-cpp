//
// Created by edmond on 20.12.24.
//
#include <iostream>
#include "pixel.h"

pixel::pixel() : r(0.0), g(0.0), b(0.0) {};

pixel::pixel(float r, float g, float b) : r(r), g(g), b(b) {};

pixel& pixel::operator+=(const pixel &other) {
    r += other.r;
    g += other.g;
    b += other.b;
    return *this;
}

pixel& pixel::operator/=(float d) {
    r /= d;
    g /= d;
    b /= d;
    return *this;
}

pixel& pixel::operator=(const png::rgb_pixel& other) {
    r = other.red;
    g = other.green;
    b = other.blue;
    return *this;
}




