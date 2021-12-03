#include "bsp_sg90.h"

#define COUNT_PERIOD	20000		/* PWM一个周期计数值，这里为20000 */
#define CYCLETIME		20			/* 一个周期多少ms，这里为20 */

//设置SG90为参数范围内(0~180°)任意度数
/*
* htim:要设置的定时器句柄
* Channel：PWM输出通道
*
*/
void setSG90Angle(TIM_HandleTypeDef* htim, uint32_t channel, uint8_t angle)
{
	uint16_t compare_value=0;
	if(angle<=180)
	{
		//角度转化为数值
		compare_value=0.5 * COUNT_PERIOD / CYCLETIME + angle * COUNT_PERIOD / CYCLETIME / 90;
		__HAL_TIM_SET_COMPARE(htim, channel, compare_value);
	}
}
