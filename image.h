//
// Created by edmond on 20.12.24.
//

#pragma once
#include "pixel.h"
#include <string>

class image {
    int w, h;
    pixel* data;

public:
    image(int w, int h);
    image(const std::string& filename);
    ~image();

    image(const image& other);
    image& operator=(const image& other);

    image(image&& other);
    image& operator=(image&& other);

    void save();

    int width() const;
    int height() const;

    pixel& operator()(int x, int y);
    const pixel& operator()(int x, int y) const;
};