#include "dialog.h"
#include "ui_dialog.h"

int train_plan[5] = {10, 10, 10, 10, 10};
float train_des[5] = {45.0, 30.0, -25.0, 50.0, -35.0};
bool hand = 0;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    if(ui->radioButton_l->isChecked())
    {
        hand = 0;
        train_des[0] = ui->lineEdit_roll_a->text().toFloat();
        train_des[1] = ui->lineEdit_yaw_r_a->text().toFloat();
        train_des[2] = -ui->lineEdit_yaw_l_a->text().toFloat();
    }
    if(ui->radioButton_r->isChecked())
    {
        hand = 1;
        train_des[0] = -ui->lineEdit_roll_a->text().toFloat();
        train_des[1] = -ui->lineEdit_yaw_r_a->text().toFloat();
        train_des[2] = ui->lineEdit_yaw_l_a->text().toFloat();
    }

    train_plan[0] = ui->lineEdit_roll_n->text().toInt();
    train_plan[1] = ui->lineEdit_yaw_r_n->text().toInt();
    train_plan[2] = ui->lineEdit_yaw_l_n->text().toInt();
    train_plan[3] = ui->lineEdit_pitch_up_n->text().toInt();
    train_plan[4] = ui->lineEdit_pitch_down_n->text().toInt();



    train_des[3] = ui->lineEdit_pitch_up_a->text().toFloat();
    train_des[4] = -ui->lineEdit_pitch_down_a->text().toFloat();

    get_trainpamar_ok();
}
