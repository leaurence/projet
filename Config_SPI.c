#include <c8051f020.h>
#include "Config_SPI.h"
#include "intrins.h"
#include <string.h>

void Config_SPI(void){
	
	SPI0CFG=0x87; // Configuration de registre
	SPI0CN=0x01; //On active la SPI en slave
	SPI0CKR=0x36; //pour avoir fSCK = 200 kHz
	SPIF=0; //Drapeau de fin de transmission activé (pour pouvoir débuter une autre transmission)

}

char putcharSPI(char c) {
	SPI0DAT = c; // mise de caractere dans la memoire
	return c;
}

char getcharSPI(){
	char caractererecu;
	if (SPIF==0)  //Si le drapeau d'interruption n'est pas prêt (si réception pas terminéé)
		return 0;
	else{
		caractererecu=SPI0DAT; // recuperation du caractere recu
		SPIF=0;
		return caractererecu;
	}
}

char test(void){	
	int j=0;
	char chainerecu[200];
	
	if (SPIF==1){	
		chainerecu[j]=getcharSPI();
		putcharSPI(chainerecu[j]);
		j++;
	}
	return 0;
}

