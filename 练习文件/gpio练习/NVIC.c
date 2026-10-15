#include "stm32f10x.h"                  // Device header
/*
*************************************************
* 函数名：NVIC_Init_All
* 功能：配置中断优先级
*************************************************
*/

void NVIC_Init_All(void)
{

    NVIC_InitTypeDef NVIC_InitStructure;



    /*
    设置优先级分组

    2位抢占
    2位响应

    */

    NVIC_PriorityGroupConfig(
        NVIC_PriorityGroup_2
    );



    /*
    ============================
    PB11
    EXTI15_10
    ============================
    */

    NVIC_InitStructure.NVIC_IRQChannel =
        EXTI15_10_IRQn;


    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =
        1;


    NVIC_InitStructure.NVIC_IRQChannelSubPriority =
        1;


    NVIC_InitStructure.NVIC_IRQChannelCmd =
        ENABLE;


    NVIC_Init(&NVIC_InitStructure);




    /*
    ============================
    PB1
    EXTI1
    ============================
    */


    NVIC_InitStructure.NVIC_IRQChannel =
        EXTI1_IRQn;


    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =
        1;


    NVIC_InitStructure.NVIC_IRQChannelSubPriority =
        2;


    NVIC_Init(&NVIC_InitStructure);

}
