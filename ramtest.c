#include <stdint.h>
#include <stdlib.h>
#include "ramtest.h"

void PUSH(uint32_t *regs, uint8_t *MemRAM, uint8_t *Reg)
{
    int i,j=0;
    uint32_t address;

    for(i=0;i<16;i++)
    {
        if(Reg[i]==1)
        {
            j++;
        }
    }
    address=regs[13]-(j*4);
    for(i=0;i<16;i++)
    {
        if(Reg[i]==1)
        {
            MemRAM[address]=(regs[i]);
            MemRAM[address+1]=(regs[i]>>8);
            MemRAM[address+2]=(regs[i]>>16);
            MemRAM[address+3]=(regs[i]>>24);
        }
        address=address+4;
    }
    regs[13]=regs[13]-(j*4);
}

void POP(uint32_t *regs, uint8_t *MemRAM, uint8_t *Reg)
{
    int i,j;
    uint32_t address;
    for(i=0;i<16;i++)
    {
        if((Reg[i]==1))
        {
            j++;
        }
    }
    address=regs[13];
    for(i=0;i<16;i++)
    {
        if(Reg[i]==1)
        {
            regs[i]=(MemRAM[address])|(MemRAM[address+1]<<8)|(MemRAM[address+2]<<16)|(MemRAM[address+3]<<24);
        }
        address=address+4;
    }
    regs[13]=regs[13]+(j*4);
}

