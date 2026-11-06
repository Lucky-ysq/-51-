#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned int Sec;

void main(){
    UartInit();
    while(1){
        UartSend(Sec);
        Sec++;
		Delay(1000);
    }
}
