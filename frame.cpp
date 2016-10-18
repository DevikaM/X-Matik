#include "frame.h"


Frame::Frame(){}

Frame::Frame(std::string path){
    filePath = path;
    img = cv::imread(path);
    noPoint = 0;
    fileName = "whatever.png";
    file= fileName + ":";
    points = new ImagePoint[6];
    maxPoints = 6;
}
Frame::Frame(std::string path, std::string outDir, std::string filename, int maxP){
    filePath = path;
    img = cv::imread(path);
    noPoint = 0;
    fileName = filename;
    file= fileName + ":";
    maxPoints = maxP;
    outputDir = outDir;


}

void Frame::onMouse(int event, int x, int y, int flags, void* userdata){
    if ( event != 1 ) return;
    if(noPoint < maxPoints){
    cv::Point pt1 = cv::Point(x, y);
    cv::circle(img, pt1, 1, cvScalar(0, 255, 0), 12, 8, 0);
    //std::string tempFileName = (std::string) PATH+ "temp_"+std::to_string(noPoint+1)+".png";
    std::string tempFileName = outputDir + "temp_"+std::to_string(noPoint+1)+".png";
    cv::imwrite(tempFileName, img);
    ImagePoint tempPoint(x,y,tempFileName,noPoint+1);
    points[noPoint] = tempPoint;
    noPoint++;
    cv::imshow("image", img);
    }else {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","MAX POINTS REACHED");
        messageBox.setFixedSize(500,200);
    }


}
void Frame::onMouseWrapper(int event, int x, int y, int flags, void *param){
    Frame * fra = (Frame*) param;
    fra->onMouse(event,x,y,flags,0);
}
void Frame::run(){

    while(true){
    char key =  display();

        if(noPoint == maxPoints){
            QMessageBox msgBox;
            msgBox.setText("You've reached " + maxPoints);
            msgBox.setInformativeText("Do you want to save?");
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            int ret = msgBox.exec();
            if(ret == QMessageBox::Save){
                cvDestroyWindow("image");
                //cv::imwrite((std::string) PATH+fileName, img);
                cv::imwrite(outputDir+fileName, img);
                saveFile();
                break;
            }else if (ret == QMessageBox::Cancel){
               deletePoint();
            }
        }else {
            cvDestroyWindow("image");
            cv::imwrite(outputDir+fileName, img);
            if (key == ' '){
                if(!(noPoint == maxPoints)){
                    QMessageBox messageBox;
                    messageBox.critical(0,"Error","NOT ENOUGH POINTS");
                    messageBox.setFixedSize(500,200);
                }else
                    break;
            }else if((key == 'D' || key == 'd' ) && noPoint > 0){
                deletePoint();
            }
        }
    }
}

char Frame::display(){
    cv::namedWindow("image", CV_WINDOW_AUTOSIZE);
    cv::setMouseCallback("image", onMouseWrapper, this);
    imshow("image", img);
    return (char) cv::waitKey();
}


void Frame::saveFile(){
    for(int i = 1; i <= maxPoints; i++) std::remove((outputDir +"temp_"+std::to_string(i)+".png").c_str());
    std::fstream f;
    f.open (outputDir + "test.txt", std::ios::out);

    for(int t = 0; t < (maxPoints -1); t++){
        for(int s = 0; s <maxPoints - t - 1; s++){
            if(points[s].y() > points[s+1].y()){
                ImagePoint temp = points[s];
                points[s] = points[s+1];
                points[s+1] = temp;
            }
        }
    }

    for(int o = 0; o < maxPoints; o++){
        points[o].setIndex(o);
        file += points[o].display();
    }

    f << file;
    f.close();
}

void Frame::deletePoint(){
    if(noPoint > 1){
        std::cout << noPoint << std::endl;
        noPoint--;
        img = cv::imread(outputDir+ "temp_"+std::to_string(noPoint)+".png");
    }else{
        img = cv::imread(filePath);
        noPoint = 0;
    }
}





