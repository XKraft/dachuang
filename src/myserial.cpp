#include"../head/myserial.h"

//构造函数
Serial::Serial()
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
Serial::~Serial()
{
    Qbuf.clear();
}

//得到串口缓冲区存在的字符数
int Serial::GetSerialBufByteNumber()
{
    return serialDataAvail(serialfd);
}

//从串口缓冲区读取一个字节
void Serial::ReadSerialByte()
{
    if(serialDataAvail(serialfd) > 0)
        Qbuf.push_back(serialGetchar(serialfd));
}

//从串口缓冲区读取number个字节
int Serial::ReadSerialBytes(int number)
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
void Serial::WriteSerialByte(uint8_t byte)
{
    serialPutchar(serialfd, byte);
}

//向串口缓冲区写入number个字节
bool Serial::WriteSerialBytes(int number, uint8_t* buf)
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
uint8_t Serial::GetQbufByte()
{
    uint8_t temp = Qbuf.front();
    Qbuf.pop_front();
    return temp;
}

//得到队列中的元素个数
int Serial::GetQbufNumber()
{
    return Qbuf.size();
}