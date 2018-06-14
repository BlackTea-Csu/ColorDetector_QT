#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc/imgproc.hpp>

#include "opencv_process/ColorDetectorController.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Button_open_clicked();

    void on_Button_select_clicked();

    void on_Button_process_clicked();

    void on_verticalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    cv::Mat image;
    ColorDetectorController colordetector;
};

#endif // MAINWINDOW_H
