#ifndef IMAGEPOINT_H
#define IMAGEPOINT_H
#include <iostream>
#include <string>



class ImagePoint
{
    int X;
    int Y;
    std::string path;
    int index;
public:
    ImagePoint();
    ImagePoint(int x, int y, std::string p, int i);
    ImagePoint& operator=(ImagePoint& LO);
    std::string display();
    int y();
    void setIndex(int i);

};

#endif // IMAGEPOINT_H
