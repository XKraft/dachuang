#include "mainwindow.h"

#include <QApplication>
#include <mavlink.h>
#include <unistd.h>
#include "myserial.h"

void mavlink_decode(uint8_t msgid);
PI_THREAD (readThread);
PI_THREAD (parseThread);

MySerial serial;
uint8_t byte;
mavlink_message_t msg;
mavlink_status_t status;
float roll = 0, pitch = 0, yaw = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    if(piThreadCreate(readThread))
    {
        std::cout << "erro3:unenble to creat readThread" << std::endl;
        exit(-3);
    }
    if(piThreadCreate(parseThread))
    {
        std::cout << "error4:unable to creat parseThread" << std::endl;
        exit(-4);
    }
    serial.RequestPixhawkSendMsg();

    w.show();

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

PI_THREAD (parseThread)
{
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
}
void mavlink_decode(uint8_t msgid)
{
    switch (msgid)
    {
        case MAVLINK_MSG_ID_ATTITUDE:
            mavlink_attitude_t attitude_msg;
            mavlink_msg_attitude_decode(&msg, &attitude_msg);
            std::cout << "attitude: pitch:" << attitude_msg.pitch << " roll:" << attitude_msg.roll << " yaw:" << attitude_msg.yaw << std::endl;
            roll = attitude_msg.roll; pitch = attitude_msg.pitch; yaw = attitude_msg.yaw;
            break;
        default:
            break;
    }
}
