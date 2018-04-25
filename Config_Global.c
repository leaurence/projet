#include <c8051f020.h>
#include "Config_Global.h"


void oscillator_init (void)
{ 
	int i=0;
	OSCXCN = 0x67; // Crystal oscillator mode
	for (i = 0; i < 3000; i++)  // Wait for 1ms
	while ((OSCXCN & 0x80) == 0x00);  // Crystal oscillator valid flag check
	OSCICN = 0x08;  // Swicth from oscillator
}

void Reset_Sources_init(void)
{
	EA=0;
	WDTCN = 0xDE; // desactivation du watchdog
	WDTCN = 0xAD;
	//EA=1;
}



void Init_Device(void) //appel d'une fonction unique dans le main
{ 
	
	oscillator_init();
	Reset_Sources_init();
	
}