#include"../head/debug.h"

void printf_packed_msg(unsigned char* buf, int len)
{
    for(int i = 0; i <len; ++i)
        cout << std::setfill('0') << std::setw(2) << std::hex << buf[i] << " ";
    cout << endl;
}