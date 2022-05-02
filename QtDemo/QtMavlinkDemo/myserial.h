#ifndef MYSERIAL_H
#define MYSERIAL_H

#include <wiringPi.h>
#include <wiringSerial.h>
#include <mavlink.h>
#include <iostream>
#include <deque>

class MySerial
{
public:
    MySerial();
    ~MySerial();
    int GetSerialBufByteNumber();
    void ReadSerialByte();
    int ReadSerialBytes(int number);
    void WriteSerialByte(uint8_t byte);
    bool WriteSerialBytes(int number, uint8_t* buf);
    uint8_t GetQbufByte();
    int GetQbufNumber();
    void RequestPixhawkSendMsg();

protected:
    int serialfd;
    std::deque<uint8_t> Qbuf;
    uint8_t BufSend[MAVLINK_MAX_PACKET_LEN];
    int BufSendLen = 0;
    mavlink_message_t msg;
};

#endif // MYSERIAL_H
