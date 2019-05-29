//
// Created by Dominika on 06.03.2019.
//

#include "Image.h"

Image::Image(string filePath) {
    image = imread(filePath, CV_LOAD_IMAGE_COLOR);
}
