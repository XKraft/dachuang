#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
#include <cmath>

#define STATE_NOT_REACH 0
#define STATE_REACH_KEEPING 1
#define STATE_KEEP_FIAL 2
#define STATE_RESET 3
#define STATE_END 4

const char* seriesname[3] = {"环转角度", "尺偏、桡偏角度", "掌屈、背伸角度"};
Qt::GlobalColor color[3] = {Qt::red, Qt::blue, Qt::green};
int count = 0;
float AttitudeData[3] = {0};
float init_AttitudeData[3] = {0, 0, 0};
float cor_AttitudeData[3] = {0, 0, 0};


int train_plan_havedone[5] = {0, 0, 0, 0, 0};
int train_flag = 0;
const char* text_tishi1[] = {
    "请手腕向 内侧 转动,直到到达目标要求",
    "请手腕伸直向 小手指的方向 偏手掌,直到到达目标要求",
    "请手腕伸直向 大拇指的方向 偏手掌,直到到达目标要求",
    "请向 手心方向 弯手腕,直到到达目标要求",
    "请向 手背方向 抬手腕,直到到达目标要求"
};
int state = 0;

float calculate_yaw(float yaw, float init_yaw);
float calculate_pitch(float pitch, float init_pitch);
float calculate_roll(float roll, float init_roll);
void calculate_AttitudeData();
void reset_train_pamar();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chart1 = new QtCharts::QChart();
    chart1->setTitle((QString)"手腕姿态曲线");
    ui->widget_2->setChart(chart1);
    ui->widget_2->setRubberBand(QtCharts::QChartView::NoRubberBand);//矩形缩放
    ui->widget_2->setRenderHint(QPainter::Antialiasing);//抗锯齿
    ui->widget_2->show();

    axisX = new QtCharts::QValueAxis;
    axisX->setRange(0, 30);
    axisX->setLabelFormat(("%.2f"));
    axisX->setTitleText("时间/s");
    axisX->setGridLineVisible(false);
    axisX->setTickCount(2);
    axisY = new QtCharts::QValueAxis;
    axisY->setRange(-90, 90);
    axisY->setLabelFormat(("%.2f"));
    axisY->setTitleText("角度/°");

    chart1->addAxis(axisX, Qt::AlignBottom);
    chart1->addAxis(axisY, Qt::AlignLeft);

    chart1->legend()->setVisible(true);

    for(int i = 0; i < 3; ++i)
    {
        QtCharts::QSplineSeries* s = new QtCharts::QSplineSeries(this);
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

    des_series = new QtCharts::QSplineSeries(this);
    des_series->setName((QString)"目标角度");
    chart1->addSeries(des_series);
    des_series->attachAxis(axisX);
    des_series->attachAxis(axisY);
    QPen pen;
    pen.setBrush(Qt::black);
    pen.setColor(Qt::black);
    des_series->setPen(pen);

    timer1 = nullptr;
    timer2 = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete axisX;
    delete axisY;
}

void MainWindow::on_action_triggered()
{
    ui->label_tishi->setText((QString)"请手握传感器,训练将在5s后开始");
    timer2 = new QTimer(this);
    MainWindow::connect(timer2, &QTimer::timeout, this, [=](){
        init_AttitudeData[0] = roll;
        init_AttitudeData[1] = yaw;
        init_AttitudeData[2] = pitch;
        ui->label_tishi->setText((QString)"训练开始");
        if(timer2->isActive())
        {
            timer2->stop();
            delete timer2;
            timer2 = new QTimer(this);
            reset_train_pamar();
            timer2->start(30);
            MainWindow::connect(timer2, &QTimer::timeout, this, [=](){
                AttitudeData[0] = roll;
                AttitudeData[1] = yaw;
                AttitudeData[2] = pitch;
                UpdateSeriesData();
                train();
                set_havedone_text();
            });
        }
    });
    MainWindow::connect(this, &MainWindow::end_train, this, &MainWindow::on_action_E_triggered);
    timer2->start(5000);
}


