#include "stm32f10x.h"

int main(void) {
    // 1. 开启 GPIOC 的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    // 2. 配置 GPIO 结构体参数
    GPIO_InitTypeDef GPIO_Instruc;
    GPIO_Instruc.GPIO_Mode = GPIO_Mode_Out_PP;   // 推挽输出
    GPIO_Instruc.GPIO_Pin = GPIO_Pin_13;         // Pin 13
    GPIO_Instruc.GPIO_Speed = GPIO_Speed_50MHz;  // 50MHz
    
    // 3. 调用初始化函数，把配置写入寄存器
    GPIO_Init(GPIOC, &GPIO_Instruc);
    
    // 4. 操作 GPIO：将 PC13 输出低电平
    //GPIO_ResetBits(GPIOC, GPIO_Pin_13);

		GPIO_SetBits(GPIOC, GPIO_Pin_13);
    
    while(1) {
        // 循环保持
    }
}