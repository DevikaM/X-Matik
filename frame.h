#ifndef FRAME_H
#define FRAME_H

#define MAXPOINTS 6
#define PATH "/Users/DevikaMaharaj/Documents/test/"
#include <fstream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <string>
#include <QMainWindow>
#include <QObject>
#include <QMessageBox>
#include "imagepoint.h"
#include <stdio.h>

class Frame
{
    cv::Mat img;
    std::string filePath;
    int noPoint;
    std::string fileName;
    std::string file;
    ImagePoint* points;
    int maxPoints;
    std::string outputDir;

public:
    Frame();
    Frame(std::string path);
    Frame(std::string path, std::string outDir, std::string filename, int maxPoints);
    void onMouse(int event, int x, int y, int flags, void* userdata);
    char display();
    void run();
    void saveFile();
    void deletePoint();
    static void onMouseWrapper(int event, int x, int y, int flags, void *param);
};

#endif // FRAME_H
