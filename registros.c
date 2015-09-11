#include "registros.h"
#include <stdint.h>
#include <curses.h>

void mostrar_registro(uint32_t *reg)
{
	int i;
	for(i=0;i<=12;i++)          //se crea un ciclo for para dar valores a los registros y mostrar los registros en pantalla
	{
		move(4+i, 15);
		printw("R%d:\t%.5d\n", i,reg[i]);
	}
    refresh();
}
