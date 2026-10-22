#include "stm32f10x.h"                  // Device header
extern uint16_t num ;
void Timer_Init(void){

 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
  GPIO_InitTypeDef GPIO_Struct;
  GPIO_Struct.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Struct.GPIO_Pin = GPIO_Pin_0  ;
  GPIO_Struct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&GPIO_Struct);


 TIM_ETRClockMode2Config(TIM2,TIM_ExtTRGPSC_OFF,TIM_ExtTRGPolarity_NonInverted,0x0f);
	TIM_TimeBaseInitTypeDef Time_Struct;
	Time_Struct.TIM_ClockDivision = TIM_CKD_DIV1   ; //时钟分频
	Time_Struct.TIM_CounterMode = TIM_CounterMode_Up ; //计数模式
	Time_Struct.TIM_Period =10 - 1; //分配时基单元
	Time_Struct.TIM_Prescaler = 1- 1;
	Time_Struct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&Time_Struct);

  TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);//开启中断的功能 开启nvic时钟

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  NVIC_InitTypeDef NVIC_Struct;
  NVIC_Struct.NVIC_IRQChannel = 28;
  NVIC_Struct.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Struct.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_Struct.NVIC_IRQChannelSubPriority = 2;
  NVIC_Init(&NVIC_Struct);

  TIM_Cmd(TIM2,ENABLE);
}
void TIM2_IRQHandler(void){
  if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)
  {
    num++;
    TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
  }
  
}
uint16_t Timer_GerConter(void){
  return TIM_GetCounter(TIM2);
}
