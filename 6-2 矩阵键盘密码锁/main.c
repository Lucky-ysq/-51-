#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "ButtonNum.h"

void main()
{
	unsigned char KeyNum = 0;
	int password = 0;
	int count = 0;
	LCD_Init();
	LCD_ShowString(1, 1, "Password:");
	while (1)
	{
		KeyNum = ButtonNum(); // 获取用户输入的数字
		if (KeyNum)
		{
			if (KeyNum <= 10) // 输入密码
			{
				if (count < 4) // 限制密码长度
				{
					password = password * 10 + (KeyNum % 10); // 密码叠加
					count++;								  // 计数
					LCD_ShowNum(2, 1, password, 4);
				}
			}
			else if (KeyNum == 11) // 确认键
			{
				if (password == 1111)
				{
					count = 0;
					password = 0;
					LCD_ShowString(1, 14, "OK ");
				}
				else
				{
					count = 0;
					password = 0;
					LCD_ShowString(1, 14, "503   ");
				}
			}
			else if (KeyNum == 12) // 清除键
			{
				count = 0;
				password = 0;
				LCD_ShowString(1, 1, "Password:");
				LCD_ShowNum(2, 1, password, 4);
			}
		}
	}
}