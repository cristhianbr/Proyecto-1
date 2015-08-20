#include "registros.h"

void mostrar_registro(int reg[12]);
{
	int i;
	for(i=0;i<12;i++)
	{
		printf("R%d: %d\n", i, reg[i]); 
	}
}