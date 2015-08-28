#include <stdio.h>
#include <stdlib.h>
#include "registros.h"
#include "ALU.h"
#include "banderas.h"
#include <stdint.h>

int main(void)
{
	uint32_t reg[13];
	char bandera[4];
	mostrar_registro(reg);
	add(reg[1],reg[2],reg[3],bandera);
	return 0;
}
