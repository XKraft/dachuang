#include<deque>
#include"c_library_v1-master/common/mavlink.h"
#include<wiringPi.h>
#include<wiringSerial.h>
#include <unistd.h>
#include"./head/debug.h"
#include"./head/myserial.h"

Serial serial; 
mavlink_message_t msg, _msg;
mavlink_status_t status;
uint8_t byte;
unsigned char BufSend[MAVLINK_MAX_PACKET_LEN];
int BufSendLen = 0;

PI_THREAD (readThread);
void mavlink_decode(uint8_t msgid);

int main()
{
    //创建线程
    if(piThreadCreate(readThread))
    {
        printf("error2:unenble to creat readThread\n");
        return -3;
    }

    //向飞控请求发送三个角度的数据
    mavlink_msg_request_data_stream_pack(100, 200, &_msg, 1, MAV_COMP_ID_ALL, MAV_DATA_STREAM_ALL, 200, 1);
	BufSendLen = mavlink_msg_to_send_buffer(BufSend, &_msg);
    if(serial.WriteSerialBytes(BufSendLen, BufSend))
    {
        cout << "Serial Write successfully! request the message : MAVLINK_MSG_ID_ATTITUDE" << endl;
    }

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

    return 0;
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
            cout << "attitude: pitch:" << attitude_msg.pitch << " roll:" << attitude_msg.roll << " yaw:" << attitude_msg.yaw << endl;
            break;
        default: 
            break;
    }
}
