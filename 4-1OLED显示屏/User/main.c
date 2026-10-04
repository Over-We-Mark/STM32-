#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"

int main(void)
{
    OLED_Init();
    Delay_ms(300);

    OLED_ShowString(1, 1, "HELLO");
    OLED_ShowString(2, 1, "STM32");

    while (1)
    {
    }
}
