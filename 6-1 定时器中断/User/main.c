#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
uint16_t num = 0;
int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	Timer_Init();

	
	OLED_ShowString(1, 3, "Num:");	//1行3列显示字符串HelloWorld!

	
	

	
	while (1)
	{
		OLED_ShowNum(1,5,num,5);
	}
}
