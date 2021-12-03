#ifndef BSP_SG90_H
#define BSP_SG90_H

#include "tim.h"

void setSG90Angle(TIM_HandleTypeDef* htim, uint32_t channel, uint8_t angle);

#endif
