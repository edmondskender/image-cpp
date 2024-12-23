//
// Created by edmond on 20.12.24.
//

#pragma once
#include <png++/png.hpp>

struct pixel {
    float r, g, b;

    pixel();
    pixel(float r, float g, float b);

    pixel& operator=(const png::rgb_pixel& other);

    pixel& operator+=(const pixel& other);
    pixel& operator/=(float d);
};