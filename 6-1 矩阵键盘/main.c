#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "ButtonNum.h"

void main()
{
	unsigned char KeyNum = 0;
	LCD_Init();
	while(1)
	{
		KeyNum = ButtonNum();
		if(KeyNum){
			LCD_ShowNum(1,1,KeyNum,2);
		}
	}
}