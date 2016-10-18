#include "imagepoint.h"

ImagePoint::ImagePoint()
{

}

ImagePoint::ImagePoint(int x, int y, std::string p, int i){
    X = x;
    Y = y;
    path = p;
    index = i;
}

ImagePoint& ImagePoint::operator=(ImagePoint& LO){
    X = LO.X;
    Y = LO.Y;
    path = LO.path;
}

std::string ImagePoint::display(){
    return "Point " + std::to_string(index) + "- X:"+ std::to_string(X) + ",Y:" + std::to_string(Y) + ";";

}

int ImagePoint::y(){
    return Y;
}

void ImagePoint::setIndex(int i){
    index = i;
}
