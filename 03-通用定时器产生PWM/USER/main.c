//系统库
#include "delay.h"
#include "sys.h"
#include "usart.h"
//用户外设库
#include "beep.h"
#include "led.h"
#include "key.h"
#include "timer.h"

//程序功能：PA8复用为TIM1_CH1输出10KHz、70% PWM方波
//10KHz = 72M / [(1+71)*(1+99)] = 0.0001s
//Prescaler = 72 - 1 = 71;
//Period = 100 - 1 = 99;		//可控制占空比

int main(void)
{
	int i;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    delay_init();
    uart_init(115200);
    LED_Init();			//PWM模式需要配置为复用推挽输出
    BEEP_Init();
    KEY_Init();

	TIM3_Int_Init(100 - 1, 72 - 1);//10KHz

    while (1)
    {
		if(i <= 0)
		{
			for(i = 0; i <= 100; i += 8)
			{
				TIM_SetCompare1(TIM3, i);		//占空比 = 70 / 100 = 70%;	
				TIM_SetCompare2(TIM3, i);		//占空比 = 70 / 100 = 70%;	
				delay_ms(100);
			}
		}
		delay_ms(300);
		if(i >=100)
		{
			for(i = 100; i > 0; i -= 8)
			{
				TIM_SetCompare1(TIM3, i);		//占空比 = 70 / 100 = 70%;	
				TIM_SetCompare2(TIM3, i);		//占空比 = 70 / 100 = 70%;	
				delay_ms(100);
			}
		}
		delay_ms(300);
        printf("Running...\r\n");       //串口1输出
    }
	
	
}

