#ifndef __LED_H
#define __LED_H
#include "sys.h"

#define RED_LED PAout(7)
#define BLUE_LED PAout(6)

#define RED_ON  RED_LED=0
#define RED_OFF RED_LED=1

#define BLUE_ON  BLUE_LED=0
#define BLUE_OFF BLUE_LED=1

void LED_Init(void);//≥ı ºªØ
void LED_Set(u8 led, u8 state);


#endif
