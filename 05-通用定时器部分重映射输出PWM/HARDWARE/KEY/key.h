#ifndef __KEY_H
#define __KEY_H
#include "sys.h"

//K1-PA0 K2-PA1

#define K1 PAin(0)
#define K2 PAin(1)

void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8);    //按键扫描函数


#endif
