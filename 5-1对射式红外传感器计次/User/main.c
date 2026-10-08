#include "stm32f10x.h"
#include "OLED.h"
#include "Delay.h"
#include "CenterSensor.h"


int main(void)
{
    OLED_Init();
    CenterSensor_init();

    
	OLED_ShowString(1, 1, "COUNT:");
    
    while (1)
    {
        OLED_ShowNum(1,7,ConterSen(),5);
    }
}
