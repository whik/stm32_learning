#include "timer.h"
#include "led.h"
#include "usart.h"

//����ӳ��(CH1/PB4��CH2/PB5��CH3/PB0��CH4/PB1)
void TIM3_Int_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef IO_Init;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef OC_Init;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	//��ʱ��ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//GPIOʱ��ʹ��
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	//��ӳ��ʱ��ʹ��,��ʹ��Ҳ���ԣ�
	
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE);		//������ӳ��	
	
	IO_Init.GPIO_Mode = GPIO_Mode_AF_PP;
	IO_Init.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5;
	IO_Init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &IO_Init);
		
    TIM_TimeBaseStructure.TIM_Period = arr; 
    TIM_TimeBaseStructure.TIM_Prescaler = psc;		
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 

	OC_Init.TIM_OCMode = TIM_OCMode_PWM1;//���ģʽ
	OC_Init.TIM_OutputState = ENABLE;				//���ʹ��
	OC_Init.TIM_OCPolarity = TIM_OCPolarity_High;	//�������
	GPIO_Init(GPIOC, &IO_Init);
	
	TIM_OC1Init(TIM3, &OC_Init);		//TIM3_CH1���
	TIM_OC2Init(TIM3, &OC_Init);		//TIM3_CH2�����CH1�෴
	TIM_OC3Init(TIM3, &OC_Init);		//TIM3_CH1���
	TIM_OC4Init(TIM3, &OC_Init);		//TIM3_CH2�����CH1�෴

	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);

    TIM_Cmd(TIM3, ENABLE); 
}
/*
void TIM3_IRQHandler(void)   
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
    {
        RED_LED = !RED_LED;			//PA7
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);    //���TIM7�����жϱ�־
    }
}
*/



