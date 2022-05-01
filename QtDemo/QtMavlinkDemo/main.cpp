#include "mainwindow.h"

#include <QApplication>
#include <mavlink.h>
#include <unistd.h>
#include "myserial.h"

void mavlink_decode(uint8_t msgid);

MySerial serial;
mavlink_message_t msg;
mavlink_status_t status;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    uint8_t byte;


    QPushButton* btn = new QPushButton;
    btn->setParent(&w);
    btn->setText("开始");
    btn->resize(200, 100);
    btn->move(300, 300);

    MainWindow::connect(btn, &QPushButton::clicked, &serial, &MySerial::RequestPixhawkSendMsg);
    MainWindow::connect(btn, &QPushButton::clicked, btn, &QPushButton::close);


    w.show();

    while(1)
    {
        if(serial.GetQbufNumber() != 0)
        {
            piLock(0);
            byte = serial.GetQbufByte();
            piUnlock(0);
            if(mavlink_parse_char(MAVLINK_COMM_0, byte, &msg, &status))
            {
                mavlink_decode(msg.msgid);
            }
        }
    }


    return a.exec();
}

PI_THREAD (readThread)
{
    while(1)
    {
        piLock(0);
        serial.ReadSerialByte();
        piUnlock(0);
    }
}

void mavlink_decode(uint8_t msgid)
{
    switch (msgid)
    {
        case MAVLINK_MSG_ID_ATTITUDE:
            mavlink_attitude_t attitude_msg;
            mavlink_msg_attitude_decode(&msg, &attitude_msg);
            std::cout << "attitude: pitch:" << attitude_msg.pitch << " roll:" << attitude_msg.roll << " yaw:" << attitude_msg.yaw << std::endl;
            break;
        default:
            break;
    }
}
