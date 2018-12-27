//系统库
#include "delay.h"
#include "sys.h"
#include "usart.h"
//用户外设库
#include "beep.h"
#include "led.h"
#include "key.h"

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    delay_init();
    uart_init(115200);
    LED_Init();
    BEEP_Init();
    KEY_Init();

    while (1)
    {
        RED_LED = !RED_LED;
        BLUE_LED = !BLUE_LED;
        delay_ms(200);
        printf("Running...\r\n");       //串口1输出
    }
}

