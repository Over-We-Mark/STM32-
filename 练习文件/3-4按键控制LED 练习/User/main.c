#include "stm32f10x.h"
#include "stdint.h"
#include "Delay.h"
#include "LED.h"
#include "KEY.h"

uint8_t KeyNum;
int main(void)
{

    //   提供初始化函数
    LED_Init();
    Key_Init();
    while (1)
    {

        KeyNum = Key_GetNumber();
        if (KeyNum == 1)
        {
           LED1_Turn();
        }
        if (KeyNum == 2)
        {
            LED2_Turn();
        }
        
        
    };
}
