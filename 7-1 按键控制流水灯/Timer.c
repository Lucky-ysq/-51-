#include <REGX52.H>


void Timer0Init(void)		//1毫秒@12.000MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;		//允许定时器0中断
	EA = 1;		//打开总中断
	PT0 = 0;		//设置定时器0为高优先级
}

// 模板
/*void Timer0_Routine() interrupt 1
{
	static unsigned int count = 0;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	count++;
	if (count >= 1000) //1s
	{
		P2_0 = ~P2_0; //流水灯取反
		count = 0;
	}
}
	*/