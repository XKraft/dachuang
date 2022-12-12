/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QRadioButton *radioButton_l;
    QRadioButton *radioButton_r;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_roll_n;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *lineEdit_roll_a;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_yaw_r_n;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLineEdit *lineEdit_yaw_r_a;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_yaw_l_n;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_7;
    QLineEdit *lineEdit_yaw_l_a;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLineEdit *lineEdit_pitch_up_n;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_9;
    QLineEdit *lineEdit_pitch_up_a;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_10;
    QLineEdit *lineEdit_pitch_down_n;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_11;
    QLineEdit *lineEdit_pitch_down_a;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(492, 388);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(Dialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        radioButton_l = new QRadioButton(widget);
        radioButton_l->setObjectName(QString::fromUtf8("radioButton_l"));

        horizontalLayout->addWidget(radioButton_l);

        radioButton_r = new QRadioButton(widget);
        radioButton_r->setObjectName(QString::fromUtf8("radioButton_r"));

        horizontalLayout->addWidget(radioButton_r);


        verticalLayout_2->addWidget(widget);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_roll_n = new QLineEdit(widget_3);
        lineEdit_roll_n->setObjectName(QString::fromUtf8("lineEdit_roll_n"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_roll_n->sizePolicy().hasHeightForWidth());
        lineEdit_roll_n->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit_roll_n);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_roll_a = new QLineEdit(widget_3);
        lineEdit_roll_a->setObjectName(QString::fromUtf8("lineEdit_roll_a"));
        sizePolicy1.setHeightForWidth(lineEdit_roll_a->sizePolicy().hasHeightForWidth());
        lineEdit_roll_a->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit_roll_a);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_yaw_r_n = new QLineEdit(widget_4);
        lineEdit_yaw_r_n->setObjectName(QString::fromUtf8("lineEdit_yaw_r_n"));
        sizePolicy1.setHeightForWidth(lineEdit_yaw_r_n->sizePolicy().hasHeightForWidth());
        lineEdit_yaw_r_n->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEdit_yaw_r_n);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        lineEdit_yaw_r_a = new QLineEdit(widget_4);
        lineEdit_yaw_r_a->setObjectName(QString::fromUtf8("lineEdit_yaw_r_a"));
        sizePolicy1.setHeightForWidth(lineEdit_yaw_r_a->sizePolicy().hasHeightForWidth());
        lineEdit_yaw_r_a->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEdit_yaw_r_a);


        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        lineEdit_yaw_l_n = new QLineEdit(widget_5);
        lineEdit_yaw_l_n->setObjectName(QString::fromUtf8("lineEdit_yaw_l_n"));
        sizePolicy1.setHeightForWidth(lineEdit_yaw_l_n->sizePolicy().hasHeightForWidth());
        lineEdit_yaw_l_n->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEdit_yaw_l_n);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_7 = new QLabel(widget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        lineEdit_yaw_l_a = new QLineEdit(widget_5);
        lineEdit_yaw_l_a->setObjectName(QString::fromUtf8("lineEdit_yaw_l_a"));
        sizePolicy1.setHeightForWidth(lineEdit_yaw_l_a->sizePolicy().hasHeightForWidth());
        lineEdit_yaw_l_a->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEdit_yaw_l_a);


        verticalLayout_2->addWidget(widget_5);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(widget_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        lineEdit_pitch_up_n = new QLineEdit(widget_6);
        lineEdit_pitch_up_n->setObjectName(QString::fromUtf8("lineEdit_pitch_up_n"));
        sizePolicy1.setHeightForWidth(lineEdit_pitch_up_n->sizePolicy().hasHeightForWidth());
        lineEdit_pitch_up_n->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(lineEdit_pitch_up_n);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        label_9 = new QLabel(widget_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_5->addWidget(label_9);

        lineEdit_pitch_up_a = new QLineEdit(widget_6);
        lineEdit_pitch_up_a->setObjectName(QString::fromUtf8("lineEdit_pitch_up_a"));
        sizePolicy1.setHeightForWidth(lineEdit_pitch_up_a->sizePolicy().hasHeightForWidth());
        lineEdit_pitch_up_a->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(lineEdit_pitch_up_a);


        verticalLayout_2->addWidget(widget_6);

        widget_7 = new QWidget(widget_2);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_10 = new QLabel(widget_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_6->addWidget(label_10);

        lineEdit_pitch_down_n = new QLineEdit(widget_7);
        lineEdit_pitch_down_n->setObjectName(QString::fromUtf8("lineEdit_pitch_down_n"));
        sizePolicy1.setHeightForWidth(lineEdit_pitch_down_n->sizePolicy().hasHeightForWidth());
        lineEdit_pitch_down_n->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(lineEdit_pitch_down_n);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        label_11 = new QLabel(widget_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_6->addWidget(label_11);

        lineEdit_pitch_down_a = new QLineEdit(widget_7);
        lineEdit_pitch_down_a->setObjectName(QString::fromUtf8("lineEdit_pitch_down_a"));
        sizePolicy1.setHeightForWidth(lineEdit_pitch_down_a->sizePolicy().hasHeightForWidth());
        lineEdit_pitch_down_a->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(lineEdit_pitch_down_a);


        verticalLayout_2->addWidget(widget_7);


        verticalLayout->addWidget(widget_2);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "\350\256\276\347\275\256\350\256\255\347\273\203\344\273\273\345\212\241\345\217\202\346\225\260", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\345\272\267\345\244\215\346\211\213:", nullptr));
        radioButton_l->setText(QCoreApplication::translate("Dialog", "\345\267\246\346\211\213", nullptr));
        radioButton_r->setText(QCoreApplication::translate("Dialog", "\345\217\263\346\211\213", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\347\216\257\350\275\254\346\254\241\346\225\260:", nullptr));
        lineEdit_roll_n->setText(QCoreApplication::translate("Dialog", "10", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\347\216\257\350\275\254\350\247\222\345\272\246:", nullptr));
        lineEdit_roll_a->setText(QCoreApplication::translate("Dialog", "45.0", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "\345\260\272\345\201\217\346\254\241\346\225\260:", nullptr));
        lineEdit_yaw_r_n->setText(QCoreApplication::translate("Dialog", "10", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "\345\260\272\345\201\217\350\247\222\345\272\246:", nullptr));
        lineEdit_yaw_r_a->setText(QCoreApplication::translate("Dialog", "30.0", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "\346\241\241\345\201\217\346\254\241\346\225\260:", nullptr));
        lineEdit_yaw_l_n->setText(QCoreApplication::translate("Dialog", "10", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "\346\241\241\345\201\217\350\247\222\345\272\246:", nullptr));
        lineEdit_yaw_l_a->setText(QCoreApplication::translate("Dialog", "25.0", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog", "\346\216\214\345\261\210\346\254\241\346\225\260:", nullptr));
        lineEdit_pitch_up_n->setText(QCoreApplication::translate("Dialog", "10", nullptr));
        label_9->setText(QCoreApplication::translate("Dialog", "\346\216\214\345\261\210\350\247\222\345\272\246:", nullptr));
        lineEdit_pitch_up_a->setText(QCoreApplication::translate("Dialog", "50.0", nullptr));
        label_10->setText(QCoreApplication::translate("Dialog", "\350\203\214\344\274\270\346\254\241\346\225\260:", nullptr));
        lineEdit_pitch_down_n->setText(QCoreApplication::translate("Dialog", "10", nullptr));
        label_11->setText(QCoreApplication::translate("Dialog", "\350\203\214\344\274\270\350\247\222\345\272\246:", nullptr));
        lineEdit_pitch_down_a->setText(QCoreApplication::translate("Dialog", "35.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
