#include "stm32f10x.h"                  // Device header



/*
*************************************************
* 函数名：GPIO_Init_All
* 功能：初始化LED和按键GPIO
*************************************************
*/
void GPIO_Init_All(void)
{

    GPIO_InitTypeDef GPIO_InitStructure;


    /*
    ============================
    开启GPIO时钟
    ============================
    */

    RCC_APB2PeriphClockCmd(
        RCC_APB2Periph_GPIOA |
        RCC_APB2Periph_GPIOB |
        RCC_APB2Periph_AFIO,
        ENABLE
    );


    /*
    ============================
    LED初始化
    PA1 PA2 输出
    ============================
    */

    GPIO_InitStructure.GPIO_Pin =
        GPIO_Pin_1 | GPIO_Pin_2;

    GPIO_InitStructure.GPIO_Mode =
        GPIO_Mode_Out_PP;

    GPIO_InitStructure.GPIO_Speed =
        GPIO_Speed_50MHz;


    GPIO_Init(GPIOA,&GPIO_InitStructure);



    /*
    LED默认关闭
    高电平灭
    */

    GPIO_SetBits(GPIOA,
        GPIO_Pin_1 | GPIO_Pin_2);



    /*
    ============================
    按键初始化
    PB11 PB1 输入上拉
    ============================
    */

    GPIO_InitStructure.GPIO_Pin =
        GPIO_Pin_11 | GPIO_Pin_1;


    GPIO_InitStructure.GPIO_Mode =
        GPIO_Mode_IPU;


    GPIO_Init(GPIOB,&GPIO_InitStructure);

}
