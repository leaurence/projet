#include <c8051f020.h>
#include "Config_Global.h"
#include "Config_GPIO.h"
#include "Config_SPI.h"


void main()
{
	EA=0;
	
	Init_Device(); //on initialise les ports, le Sysclock et le reset
	Gestion_GPIO();
	//Init_PCA(); //on initialise le PCA
	Config_SPI();
	
	EA=1;	
	while(1){
		
		test();
}

}