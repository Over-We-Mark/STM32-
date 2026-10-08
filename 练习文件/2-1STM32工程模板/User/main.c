#include "stm32f10x.h"

int main(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

   GPIO_InitTypeDef GPIO_Structtt;
    GPIO_Structtt.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_Structtt.GPIO_Pin = GPIO_Pin_0   | GPIO_Pin_1  ;
    GPIO_Structtt.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_Structtt);

    GPIO_ResetBits(GPIOA,GPIO_Pin_0   | GPIO_Pin_1 );
    
    while(1) {
        // 循环保持
    }
}

