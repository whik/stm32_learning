#include "timer.h"
#include "led.h"
#include "usart.h"

//TIM3_CH1 - PA6 - BLUE_LED
//TIM3_CH2 - PA7 - RED_LED

void TIM3_Int_Init(u16 arr, u16 psc)
{
//    NVIC_InitTypeDef NVIC_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef OC_Init;
	
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能

    TIM_TimeBaseStructure.TIM_Period = arr; 
    TIM_TimeBaseStructure.TIM_Prescaler = psc;		
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); 
/*
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE); 		//配置中断类型为溢出中断
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn; 
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
    NVIC_Init(&NVIC_InitStructure); 
*/	
	OC_Init.TIM_OCMode = TIM_OCMode_PWM1;//输出模式
	OC_Init.TIM_OutputState = ENABLE;				//输出使能
	OC_Init.TIM_OCPolarity = TIM_OCPolarity_High;	//输出极性
//	OC_Init.TIM_OutputNState = DISABLE;			//互补通道输出使能,高级定时器
//	OC_Init.TIM_OCIdleState = TIM_OCIdleState_Set;//高级定时器
//	OC_Init.TIM_OCNIdleState = TIM_OCNIdleState_Set;//高级定时器
//	OC_Init.TIM_OCNPolarity = TIM_OCPolarity_Low; //互补通道输出的极性，高级定时器
//	OC_Init.TIM_Pulse = 50;//设置初始占空比50%
	TIM_OC1Init(TIM3, &OC_Init);		//TIM3_CH1输出
	TIM_OC2Init(TIM3, &OC_Init);		//TIM3_CH2输出与CH1相反
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);

//	TIM_CtrlPWMOutputs(TIM1, ENABLE);			//高级定时器必须使能
    TIM_Cmd(TIM3, ENABLE); 
}
/*
void TIM3_IRQHandler(void)   
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
    {
        RED_LED = !RED_LED;			//PA7
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);    //清除TIM7更新中断标志
    }
}
*/



