#include <REGX52.H> 
sbit RCK = P3^5; // 输出数据 
sbit SCK = P3^6; // 时钟信号
sbit SER = P3^4; // 串行数据输入

// 控制74HC595芯片的函数
void _74HC595_WriteByte(unsigned char Byte){
    unsigned char i;
    for(i=0;i<8;i++){
        SER = Byte&(0x80>>i); // 取最高位
        SCK = 1; // 下降沿时钟信号
        SCK = 0; // 上升沿时钟信号
    }
    RCK = 1;
	RCK = 0; // 输出数据
}

// 显示动画
void ShowCartoon(unsigned char Column, unsigned char Data){
    _74HC595_WriteByte(Data);
    P0=~(0x80>>Column); // 选择列
}             


void main(){
    SCK=0;
    RCK=0;
    ShowCartoon(0,0xD9);
    while(1){
    }
}
