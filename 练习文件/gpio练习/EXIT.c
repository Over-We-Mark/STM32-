#include "stm32f10x.h"                  // Device header

/*
*************************************************
* 函数名：EXTI_Init_All
* 功能：配置外部中断
*************************************************
*/

void EXTI_Init_All(void)
{

    EXTI_InitTypeDef EXTI_InitStructure;


    /*
    ============================
    GPIO连接EXTI
    ============================
    */


    /*
    PB11 -> EXTI11
    */

    GPIO_EXTILineConfig(
        GPIO_PortSourceGPIOB,
        GPIO_PinSource11
    );


    /*
    PB1 -> EXTI1
    */

    GPIO_EXTILineConfig(
        GPIO_PortSourceGPIOB,
        GPIO_PinSource1
    );



    /*
    ============================
    PB11 EXTI配置
    ============================
    */

    EXTI_InitStructure.EXTI_Line =
        EXTI_Line11;


    EXTI_InitStructure.EXTI_Mode =
        EXTI_Mode_Interrupt;


    /*
    按下：
    1 -> 0
    所以下降沿
    */

    EXTI_InitStructure.EXTI_Trigger =
        EXTI_Trigger_Falling;


    EXTI_InitStructure.EXTI_LineCmd =
        ENABLE;


    EXTI_Init(&EXTI_InitStructure);



    /*
    ============================
    PB1 EXTI配置
    ============================
    */


    EXTI_InitStructure.EXTI_Line =
        EXTI_Line1;


    EXTI_Init(&EXTI_InitStructure);

}


/*
*************************************************
* 中断函数1
*
* PB11按键
*
* 控制PA1 LED
*
*************************************************
*/


void EXTI15_10_IRQHandler(void)
{


    if(EXTI_GetITStatus(EXTI_Line11)
        != RESET)
    {


        /*
        PA1翻转

        0->1
        1->0

        */

        GPIOA->ODR ^= GPIO_Pin_1;



        /*
        清除中断标志
        */

        EXTI_ClearITPendingBit(
            EXTI_Line11
        );

    }

}


/*
*************************************************
* 中断函数2
*
* PB1按键
*
* 控制PA2 LED
*
*************************************************
*/


void EXTI1_IRQHandler(void)
{


    if(EXTI_GetITStatus(EXTI_Line1)
        != RESET)
    {


        GPIOA->ODR ^= GPIO_Pin_2;



        EXTI_ClearITPendingBit(
            EXTI_Line1
        );


    }

}