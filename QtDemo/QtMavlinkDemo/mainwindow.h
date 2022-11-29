#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QSplineSeries>
#include <QRandomGenerator>
#include <QPointF>

extern float roll, pitch, yaw;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_action_E_triggered();

private:
    Ui::MainWindow *ui;

    QTimer* timer1;
    QChart* chart1;
    QValueAxis* axisX;
    QValueAxis* axisY;
    QList<QSplineSeries*> series;

    void UpdateSeriesData();
};
#endif // MAINWINDOW_H
