#ifndef __BEEP_H
#define __BEEP_H


#include "sys.h"


//BEEP - PC5



#define BEEP     PCout(5)
#define BEEP_ON  BEEP=1
#define BEEP_OFF BEEP=0


void BEEP_Init(void);//≥ı ºªØ
void BEEP_Set(u8 state);


#endif
