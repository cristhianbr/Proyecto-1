#include "registros.h"
#include <stdint.h>
#include "curses.h"

void mostrar_registro(uint32_t *reg)
{
	int i;
	move(4, 15); printw("Registros");
	for(i=0;i<=12;i++)          //se crea un ciclo for para dar valores a los registros y mostrar los registros en pantalla
	{
		move(6+i, 15);
		printw("R%d:\t%.10d\n", i,reg[i]);
	}
    refresh();
}
