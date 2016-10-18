#ifndef VIDEO_H
#define VIDEO_H
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
#include "frame.h"
#include <sys/types.h>
#include <dirent.h>


class Video
{
public:
    Video();
    Video(std::string path);
    Video(std::string path, std::string outputDir, std::string maxPoints);
};

#endif // VIDEO_H
