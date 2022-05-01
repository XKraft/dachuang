#include "myserial.h"

MySerial::MySerial(QWidget *parent)
    : QMainWindow{parent}
{
    if(wiringPiSetup() < 0)
    {
        std::cout << "error1:init wiringPi error" << std::endl;
        exit(-1);
    }

    if((serialfd = serialOpen("/dev/ttyAMA0", 57600)) < 0)
    {
        std::cout << "error2:unable to open serial" << std::endl;
        exit(-2);
    }

    Qbuf.clear();
}

//析构函数
MySerial::~MySerial()
{
    Qbuf.clear();
    serialClose(serialfd);
}

//得到串口缓冲区存在的字符数
int MySerial::GetSerialBufByteNumber()
{
    return serialDataAvail(serialfd);
}

//从串口缓冲区读取一个字节
void MySerial::ReadSerialByte()
{
    if(serialDataAvail(serialfd) > 0)
        Qbuf.push_back(serialGetchar(serialfd));
}

//从串口缓冲区读取number个字节
int MySerial::ReadSerialBytes(int number)
{
    int count = 0;
    for(int i = 0; i < number; ++i)
    {
        if(serialDataAvail(serialfd) > 0)
        {
            Qbuf.push_back(serialGetchar(serialfd));
            ++count;
        }
    }
    return count;
}

//向串口缓冲区写入一个字节
void MySerial::WriteSerialByte(uint8_t byte)
{
    serialPutchar(serialfd, byte);
}

//向串口缓冲区写入number个字节
bool MySerial::WriteSerialBytes(int number, uint8_t* buf)
{
    int count = 0;
    for(int i = 0; i < number; ++i)
    {
        serialPutchar(serialfd, buf[i]);
        ++count;
    }
    if(count == number)
        return true;
    else
        return false;
}

//从队列中得到一个字节
uint8_t MySerial::GetQbufByte()
{
    uint8_t temp = Qbuf.front();
    Qbuf.pop_front();
    return temp;
}

//得到队列中的元素个数
int MySerial::GetQbufNumber()
{
    return Qbuf.size();
}

void MySerial::RequestPixhawkSendMsg()
{
    if(piThreadCreate(readThread))
    {
        std::cout << "erro3:unenble to creat readThread" << std::endl;
        exit(-3);
    }

    mavlink_msg_request_data_stream_pack(100, 200, &msg, 1, MAV_COMP_ID_ALL, MAVLINK_MSG_ID_ATTITUDE, 200, 1);
    BufSendLen = mavlink_msg_to_send_buffer(BufSend, &msg);
    if(this->WriteSerialBytes(BufSendLen, BufSend))
    {
        std::cout << "Serial Write successfully! request the message : MAVLINK_MSG_ID_ATTITUDE" << std::endl;
    }
}

