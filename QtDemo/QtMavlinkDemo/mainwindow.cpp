#include "mainwindow.h"
#include "./ui_mainwindow.h"

const char* seriesname[3] = {"roll", "yaw", "pitch"};
Qt::GlobalColor color[3] = {Qt::red, Qt::blue, Qt::green};
int count = 0;
float AttitudeData[3] = {0};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chart1 = new QChart();
    chart1->setTitle((QString)"数据曲线");
    ui->widget_2->setChart(chart1);
    ui->widget_2->setRubberBand(QChartView::NoRubberBand);//矩形缩放
    ui->widget_2->setRenderHint(QPainter::Antialiasing);//抗锯齿
    ui->widget_2->show();

    axisX = new QValueAxis;
    axisX->setRange(0, 30);
    axisX->setLabelFormat(("%.2f"));
    axisX->setTitleText("时间/s");
    axisX->setGridLineVisible(false);
    axisX->setTickCount(2);
    axisY = new QValueAxis;
    axisY->setRange(0, 200);
    axisY->setLabelFormat(("%.2f"));
    axisY->setTitleText("角度/°");

    chart1->addAxis(axisX, Qt::AlignBottom);
    chart1->addAxis(axisY, Qt::AlignLeft);

    chart1->legend()->setVisible(true);

    for(int i = 0; i < 3; ++i)
    {
        QSplineSeries* s = new QSplineSeries(this);
        s->setName(QString(seriesname[i]));
        chart1->addSeries(s);
        s->attachAxis(axisX);//将数据与坐标轴绑定
        s->attachAxis(axisY);
        QPen pen;
        pen.setBrush(color[i]);
        pen.setColor(color[i]);
        s->setPen(pen);
        series.append(s);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer1;
    delete chart1;
    delete axisX;
    delete axisY;
}

void MainWindow::on_action_triggered()
{
    timer1 = new QTimer(this);
    timer1->start(30);
    count = 0;
    MainWindow::connect(timer1, &QTimer::timeout, this, [=](){
        AttitudeData[0] = roll;
        AttitudeData[1] = yaw;
        AttitudeData[2] = pitch;
        ui->label_roll->setText((QString)"横滚角roll:" + QString::number(AttitudeData[0] * 180 / 3.14159) + (QString)"°");
        ui->label_yaw->setText((QString)"偏航角yaw:" + QString::number(AttitudeData[1] * 180 / 3.14159) + (QString)"°");
        ui->label_pitch->setText((QString)"俯仰角pitch:" + QString::number(AttitudeData[2] * 180 / 3.14159) + (QString)"°");
        UpdateSeriesData();
    });
}


void MainWindow::on_action_E_triggered()
{
    timer1->stop();
    count = 0;
    foreach(QSplineSeries* s, series)
    {
        QVector<QPointF> v;
        s->replace(v);
    }
    axisX->setRange(0, 30);
    ui->label_roll->setText((QString)"横滚角roll:");
    ui->label_yaw->setText((QString)"偏航角yaw:");
    ui->label_pitch->setText((QString)"俯仰角pitch:");
}

void MainWindow::UpdateSeriesData()
{
    int i = 0;
    foreach(QSplineSeries* s, series)
    {
        if(s->isVisible())
        {
            if(s->count() < 1000)
            {
                s->append(QPointF(count * 0.03, AttitudeData[i] * 180 / 3.14159));
            }
            else
            {
                axisX->setRange((count - 1000) * 0.03, count * 0.03);
                QVector<QPointF> v = s->points();
                v.append(QPointF(count * 0.03, AttitudeData[i] * 180 / 3.14159));
                v.pop_front();
                s->replace(v);
            }
        }
        i++;
    }
    count++;
}

