#include <stdio.h>
#include <stdlib.h>
#include "registros.h"
#include "ALU.h"
#include "banderas.h"
#include <stdint.h>

int main(void)
{
	uint32_t reg[13];           //se creo un arreglo de 13 variables de 32 bits para los 13 registros
	char bandera[4];            //La bandera se definio como un arreglo de 4 variables siendo la primera la bandera de negativo
	mostrar_registro(reg);      //la segunda la bandera de cero, la tercera la bandera del acarreo y la ultima variable la bandera del sobreflujo
	And(&reg[4],reg[2],reg[3],bandera);
	printf("Res:\t%d\nBanderas:\nN:%d\nZ:%d\nC:%d\nS:%d\n",reg[1],bandera[0],bandera[1],bandera[2],bandera[3]);
    LSRS(&reg[10],1,bandera);
    printf("\nLSLS:\t%d",reg[10]);
    printf("\nBanderas:\nN:%d\nZ:%d\nC:%d\nS:%d\n",bandera[0],bandera[1],bandera[2],bandera[3]);
    ROR(&reg[1],1,bandera);
    printf("\nROR:\t%d",reg[1]);
    printf("\nBanderas:\nN:%d\nZ:%d\nC:%d\nS:%d\n",bandera[0],bandera[1],bandera[2],bandera[3]);
	return 0;
}
