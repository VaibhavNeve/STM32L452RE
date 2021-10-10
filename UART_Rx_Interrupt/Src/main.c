/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * This code implements to receive data from USART2 (in interrupt mode) &
 * transmit back the data when data reception completed
 * End of reception is consider when user press Enter Key from  PC keyboard
 *
 ******************************************************************************
 ******************************************************************************
 ******************************************************************************/

#include <stm32l452xx.h>
#include "main.h"
int RxBufferPtr = 0, DataBufferPtr = 0 ;

char Rx_Data, Rx_DataBuffer[50];

int main(void)
{

	/* This Program use MSI(4MHz) Default Clock Source as a SYSCLK */


	RCC->AHB2ENR |= 0x01;			/* Clock source for GPIOA */


	RCC->APB1ENR1 |= (1 << 17);		/* Clock Source for USART2 */


	GPIO_Setup();					/* GPIO Setup */


	UART_Handler();					/* UART Handler */


	NVIC_EnableIRQ(USART2_IRQn);	/* Interrupt Enable */

	while(1)
	{

		if(Rx_Data == '\n')			/* Check if Enter Key pressed by user */
		{
			Rx_Data = RESET;
			RxBufferPtr = RESET;
			Transmit_Buffer(Rx_DataBuffer, sizeof(Rx_DataBuffer));	/* Transmit back received data */
			memset(Rx_DataBuffer, 0, sizeof(Rx_DataBuffer));		/* Clear receive data buffer */
		}
	}
	return 0;
}

void UART_Handler(void)
{

	USART2->CR1 |= (0x03 << 2); 	/* To set bit RE in CR1 (Receiver enable) */

	USART2->CR1 |= (0x01 << 5); 	/* To set bit RXNEIE (RXNE interrupt enable) */

	USART2->BRR = 0x1A0;   			/* 4MHz/9600 = 0x1A0,  4MHz because after reset SYSCLK is MSI(4MHz) By default */
	USART2->CR1 |= (1 << 0); 		/* to make UE bit 1. Should keep at last after all UART related setting */
	USART2 -> CR2 |= USART_CR2_CLKEN;

	/* Keeping other settings default */

}


void UART_Transmit(char Char)
{
	USART2->TDR = Char;

	while((USART2 -> ISR & USART_ISR_TC) == 0);

}

void Transmit_Buffer(char Buffer[],int length)
{
	for(i=0; i<length; i++)
	{
		UART_Transmit(Buffer[i]);
	}
}

void GPIO_Setup(void)
{
	/* Set PA2 & PA3 as alternate functionality mode */
	GPIOA->MODER &= ~(1 << 4);
	GPIOA->MODER &= ~(1 << 6);

	/* Alter. functionality as pins assigned for Tx & Rx */
	GPIOA->AFR[0] |= (7 << 8);
	GPIOA->AFR[0] |= (7 << 12);

	//GPIO Speed
	GPIOA->OSPEEDR |= (2 << 4);
	GPIOA->OSPEEDR |= (2 << 6);
}


void USART2_IRQHandler(void)
{
	if (USART2 -> ISR & USART_ISR_RXNE)
	{
		/* Read Data Register Not Empty */
		USART2 -> ISR &= ~USART_ISR_RXNE;
		Rx_Data = USART2 -> RDR;
		Rx_DataBuffer[RxBufferPtr++] = Rx_Data;
	}
}
