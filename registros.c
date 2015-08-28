#include "registros.h"
#include <stdint.h>

void mostrar_registro(uint32_t *reg)
{
	int i;
	for(i=0;i<=12;i++)
	{
		printf("R%d: %d\n", i,reg[i]);
	}
}
