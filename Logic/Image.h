//
// Created by Dominika on 06.03.2019.
//

#ifndef HIPSEGMENTER_IMAGE_H
#define HIPSEGMENTER_IMAGE_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

class Image {
public:
    Image(string filePath);
    ~Image();

private:
    Mat image;

};


#endif //HIPSEGMENTER_IMAGE_H
