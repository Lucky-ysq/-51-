#include <REGX52.H>
#include "UART.h"


void main(){
    UartInit();
    while(1){
    }
}


void UART_Routine() interrupt 4{
    // 接收信息判断
    if(RI == 1){
        P2 = ~SBUF; // 将接收到的数据发送到P2口
        UartSend(SBUF); // 将接收到的数据发送回去
        RI = 0;
    }
}