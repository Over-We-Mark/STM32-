#include "stm32f10x.h"
#include "stdint.h"
#include "Delay.h"
#include "LED.h"
#include "KEY.h"

uint8_t KeyNum;
int main(void)
{
   
   
  
    while(1){
       
    LED1_ON();
   Delay_ms(500);
   LED1_OFF();
   Delay_ms(500);
   
   LED_ON2();   
   Delay_ms(500);
   LED_OFF2();
   Delay_ms(500);

    };
}
