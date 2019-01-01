#include "timer.h"
#include "led.h"
#include "usart.h"

//���ù��ܣ�TIM1_CH1 - PA8, PA9, PA10, PA11
void TIM1_Int_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef IO_Init;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef OC_Init;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);	//��ʱ��ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//GPIOʱ��ʹ��
	
	IO_Init.GPIO_Mode = GPIO_Mode_AF_PP;		//�����������
	IO_Init.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
	IO_Init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &IO_Init);
		
    TIM_TimeBaseStructure.TIM_Period = arr; 
    TIM_TimeBaseStructure.TIM_Prescaler = psc;		
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); 

	OC_Init.TIM_OCMode = TIM_OCMode_PWM1;//���ģʽ
	OC_Init.TIM_OutputState = ENABLE;				//���ʹ��
	OC_Init.TIM_OCPolarity = TIM_OCPolarity_High;	//�������
	
	TIM_OC1Init(TIM1, &OC_Init);		
	TIM_OC2Init(TIM1, &OC_Init);	
	TIM_OC3Init(TIM1, &OC_Init);	
	TIM_OC4Init(TIM1, &OC_Init);	

	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	TIM_CtrlPWMOutputs(TIM1, ENABLE);

    TIM_Cmd(TIM1, ENABLE); 
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



