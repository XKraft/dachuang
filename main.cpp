#include<iostream>
#include<deque>
#include"c_library_v1-master/common/mavlink.h"
#include<wiringPi.h>
#include<wiringSerial.h>
#include <unistd.h>
using namespace std;

int fd;
unsigned char rbuf[MAVLINK_MAX_PACKET_LEN];
// int len = 0;
deque<unsigned char> Qbuf;
PI_THREAD (readThread);
void write_to_deque(int _num, unsigned char* buf);
// void serial_read();

int main()
{
    
    mavlink_message_t msg;
    mavlink_status_t status;
    printf("hello pi!\n");

    if(wiringPiSetup() < 0)
    {
        printf("init wiringPi error\n");
        return -2;
    }

    fd = serialOpen("/dev/ttyAMA0", 57600);
    
    if(fd < 0)
    {
        printf("error1:unable to open serial\n");
        return -1;
    }
    if(piThreadCreate(readThread))
    {
        printf("error2:unenble to creat readThread\n");
        return -3;
    }
    
    while(1)
    {
        // serial_read();
        //piLock(0);
	    if(Qbuf.size() != 0)
        {
            printf("%x ", Qbuf.front());fflush(stdout);
            if(mavlink_parse_char(MAVLINK_COMM_0, Qbuf.front(), &msg, &status))
            {
                //piUnlock(0);	            
	            Qbuf.pop_front();
                printf("msgid:%d stx:%x\n", msg.msgid, msg.magic);
                if(msg.msgid == MAVLINK_MSG_ID_HEARTBEAT)
                {
                    printf("heartbeat!\n");
	           	    mavlink_heartbeat_t msg_heartbeat;
		            mavlink_msg_heartbeat_decode(&msg, &msg_heartbeat);
		            printf("%x %x %x %x %x %x\n", msg_heartbeat.custom_mode, msg_heartbeat.type, msg_heartbeat.autopilot, msg_heartbeat.base_mode, msg_heartbeat.system_status, msg_heartbeat.mavlink_version);
                }
                else
                {
                    printf("other msg\n");
                }
            }
            else
            {
                //piUnlock(0);
	            Qbuf.pop_front();
            }
	    }
    }
    
    serialClose(fd);

    return 0;
}

PI_THREAD (readThread)
{
    while(1)
    {
        int size = serialDataAvail(fd);
        if( size> 0)
        {
            //piLock(0);
            printf("(%d) ", size);fflush(stdout);
            size = read(fd, rbuf, size);
            printf("[%d] ", size);fflush(stdout);
	        write_to_deque(size, rbuf);
            //piUnlock(0);
        }
    }
}

void write_to_deque(int _num, unsigned char* buf)
{
    for(int i = 0; i < _num; ++i)
    {
            Qbuf.push_back(rbuf[i]);
    }
}

// void serial_read()
// {
//     len = serialDataAvail(fd);
//     if(len > 0)
//     {
//         len = read(fd, rbuf, len);
//     }
//     for(int i = 0; i < len; ++i)
//     {
//         Qbuf.push_back(rbuf[i]);
//     }
// }