#ifndef MYSERIAL
#define MYSERIAL
#include<wiringPi.h>
#include<wiringSerial.h>
#include<iostream>
#include<deque>

class Serial
{
    public:
    Serial();
    ~Serial();
    int GetSerialBufByteNumber();
    void ReadSerialByte();
    int ReadSerialBytes(int number);
    void WriteSerialByte(uint8_t byte);
    bool WriteSerialBytes(int number, uint8_t* buf);
    uint8_t GetQbufByte();
    int GetQbufNumber();

    protected:
    int serialfd;
    std::deque<uint8_t> Qbuf;
};

#endif