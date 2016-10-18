#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frame.h"

using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SubmitButton_clicked()
{

   QString path = ui->lineEdit->text();
   std::string p = path.toStdString();
   if(p.find("/") == 0){
       p = p.substr(p.find_last_of("/")+1, p.length() - p.find_last_of("/"));
   }
   else if(p.find("\\") == 0){
       p = p.substr(p.find_last_of("\\")+1, p.length() - p.find_last_of("\\"));
   }
   QString fileName = QString::fromStdString(p);
   ui->textEdit->insertPlainText(fileName + " Loading\n");
   Frame f(path.toStdString());
   ui->textEdit->insertPlainText(fileName + " Loaded\n");
   f.Frame::run();
   ui->textEdit->insertPlainText(fileName+ " Saved!\n");





}
