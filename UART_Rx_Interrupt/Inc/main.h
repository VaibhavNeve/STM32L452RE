/*
 * main.h
 *
 *  Created on: 28-Mar-2021
 *      Author: Vaibhav Neve
 */

#ifndef MAIN_H_
#define MAIN_H_
#include "string.h"

#define SET		1
#define RESET	0

void UART_Handler(void);
void UART_Transmit(char Char);
int i;
void Transmit_Buffer(char Buffer[],int length);
void GPIO_Setup(void);

#endif /* MAIN_H_ */
