#include <REGX52.H>

void UartInit() // 4800bps@11.0592MHz
{
    PCON &= 0x7F; // 波特率不倍速
    SCON = 0x50;  // 8位数据,可变波特率
    TMOD &= 0x0F; // 清除定时器1模式位
    TMOD |= 0x20; // 设定定时器1为8位自动重装方式
    TL1 = 0xFA;   // 设定定时初值
    TH1 = 0xFA;   // 设定定时器重装值
    ET1 = 0;      // 禁止定时器1中断
    TR1 = 1;      // 启动定时器1
    ES = 1;
    EA = 1;
}

void UartSend(unsigned char Byte)
{
    SBUF = Byte;
    while (TI == 0);
    TI = 0;
}

// 串口中断模板
/*
void UART_Routine() interrupt 4{
    // 接收信息判断
    if(RI == 1){
        P2 = ~SBUF; // 将接收到的数据发送到P2口
        UartSend(SBUF); // 将接收到的数据发送回去
        RI = 0;
    }
}
*/