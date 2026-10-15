#include "stm32f10x.h"


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




/*
*************************************************
* 主函数
*************************************************
*/


int main(void)
{


    GPIO_Init_All();


    EXTI_Init_All();


    NVIC_Init_All();



    while(1)
    {


        /*
        主循环为空

        等待中断

        */


    }

}
