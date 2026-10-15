#include "stm32f10x.h"

int main(void)
{
/* 1. 开启 GPIOA 和 TIM2 时钟 */
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);


/* 2. 配置 PA0 为输出 */
GPIO_InitTypeDef GPIO_InitStructure;

GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

GPIO_Init(GPIOA, &GPIO_InitStructure);

/* 高电平熄灭，低电平点亮 */
GPIO_SetBits(GPIOA, GPIO_Pin_0);

/* 3. 配置定时器时基 */
TIM_TimeBaseInitTypeDef TIM_InitStructure;

TIM_TimeBaseStructInit(&TIM_InitStructure);

TIM_InitStructure.TIM_Prescaler = 7199;
TIM_InitStructure.TIM_Period = 9999;
TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;

TIM_TimeBaseInit(TIM2, &TIM_InitStructure);

/* 4. 清除初始化产生的更新标志 */
TIM_ClearFlag(TIM2, TIM_FLAG_Update);

/* 5. 启动定时器 */
TIM_Cmd(TIM2, ENABLE);

while (1)
{
    /* 6. 查询更新标志 */
    if (TIM_GetFlagStatus(TIM2, TIM_FLAG_Update) == SET)
    {
        TIM_ClearFlag(TIM2, TIM_FLAG_Update);

        /* 翻转 PA0 */
        GPIOA->ODR ^= GPIO_Pin_0;
    }
}


}
