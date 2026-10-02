#include "stm32f10x.h"                  // Device header

void LED(void){
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitTypeDef GPIO_Insturt;
    GPIO_Insturt.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Insturt.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_1        ;
    GPIO_Insturt.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_Insturt);
}