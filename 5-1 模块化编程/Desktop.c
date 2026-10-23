#include <REGX52.H>
#include "Delay.h"


unsigned char NumberValue[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Desktop(unsigned char Index,unsigned char Number){
        switch(Index){
            // 1~8对应P2.2~P2.4的三位二进制数  P2_2为1 P2_3为2 P2_4为4
            case 1: P2_2=1;P2_3=1;P2_4=1;break; // 7 
            case 2: P2_2=0;P2_3=1;P2_4=1;break; // 6
            case 3: P2_2=1;P2_3=0;P2_4=1;break; // 5
            case 4: P2_2=0;P2_3=0;P2_4=1;break; // 4
            case 5: P2_2=1;P2_3=1;P2_4=0;break; // 3
            case 6: P2_2=0;P2_3=1;P2_4=0;break; // 2
            case 7: P2_2=1;P2_3=0;P2_4=0;break; // 1
            case 8: P2_2=0;P2_3=0;P2_4=0;break; // 0
        }
        P0=NumberValue[Number];
		Delay(1);
		P0=0x00; // 关闭数码管
}