void MainWindow::on_action_E_triggered()
{
    if(timer1)
    {
        timer1->stop();
        delete timer1;
        timer1 = nullptr;
    }
    if(timer2)
    {
        timer2->stop();
        delete timer2;
        timer2 = nullptr;
    }
    if(timer3)
    {
        timer3->stop();
        delete timer3;
        timer3 = nullptr;
    }
    count = 0;
    foreach(QtCharts::QSplineSeries* s, series)
    {
        QVector<QPointF> v;
        s->replace(v);
    }
    QVector<QPointF> v;
    des_series->replace(v);
    axisX->setRange(0, 30);
    ui->label_roll->setText((QString)"环转角度:");
    ui->label_yaw->setText((QString)"尺偏、桡偏角度:");
    ui->label_pitch->setText((QString)"掌屈、背伸角度:");
}

void MainWindow::on_action_3_triggered()
{
    init_AttitudeData[0] = 0;
    init_AttitudeData[1] = 0;
    init_AttitudeData[2] = 0;
    timer1 = new QTimer(this);
    timer1->start(30);
    count = 0;
    MainWindow::connect(timer1, &QTimer::timeout, this, [=](){
        AttitudeData[0] = roll;
        AttitudeData[1] = yaw;
        AttitudeData[2] = pitch;
        UpdateSeriesData();
    });
}

void MainWindow::on_action_2_triggered()
{
       Dialog* dialog = new Dialog(this);
       MainWindow::connect(dialog, &Dialog::get_trainpamar_ok, this, [=](){
            if(!hand)
                ui->label_hand->setText((QString)"当前康复训练为:左手");
            else
                ui->label_hand->setText((QString)"当前康复训练为:右手");
            ui->label_roll_r->setText((QString)"环转次数:" + QString::number(train_plan[0]));
            ui->label_yaw_r->setText((QString)"尺偏次数:" + QString::number(train_plan[1]));
            ui->label_yaw_l->setText((QString)"桡偏次数:" + QString::number(train_plan[2]));
            ui->label_pitch_up->setText((QString)"掌屈次数:" + QString::number(train_plan[3]));
            ui->label_pitch_down->setText((QString)"背伸次数:" + QString::number(train_plan[4]));
       });
       dialog->show();
}

void MainWindow::UpdateSeriesData()
{
    calculate_AttitudeData();
    ui->label_roll->setText((QString)"环转角度:" + QString::number(cor_AttitudeData[0]) + (QString)"°");
    ui->label_yaw->setText((QString)"尺偏、桡偏角度:" + QString::number(cor_AttitudeData[1]) + (QString)"°");
    ui->label_pitch->setText((QString)"掌屈、背伸角度:" + QString::number(cor_AttitudeData[2]) + (QString)"°");
    int i = 0;
    foreach(QtCharts::QSplineSeries* s, series)
    {
        s->setVisible(true);
        if(s->isVisible())
        {
            if(s->count() < 1000)
            {
                s->append(QPointF(count * 0.03, cor_AttitudeData[i]));
            }
            else
            {
                axisX->setRange((count - 1000) * 0.03, count * 0.03);
                QList<QPointF> v = s->points();
                v.append(QPointF(count * 0.03, cor_AttitudeData[i]));
                v.pop_front();
                s->replace(v);
            }
        }
        s->setVisible(false);
        i++;
    }
    if(des_series->count() < 1000)
        des_series->append(QPointF(count * 0.03, train_des[train_flag]));
    else
    {
        QList<QPointF> v = des_series->points();
        v.append(QPointF(count * 0.03, train_des[train_flag]));
        v.pop_front();
        des_series->replace(v);
    }
    count++;
    series[(train_flag + 1) / 2]->setVisible(true);
}

