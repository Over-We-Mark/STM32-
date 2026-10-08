#include "stm32f10x.h"                  // Device header
#include "Delay.h"
uint16_t Conter_Count;

void CenterSensor_init(void){
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
  GPIO_InitTypeDef GPIO_Struct;
  GPIO_Struct.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Struct.GPIO_Pin = GPIO_Pin_14  ;
  GPIO_Struct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB,&GPIO_Struct);

  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);

  EXTI_InitTypeDef Exit_Struct;
  Exit_Struct.EXTI_Line = EXTI_Line14 ;
  Exit_Struct.EXTI_LineCmd = ENABLE;
  Exit_Struct.EXTI_Mode = EXTI_Mode_Interrupt;
 
  Exit_Struct.EXTI_Trigger =EXTI_Trigger_Rising;
  EXTI_Init(&Exit_Struct);

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

  NVIC_InitTypeDef NVIC_Struct;
  NVIC_Struct.NVIC_IRQChannel =  40;
  NVIC_Struct.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Struct.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_Struct.NVIC_IRQChannelSubPriority = 2;
  NVIC_Init(&NVIC_Struct);

}
uint16_t ConterSen(void){
  return Conter_Count;
}
void EXTI15_10_IRQHandler(void){
  if (EXTI_GetITStatus(EXTI_Line14) ==SET )
  {
    Conter_Count++;
    EXTI_ClearITPendingBit(EXTI_Line14);
  }
  
}
