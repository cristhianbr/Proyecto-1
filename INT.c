#include <stdint.h>
#include <stdlib.h>
#include "INT.h"

void INT(uint8_t *irq, uint32_t *reg, uint8_t *MemRam, char *flags, uint8_t *m)//Funcion para cargar los registros y banderas en la memoria Ram cuando se ejecuta una interrupcion.
{
    int i;
    if(*m==1)
    {
        if(reg[15]==0xffffffff)
        {
            *m=0;
            POP_INT(reg,MemRam,flags);
        }
    }
    else
    {
        for(i=0;i<16;i++)
        {
            if(irq[i] == 1)
            {
                PUSH_INT(reg,MemRam,flags);
                reg[15]=i+1;
                irq[i]=0;
                reg[14]=0xffffffff;
                *m=1;
                break;
            }
        }
    }
}
