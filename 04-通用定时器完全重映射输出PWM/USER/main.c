//ϵͳ��
#include "delay.h"
#include "sys.h"
#include "usart.h"
//�û������
#include "beep.h"
#include "led.h"
#include "key.h"
#include "timer.h"

//�����ܣ�PA8����ΪTIM1_CH1���10KHz��70% PWM����
//10KHz = 72M / [(1+71)*(1+99)] = 0.0001s
//Prescaler = 72 - 1 = 71;
//Period = 100 - 1 = 99;		//�ɿ���ռ�ձ�

int main(void)
{

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    delay_init();
    uart_init(115200);
    LED_Init();			//PWMģʽ��Ҫ����Ϊ�����������
    BEEP_Init();
    KEY_Init();

	TIM3_Int_Init(100 - 1, 72 - 1);//10KHz
	
	TIM_SetCompare1(TIM3, 20);		//PC6
	TIM_SetCompare2(TIM3, 40);		//PC7
	TIM_SetCompare3(TIM3, 60);		//PC8
	TIM_SetCompare4(TIM3, 80);		//PC9

    while (1)
    {
		
    }
	
	
}

