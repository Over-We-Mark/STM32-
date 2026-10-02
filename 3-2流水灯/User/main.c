#include "stm32f10x.h"
#include "Delay.h"

int main(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitTypeDef GPIO_Insturt;
    GPIO_Insturt.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Insturt.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
    GPIO_Insturt.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_Insturt);

  
    
    while(1){
       GPIO_Write(GPIOA,~0X0001);
       Delay_ms(500);
       GPIO_Write(GPIOA,~0X0002);
       Delay_ms(500);
       GPIO_Write(GPIOA,~0X0004);
       Delay_ms(500);
       GPIO_Write(GPIOA,~0X0008);
       Delay_ms(500);
       GPIO_Write(GPIOA,~0X0010);
       Delay_ms(500);
       GPIO_Write(GPIOA,~0X0020);
       Delay_ms(500);
       GPIO_Write(GPIOA,~0X0040);
       Delay_ms(500);
       GPIO_Write(GPIOA,~0X0080);
       Delay_ms(500);

    };
}