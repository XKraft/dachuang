#include<deque>
#include"c_library_v1-master/common/mavlink.h"
#include<wiringPi.h>
#include<wiringSerial.h>
#include <unistd.h>
#include"./head/debug.h"


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
    mavlink_message_t _msg;
    mavlink_status_t status;
    unsigned char BufSend[MAVLINK_MAX_PACKET_LEN];
    int BufSendLen = 0;

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

    // mavlink_msg_request_data_stream_pack(1, 1, &_msg, 1, 1, MAVLINK_MSG_ID_ATTITUDE, 5, 1);
	// BufSendLen = mavlink_msg_to_send_buffer(BufSend, &_msg);
    // if(write(fd, BufSend, BufSendLen))
    // {
    //     cout << "Serial Write successfully! MAVLINK_MSG_ID_SET_ATTITUDE_TARGET" << endl;
    // }
    // mavlink_msg_request_data_stream_pack(1, 1, &_msg, 1, 1, MAVLINK_MSG_ID_RAW_IMU, 5, 1);
	// BufSendLen = mavlink_msg_to_send_buffer(BufSend, &_msg);
    // if(write(fd, BufSend, BufSendLen))
    // {
    //     cout << "Serial Write successfully! MAVLINK_MSG_ID_RAW_IMU" << endl;
    // }
    //请求飞控发送指定消息

    if(piThreadCreate(readThread))
    {
        printf("error2:unenble to creat readThread\n");
        return -3;
    }

    // mavlink_msg_command_long_pack(100, 200, &_msg, 1, 1, MAV_CMD_REQUEST_MESSAGE, 0, MAVLINK_MSG_ID_ATTITUDE, 0, 0, 0, 0, 0, 1);
    // BufSendLen = mavlink_msg_to_send_buffer(BufSend, &_msg);
    // printf_packed_msg(BufSend, BufSendLen);
    // if(write(fd, BufSend, BufSendLen))
    // {
    //     cout << "Serial Write successfully! MAVLINK_MSG_ID_SET_ATTITUDE_TARGET" << endl;
    // }
    // mavlink_msg_command_long_pack(100, 200, &_msg, 1, MAV_COMP_ID_ALL, MAV_CMD_SET_MESSAGE_INTERVAL, 0, MAVLINK_MSG_ID_ATTITUDE, 500, 0, 0, 0, 0, 1);
    // BufSendLen = mavlink_msg_to_send_buffer(BufSend, &_msg);
    // printf_packed_msg(BufSend, BufSendLen);
    // if(write(fd, BufSend, BufSendLen))
    // {
    //     cout << "Serial Write successfully! MAVLINK_MSG_ID_SET_ATTITUDE_TARGET" << endl;
    // }
    //mavlink_msg_request_data_stream_pack(1, 1, &_msg, 1, 1, MAVLINK_MSG_ID_ATTITUDE, 5, 1);
    mavlink_msg_request_data_stream_pack(100, 200, &_msg, 1, MAV_COMP_ID_ALL, MAV_DATA_STREAM_ALL, 500, 1);
	BufSendLen = mavlink_msg_to_send_buffer(BufSend, &_msg);
    printf_packed_msg(BufSend, BufSendLen);
    if(write(fd, BufSend, BufSendLen))
    {
        cout << "Serial Write successfully! MAVLINK_MSG_ID_SET_ATTITUDE_TARGET" << endl;
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
                printf("msgid:%d stx:%x   ", msg.msgid, msg.magic);
                switch (msg.msgid)
                {
                case MAVLINK_MSG_ID_HEARTBEAT: 
                    break;
                case MAVLINK_MSG_ID_ATTITUDE: 
                    mavlink_attitude_t attitude_msg;
                    mavlink_msg_altitude_decode(&msg, &altitude_msg);
                    cout << "attitude: pitch:" << attitude_msg.pitch << " roll:" << attitude_msg.roll << " yaw:" << attitude_msg.yaw << endl;
                    break;
                case MAVLINK_MSG_ID_RAW_IMU: 
                // case MAVLINK_MSG_ID_COMMAND_ACK: 
                //     cout << "commond ack! ";
                //     mavlink_command_ack_t msg_command_ack;
                //     mavlink_msg_command_ack_decode(&msg, &msg_command_ack);
                //     cout << "command:" << (int)msg_command_ack.command  << " result:" << (int)msg_command_ack.result << "!" << endl;break;
                default: 
                    break;
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
            size = read(fd, rbuf, 8);
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
//     int size = serialDataAvail(fd);
//     if(size > 0)
//     {
//         printf("(%d) ", size);fflush(stdout);
//         size = read(fd, rbuf, size);
//         printf("[%d] ", size);fflush(stdout);
//         for(int i = 0; i < size; ++i)
//         {
//             Qbuf.push_back(rbuf[i]);
//         }
//     }
//     else
//     {
//         cout << "no data!" << endl;
//     }
// }
