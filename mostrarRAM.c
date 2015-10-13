#include "registros.h"
#include <stdint.h>
#include "curses.h"

void mostrar_ram(uint8_t *MemRAM)
{
    int i,j,k=0,a=20,b=15;
	for(i=0;i<=255;i+=16)          //se crea un ciclo for para dar valores a los registros y mostrar los registros en pantalla
	{
		b+=20;
		for(j=0;j<=15;j+=4)
        {
            move((a+(j/4)),b);
            printw("0x%.2X = ",(i+j+k));
            for(k=0;k<4;k++)
            {
                move((a+(j/4)),(b+7+(k*3)));
                printw("%.2X",MemRAM[i+j+k]);
            }
        }
	}
    refresh();
}

