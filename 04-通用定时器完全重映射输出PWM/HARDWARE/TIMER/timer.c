#include "timer.h"
#include "led.h"
#include "usart.h"

//TIM3��ȫ��ӳ��
//TIM3_CH1-PC6
//TIM3_CH2-PC7
//TIM3_CH3-PC8
//TIM3_CH4-PC9

void TIM3_Int_Init(u16 arr, u16 psc)
{
//    NVIC_InitTypeDef NVIC_InitStructure;
	GPIO_InitTypeDef IO_Init;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef OC_Init;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	//��ʱ��ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	//GPIOʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	//��ӳ��ʱ��ʹ��
	
	//�ο��ֲ�P119-��ȫӳ��
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);	
	
	IO_Init.GPIO_Mode = GPIO_Mode_AF_PP;
	IO_Init.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	IO_Init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &IO_Init);
		
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



