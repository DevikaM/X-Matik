#include "video.h"

Video::Video(){}
Video::Video(std::string path){}
Video::Video(std::string path, std::string outputDir, std::string maxPoints){
    cv::VideoCapture cap(path);
    if(cap.isOpened()){
        //try{
            /*DIR *dp;
            int i;
            struct dirent *ep;*/
            /*dp = opendir (outputDir);
            if (dp != NULL){
              while (ep = readdir (dp))
              i++;
              (void) closedir (dp);
             }else {
                throw new Exception("NOT VALID DIRECTORY");
            }*/
            int i =1;

           for(;;){
                cv::Mat fr;
                cap >> fr;
                std::string filePath = outputDir;
                std::string fileName = std::to_string(i)+".png";
                cv::imwrite(filePath+fileName, fr);
                Frame f(filePath+fileName, outputDir, fileName, 6);
                f.run();
            }

        //}catch(cv::Exception e){
            //Log error
           // exit(0);
        //}
   }
}
