#include "stm32f10x.h"                  // Device heade
#include "Delay.h"
void Key_Init(void){
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_STRUCT;
    GPIO_STRUCT.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_STRUCT.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
    GPIO_STRUCT.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOB, &GPIO_STRUCT);  // 修正
}
uint8_t Key_GetNumber(void){
  uint8_t Key_num = 0;
  if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0)
  {
    // 消除抖动
    Delay_ms(20);
    while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0);
    Delay_ms(20);
    Key_num = 2;
  }
  if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0)
  {
    // 消除抖动
    Delay_ms(20);
    while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0);
    Delay_ms(20);
    Key_num = 1;
  }
  
  return Key_num;
}

  