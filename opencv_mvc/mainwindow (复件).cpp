#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Button_select->setEnabled(false);
    ui->Button_process->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Imaege"), "/home/black-tea/桌面", tr("Image Files(*.png *.jpg *.jpeg *.bmp)"));
    if(fileName != fileName.null){
        if(colordetector.setInputImage(fileName.toLocal8Bit().data())){
            image = colordetector.getInputImage();
        }
//        image = cv::imread(fileName.toLocal8Bit().data());
        cv::Mat img_1;
        image.copyTo(img_1);
        cv::cvtColor(img_1, img_1, CV_BGR2RGB);

        if(img_1.data){
            ui->Button_select->setEnabled(true);
            QImage img = QImage ((const unsigned char*)(img_1.data),img_1.cols, img_1.rows, img_1.cols * img_1.channels(),QImage::Format_RGB888);
            ui->label_img->setPixmap(QPixmap::fromImage(img));
            ui->label_img->resize(ui->label_img->pixmap()->size());
        }
    };

}

void MainWindow::on_Button_select_clicked()
{
    QColor color = QColorDialog::getColor(Qt::gray, this);

    ui->Button_process->setEnabled(true);
}

void MainWindow::on_Button_process_clicked()
{

}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    ui->label->clear();
    QString Distance_value = QString("Color \nDistance \nThreshould %1").arg(value);
    ui->label->setText(Distance_value);
}
