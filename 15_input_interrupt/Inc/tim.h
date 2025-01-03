/*
 * tim.h
 *
 *  Created on: Dec 27, 2024
 *      Author: Admin
 */

#ifndef TIM_H_
#define TIM_H_
#define SR_UIF			(1U<<0)
#define SR_CC1IF				(1U<<0)
void tim2_1hz_init();
void tim2_PA15_output_compare();
void tim3_PA6_input_compare();

#endif /* TIM_H_ */
