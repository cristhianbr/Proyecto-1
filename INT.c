#include <stdint.h>
#include <stdlib.h>
#include "INT.h"

void INT(uint8_t *irq, uint32_t *reg, uint8_t *MemRam, char *flags, uint8_t *m)
{
    uint8_t i;
    for(i=0;i<=15;i++)
    {
        if((irq[i]==1)&&(m==0))
        {
            m=1;
            PUSH_INT(reg,MemRam,flags);
            reg[15]=i+1;
            reg[14]=0xfffffff;
            break;
        }
    }
    if(reg[15]==0xfffffff)
    {
        m=0;
        POP_INT(reg,MemRam,flags);
    }
}
