//系统库
#include "delay.h"
#include "sys.h"
#include "usart.h"
//用户外设库
#include "beep.h"
#include "led.h"
#include "key.h"
#include "timer.h"

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    delay_init();
    uart_init(115200);
    LED_Init();
    BEEP_Init();
    KEY_Init();

	TIM3_Int_Init(5000 - 1, 7200 - 1);//500ms中断
	
    while (1)
    {
        BLUE_LED = !BLUE_LED;
        delay_ms(250);
        printf("Running...\r\n");       //串口1输出
    }
}

