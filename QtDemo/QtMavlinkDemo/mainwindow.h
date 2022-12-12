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

    void on_action_3_triggered();

    void on_action_2_triggered();

signals:
    void end_train();

private:
    Ui::MainWindow *ui;

    QTimer* timer1;
    QTimer* timer2;
    QTimer* timer3;
    QtCharts::QChart* chart1;
    QtCharts::QValueAxis* axisX;
    QtCharts::QValueAxis* axisY;
    QList<QtCharts::QSplineSeries*> series;
    QtCharts::QSplineSeries* des_series;

    void UpdateSeriesData();
    void train();
    void set_havedone_text();
    void reset_train_pamar();
};
#endif // MAINWINDOW_H
