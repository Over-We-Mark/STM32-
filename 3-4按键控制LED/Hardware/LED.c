#include "stm32f10x.h"                  // Device header
#include "KEY.h"



void LED(void){
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

  GPIO_InitTypeDef GPIO_Insturt;
  GPIO_Insturt.GPIO_Mode =  GPIO_Mode_Out_PP;
  GPIO_Insturt.GPIO_Pin = GPIO_Pin_1 |GPIO_Pin_2;
  GPIO_Insturt.GPIO_Speed =  GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&GPIO_Insturt);

 GPIO_SetBits(GPIOA,GPIO_Pin_1 |GPIO_Pin_2);
}

void LED1_ON(void){
  GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}
void LED1_OFF(void){
  GPIO_SetBits(GPIOA,GPIO_Pin_1);
}
void LED_ON2(void){
  GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}
void LED_OFF2(void){
  GPIO_SetBits(GPIOA,GPIO_Pin_2);
}
