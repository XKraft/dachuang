/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_E;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *logo;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_pitch;
    QLabel *label_yaw;
    QLabel *label_roll;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *label_hand;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_roll_r;
    QLabel *label_yaw_r;
    QLabel *label_yaw_l;
    QLabel *label_pitch_up;
    QLabel *label_pitch_down;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_havedone2;
    QLabel *label_havedone3;
    QLabel *label_havedone4;
    QLabel *label_havedone5;
    QLabel *label_havedone6;
    QLabel *label_tishi;
    QSpacerItem *verticalSpacer;
    QtCharts::QChartView *widget_2;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 750);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_E = new QAction(MainWindow);
        action_E->setObjectName(QString::fromUtf8("action_E"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        verticalLayout_7 = new QVBoxLayout(widget_8);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_4 = new QHBoxLayout(widget_9);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        logo = new QLabel(widget_9);
        logo->setObjectName(QString::fromUtf8("logo"));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        logo->setFont(font);
        logo->setLayoutDirection(Qt::LeftToRight);
        logo->setTextFormat(Qt::AutoText);
        logo->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(logo);


        verticalLayout_7->addWidget(widget_9);

        frame = new QFrame(widget_8);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        frame->setMidLineWidth(0);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label->setFont(font1);

        verticalLayout_3->addWidget(label);

        label_pitch = new QLabel(frame);
        label_pitch->setObjectName(QString::fromUtf8("label_pitch"));

        verticalLayout_3->addWidget(label_pitch);

        label_yaw = new QLabel(frame);
        label_yaw->setObjectName(QString::fromUtf8("label_yaw"));

        verticalLayout_3->addWidget(label_yaw);

        label_roll = new QLabel(frame);
        label_roll->setObjectName(QString::fromUtf8("label_roll"));

        verticalLayout_3->addWidget(label_roll);


        verticalLayout_7->addWidget(frame);


        horizontalLayout_2->addWidget(widget_8);

        widget = new QWidget(widget_4);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_2 = new QFrame(widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        label_hand = new QLabel(frame_2);
        label_hand->setObjectName(QString::fromUtf8("label_hand"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_hand->setFont(font2);
        label_hand->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_hand);

        widget_5 = new QWidget(frame_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 4);
        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        verticalLayout_5 = new QVBoxLayout(widget_6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 0, -1, 0);
        label_roll_r = new QLabel(widget_6);
        label_roll_r->setObjectName(QString::fromUtf8("label_roll_r"));

        verticalLayout_5->addWidget(label_roll_r);

        label_yaw_r = new QLabel(widget_6);
        label_yaw_r->setObjectName(QString::fromUtf8("label_yaw_r"));

        verticalLayout_5->addWidget(label_yaw_r);

        label_yaw_l = new QLabel(widget_6);
        label_yaw_l->setObjectName(QString::fromUtf8("label_yaw_l"));

        verticalLayout_5->addWidget(label_yaw_l);

        label_pitch_up = new QLabel(widget_6);
        label_pitch_up->setObjectName(QString::fromUtf8("label_pitch_up"));

        verticalLayout_5->addWidget(label_pitch_up);

        label_pitch_down = new QLabel(widget_6);
        label_pitch_down->setObjectName(QString::fromUtf8("label_pitch_down"));

        verticalLayout_5->addWidget(label_pitch_down);


        horizontalLayout_3->addWidget(widget_6);

        widget_7 = new QWidget(widget_5);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        verticalLayout_6 = new QVBoxLayout(widget_7);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 0, -1, 0);
        label_havedone2 = new QLabel(widget_7);
        label_havedone2->setObjectName(QString::fromUtf8("label_havedone2"));

        verticalLayout_6->addWidget(label_havedone2);

        label_havedone3 = new QLabel(widget_7);
        label_havedone3->setObjectName(QString::fromUtf8("label_havedone3"));

        verticalLayout_6->addWidget(label_havedone3);

        label_havedone4 = new QLabel(widget_7);
        label_havedone4->setObjectName(QString::fromUtf8("label_havedone4"));

        verticalLayout_6->addWidget(label_havedone4);

        label_havedone5 = new QLabel(widget_7);
        label_havedone5->setObjectName(QString::fromUtf8("label_havedone5"));

        verticalLayout_6->addWidget(label_havedone5);

        label_havedone6 = new QLabel(widget_7);
        label_havedone6->setObjectName(QString::fromUtf8("label_havedone6"));

        verticalLayout_6->addWidget(label_havedone6);


        horizontalLayout_3->addWidget(widget_7);


        verticalLayout_4->addWidget(widget_5);


        verticalLayout_2->addWidget(frame_2);


        horizontalLayout_2->addWidget(widget);


        horizontalLayout->addWidget(widget_4);


        verticalLayout->addWidget(widget_3);

        label_tishi = new QLabel(centralwidget);
        label_tishi->setObjectName(QString::fromUtf8("label_tishi"));
        sizePolicy.setHeightForWidth(label_tishi->sizePolicy().hasHeightForWidth());
        label_tishi->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        label_tishi->setFont(font3);
        label_tishi->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_tishi);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        widget_2 = new QtCharts::QChartView(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setBaseSize(QSize(0, 0));

        verticalLayout->addWidget(widget_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addAction(action_3);
        menu->addAction(action_E);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\211\213\350\205\225\345\272\267\345\244\215\350\256\255\347\273\203\347\263\273\347\273\237", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213(&S)", nullptr));
#if QT_CONFIG(shortcut)
        action->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_E->setText(QCoreApplication::translate("MainWindow", "\347\273\223\346\235\237(&E)", nullptr));
#if QT_CONFIG(shortcut)
        action_E->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        action_2->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\350\256\255\347\273\203\350\256\241\345\210\222", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\346\250\241\345\274\217", nullptr));
        logo->setText(QCoreApplication::translate("MainWindow", "\346\211\213\350\205\225\345\272\267\345\244\215\350\256\255\347\273\203\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\346\211\213\350\205\225\345\274\257\346\233\262\345\247\277\346\200\201", nullptr));
        label_pitch->setText(QCoreApplication::translate("MainWindow", "\346\216\214\345\261\210\343\200\201\350\203\214\344\274\270\350\247\222\345\272\246:", nullptr));
        label_yaw->setText(QCoreApplication::translate("MainWindow", "\345\260\272\345\201\217\343\200\201\346\241\241\345\201\217\350\247\222\345\272\246:", nullptr));
        label_roll->setText(QCoreApplication::translate("MainWindow", "\347\216\257\350\275\254\350\247\222\345\272\246:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\272\267\345\244\215\350\256\255\347\273\203\350\256\241\345\210\222", nullptr));
        label_hand->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\345\272\267\345\244\215\350\256\255\347\273\203\344\270\272:\345\267\246\346\211\213", nullptr));
        label_roll_r->setText(QCoreApplication::translate("MainWindow", "\347\216\257\350\275\254\346\254\241\346\225\260:10", nullptr));
        label_yaw_r->setText(QCoreApplication::translate("MainWindow", "\345\260\272\345\201\217\346\254\241\346\225\260:10", nullptr));
        label_yaw_l->setText(QCoreApplication::translate("MainWindow", "\346\241\241\345\201\217\346\254\241\346\225\260:10", nullptr));
        label_pitch_up->setText(QCoreApplication::translate("MainWindow", "\346\216\214\345\261\210\346\254\241\346\225\260:10", nullptr));
        label_pitch_down->setText(QCoreApplication::translate("MainWindow", "\350\203\214\344\274\270\346\254\241\346\225\260:10", nullptr));
        label_havedone2->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\256\214\346\210\220:", nullptr));
        label_havedone3->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\256\214\346\210\220:", nullptr));
        label_havedone4->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\256\214\346\210\220:", nullptr));
        label_havedone5->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\256\214\346\210\220:", nullptr));
        label_havedone6->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\256\214\346\210\220:", nullptr));
        label_tishi->setText(QCoreApplication::translate("MainWindow", "\350\257\267\347\202\271\345\207\273\"\351\200\211\351\241\271-\345\274\200\345\247\213\"\346\235\245\345\274\200\345\247\213\345\272\267\345\244\215\350\256\255\347\273\203", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
