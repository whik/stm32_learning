#include "key.h"
#include "sys.h"
#include "delay.h"
//K1-PA0 K2-PA1

//������ʼ������
void KEY_Init(void) //IO��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

}
//K1-PA0 K2-PA1

//0 ��Чһ�Σ�1֧������
//����ֵ1-K1,2-K2,0-��
u8 KEY_Scan(u8 mode)
{
    static u8 key_up = 1; //�������ɿ���־
    if (mode)key_up = 1; //֧������
    if (key_up && (K1 == 0 || K2 == 0))
    {
        delay_ms(10);//ȥ����
        key_up = 0;
        if (K1 == 0)
            return 1;
        else if (K2 == 0)
            return 2;
    }
    else if (K1 == 1 && K2 == 1)key_up = 1;
    return 0;// �ް�������
}
