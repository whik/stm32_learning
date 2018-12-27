#include "led.h"

//PA6-BLUE PA7-RED

void LED_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_SetBits(GPIOA, GPIO_Pin_6 | GPIO_Pin_7);
}

void LED_Set(u8 led, u8 state)
{
    if (led == 0)
    {
        switch (state)
        {
        case 0:
            RED_ON;
            break;
        case 1:
            RED_OFF;
            break;
        default:
            break;
        }
    }
    else
    {
        switch (state)
        {
        case 0:
            BLUE_ON;
            break;
        case 1:
            BLUE_OFF;
            break;
        default:
            break;
        }
    }
}


