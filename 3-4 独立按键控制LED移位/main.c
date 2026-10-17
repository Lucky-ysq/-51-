#include <REGX52.H>

void Delay(unsigned int ms) //@12.000MHz
{
    unsigned char i, j;
    while (ms--)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}

void main()
{
    unsigned char LEDNum = 0;
    P2 = ~0x01;
    while (1)
    {
        if (P3_1 == 0)
        {
            Delay(20);
            while (P3_1 == 0)
                ;
            Delay(20);
            LEDNum++;
            if (LEDNum >= 8)
                LEDNum = 0;
            P2 = ~(0x01 << LEDNum); 
        }
    }
}
