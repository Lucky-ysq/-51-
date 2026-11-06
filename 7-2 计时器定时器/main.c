#include <REGX52.H>
//#include "Delay.h"
#include "LCD1602.h"
#include "Timer.h"
unsigned int Sec, Min, Housr;

void main()
{
    Timer0Init();
    LCD_Init();
    LCD_ShowString(1, 1, "Clock:");
    LCD_ShowString(2,1,"  :  :");
    while (1)
    {
        LCD_ShowNum(2, 1, Housr,2);
        LCD_ShowNum(2, 4, Min,2);
        LCD_ShowNum(2, 7, Sec,2);
    }
}

void Timer0_Routine() interrupt 1
{
    static unsigned int count = 0;
    TL0 = 0x18; // 设置定时初值
    TH0 = 0xFC; // 设置定时初值
    count++;
    if (count >= 1000) // 1s
    {
        Sec++;
        if(Sec >= 60){
            Sec = 0;
            Min++;
            if(Min >= 60){
                Min = 0;
                Housr++;
                if (Housr >= 24)
                {
                    Housr = 0;
                }
                
            }
        }
        count = 0;
    }
}
