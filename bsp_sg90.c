#include "bsp_sg90.h"

#define COUNT_PERIOD	20000		/* PWMһ�����ڼ���ֵ������Ϊ20000 */
#define CYCLETIME		20			/* һ�����ڶ���ms������Ϊ20 */

//����SG90Ϊ������Χ��(0~180��)�������
/*
* htim:Ҫ���õĶ�ʱ�����
* Channel��PWM���ͨ��
*
*/
void setSG90Angle(TIM_HandleTypeDef* htim, uint32_t channel, uint8_t angle)
{
	uint16_t compare_value=0;
	if(angle<=180)
	{
		//�Ƕ�ת��Ϊ��ֵ
		compare_value=0.5 * COUNT_PERIOD / CYCLETIME + angle * COUNT_PERIOD / CYCLETIME / 90;
		__HAL_TIM_SET_COMPARE(htim, channel, compare_value);
	}
}
