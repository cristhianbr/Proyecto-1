#include "mostrarRAM.h"
#include <stdint.h>
#include "curses.h"

void mostrar_ram(uint8_t *MemRAM)
{
    int i,j,k=0,a=22,b=-5;
	for(i=0;i<256;i+=64)          //se crea un ciclo for para dar valores a la memoria Ram en pantalla
	{
		b+=20;
		for(j=0;j<64;j+=4)
        {
            for(k=0;k<4;k++)
            {
                move((a+(j/4)),b);
                printw("0x%.2X = ",(i+j+k));
                move((a+(j /4)),(b+7+(k*3)));
                printw("%.2X",MemRAM[i+j+k]);
            }
        }
	}
    refresh();
}
