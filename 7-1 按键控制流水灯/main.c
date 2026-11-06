#include <REGX52.H>
#include <INTRINS.H>
#include "Timer.h"
#include "Key.h"
unsigned char keyNum, LEDModel;

void main()
{
	P2 = 0xFE; //设置P2口低7位为流水灯，最高位为按键输入
	Timer0Init();
	while (1)
	{
		keyNum = getKey();
		if (keyNum == 1)
		{
			LEDModel++;
			if (LEDModel >= 2)
			{
				LEDModel = 0;
			}
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int count = 0;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	count++;
	if (count >= 1000) //1s
	{
		if(LEDModel == 0){
			P2=_crol_(P2,1);
		}else if (LEDModel == 1)
		{
			P2 = _cror_(P2,1);
		}
		
		count = 0;
	}
}