#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define CHARTSNAMESPACE_H

#include <QMainWindow>
#include <QTimer>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QSplineSeries>
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
    QtCharts::QChart* chart1;
    QtCharts::QValueAxis* axisX;
    QtCharts::QValueAxis* axisY;
    QList<QtCharts::QSplineSeries*> series;

    void UpdateSeriesData();
};
#endif // MAINWINDOW_H
