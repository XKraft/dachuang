#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

extern int train_plan[5];
extern float train_des[5];
extern bool hand;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

signals:
    void get_trainpamar_ok();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
