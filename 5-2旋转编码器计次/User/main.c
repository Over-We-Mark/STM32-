#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "Encoder.h"

int16_t Num;
int main(void)
{
    OLED_Init();
    Encoder_Init();
    

    OLED_ShowString(1, 1, "NUM:");
    
    while (1)
    {
        Num += Encoder_Get();
        OLED_ShowSignedNum(1,5,Num,5);
    }
}
