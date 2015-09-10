#include "registros.h"
#include <stdint.h>
#include <curses.h>

void mostrar_registro(uint32_t *reg)
{
	int i;
	for(i=0;i<=12;i++)          //se crea un ciclo for para dar valores a los registros y mostrar los registros en pantalla
	{
		reg[i]=0+i;
		move(3+i, 15);	/* Mueve el cursor a la posición y=2, x=34*/
		printw("R%d:\t%d\n", i,reg[i]);
	}
    refresh();
}
