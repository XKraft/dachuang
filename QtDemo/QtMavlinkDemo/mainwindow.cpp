#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer* timer = new QTimer(this);

    MainWindow::connect(ui->pushButton_start, &QPushButton::clicked, this, [=](){timer->start(400);});
    MainWindow::connect(timer, &QTimer::timeout, this, [=](){
        ui->label_roll->setText((QString)"横滚角roll:" + QString::number(roll * 180 / 3.14159) + (QString)"°");
        ui->label_pitch->setText((QString)"偏航角yaw:" + QString::number(pitch * 180 / 3.14159) + (QString)"°");
        ui->label_yaw->setText((QString)"俯仰角pitch:" + QString::number(yaw * 180 / 3.14159) + (QString)"°");
    });
    MainWindow::connect(ui->pushButton_end, &QPushButton::clicked, this, &MainWindow::close);

}

MainWindow::~MainWindow()
{
    delete ui;
}

