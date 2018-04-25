#include <c8051f020.h>
#include "Config_Global.h"
#include "Config_GPIO.h"
#include "Config_SPI.h"

void Config_GPIO_Slave(void)
{
	P0=0xff;
	XBR1=0x80;//sysclk routed to port pin
	P1=0x03;
	P1MDOUT|=0x01;// P1.0 en PP
	P1MDOUT&=0x02;// P1.1 en OD pour Px.y->NSS
	P0MDOUT &=0x34; // P0.2(SCK) P0.5(NSS) P0.4(MOSI)en OD 
	P0MDOUT |=0x08; //P0.3(MISO)en PP
	XBR0 =0x06;// Activation UART et SPI
	XBR2 =0x44; // Activation UART1 et Crossbar
}

void Gestion_GPIO (void){
  Config_GPIO_Slave();
}