void MainWindow::train()
{
    switch (state)
    {
    case STATE_NOT_REACH:
        if(train_plan[train_flag] == 0)
        {
            state = STATE_RESET;
            break;
        }
        if(fabs(cor_AttitudeData[(train_flag + 1) / 2]) > fabs(train_des[train_flag]))
        {
            timer3 = new QTimer(this);
            MainWindow::connect(timer3, &QTimer::timeout, this, [=](){
                state = STATE_REACH_KEEPING;
                if(timer3->isActive())
                {
                    timer3->stop();
                    delete timer3;
                    timer3 = nullptr;
                }
            });
            timer3->start(2000);
            state = STATE_KEEP_FIAL;
        }
        ui->label_tishi->setText((QString)text_tishi1[train_flag]);
        break;
    case STATE_REACH_KEEPING: 
        ui->label_tishi->setText((QString)"本次动作已达标");
        timer3 = new QTimer(this);
        train_plan_havedone[train_flag]++;
        MainWindow::connect(timer3, &QTimer::timeout, this, [=](){
            ui->label_tishi->setText((QString)"本次动作已达标,请复位手腕");
            if(timer3->isActive())
            {
                timer3->stop();
                delete timer3;
                timer3 = nullptr;
            }
        });
        timer3->start(1000);
        state = STATE_RESET;
        break;
     case STATE_KEEP_FIAL:
        ui->label_tishi->setText((QString)"加油,请保持至少2s");
        if(fabs(cor_AttitudeData[(train_flag + 1) / 2]) < fabs(train_des[train_flag]))
        {
            if(timer3)
            {
                timer3->stop();
                delete timer3;
                timer3 = nullptr;
            }
        }
        else
        {
            if(!timer3)
            {
                timer3 = new QTimer(this);
                MainWindow::connect(timer3, &QTimer::timeout, this, [=](){
                    state = STATE_REACH_KEEPING;
                    if(timer3->isActive())
                    {
                        if(timer3)
                        {
                            timer3->stop();
                            delete timer3;
                            timer3 = nullptr;
                        }
                    }
                });
                timer3->start(2000);
            }

        }
        break;
    case STATE_RESET:
        if(fabs(cor_AttitudeData[(train_flag + 1) / 2]) < 10.0)
        {
           if(train_plan_havedone[train_flag] == train_plan[train_flag])
           {
               train_flag++; 
           }
           if(train_flag == 5)
           {
               ui->label_tishi->setText((QString)"恭喜您完成康复训练任务!");
               end_train();
               break;
           }
           state = STATE_NOT_REACH;
        }
        break;
    };
}

void MainWindow::reset_train_pamar()
{
    for(int i = 0; i < 5; ++i)
        train_plan_havedone[i] = 0;
    train_flag = 0;
    state = STATE_NOT_REACH;
    ui->label_havedone2->setText((QString)"已完成:");
    ui->label_havedone3->setText((QString)"已完成:");
    ui->label_havedone4->setText((QString)"已完成:");
    ui->label_havedone5->setText((QString)"已完成:");
    ui->label_havedone6->setText((QString)"已完成:");
}

void MainWindow::set_havedone_text()
{
    ui->label_havedone2->setText((QString)"已完成:" + QString::number(train_plan_havedone[0]) + (QString)"次");
    ui->label_havedone3->setText((QString)"已完成:" + QString::number(train_plan_havedone[1]) + (QString)"次");
    ui->label_havedone4->setText((QString)"已完成:" + QString::number(train_plan_havedone[2]) + (QString)"次");
    ui->label_havedone5->setText((QString)"已完成:" + QString::number(train_plan_havedone[3]) + (QString)"次");
    ui->label_havedone6->setText((QString)"已完成:" + QString::number(train_plan_havedone[4]) + (QString)"次");
}

float calculate_yaw(float yaw, float init_yaw)
{
    return yaw - init_yaw;
}

float calculate_pitch(float pitch, float init_pitch)
{
    return pitch - init_pitch;
}

float calculate_roll(float roll, float init_roll)
{
    return roll - init_roll;
}

void calculate_AttitudeData()
{
    for(int i = 0; i < 3; ++i)
        cor_AttitudeData[i] = (AttitudeData[i] - init_AttitudeData[i]) * 180 / 3.14159;
}


