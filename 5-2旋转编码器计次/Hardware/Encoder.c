#include "stm32f10x.h" // Device header
int16_t Encoder_count;

void Encoder_Init(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
  GPIO_InitTypeDef GPIO_Struct;
  GPIO_Struct.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Struct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
  GPIO_Struct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_Struct);

  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);

  EXTI_InitTypeDef Exit_Struct;
  Exit_Struct.EXTI_Line = EXTI_Line0 | EXTI_Line1;
  Exit_Struct.EXTI_LineCmd = ENABLE;
  Exit_Struct.EXTI_Mode = EXTI_Mode_Interrupt;

  Exit_Struct.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_Init(&Exit_Struct);

 
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitTypeDef NVIC_Struct;
    NVIC_Struct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Struct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_Struct.NVIC_IRQChannelSubPriority        = 1;

    NVIC_Struct.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_Init(&NVIC_Struct);

    NVIC_Struct.NVIC_IRQChannel = EXTI1_IRQn;
    NVIC_Init(&NVIC_Struct);
}
int16_t Encoder_Get(void)
{
  int16_t Temp;
  Temp = Encoder_count;
  Encoder_count = 0;
  return Temp;
}
void EXTI0_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line0) == SET)
  {
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == 0)
    {
      Encoder_count--;
    }

    EXTI_ClearITPendingBit(EXTI_Line0);
  };
}
void EXTI1_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line1) == SET)
  {
    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)
    {
      Encoder_count++;
    }
    EXTI_ClearITPendingBit(EXTI_Line1);
  }
}
