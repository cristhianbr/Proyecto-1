#include <stdint.h>
#include <stdlib.h>
#include "ramtest.h"

void PUSH(uint32_t *regs, uint8_t *MemRAM, uint8_t *Reg)//Funcion para guardar el contenido de registros en la memoria Ram.
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
            address=address+4;
        }
    }
    regs[13]=regs[13]-(j*4);
}

void POP(uint32_t *regs, uint8_t *MemRAM, uint8_t *Reg)//Funcion para sacar contenidos de la memoria Ram.
{
    int i,j=0;
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
            regs[i]=((MemRAM[address]) | (MemRAM[address+1]<<8) | (MemRAM[address+2]<<16) | (MemRAM[address+3]<<24));
            address=address+4;
        }
    }
    regs[13]=regs[13]+(j*4);
}
void PUSH_INT(uint32_t *regs, uint8_t *MemRAM, char *flags)//Funcion para guardar contenidos de registros en la memoria Ram y guardar las banderas.
{
    uint32_t address;
    address=regs[13]-44;
    MemRAM[address]=(regs[0]);  MemRAM[address+1]=(regs[0]>>8);     MemRAM[address+2]=(regs[0]>>16);    MemRAM[address+3]=(regs[0]>>24);    address=address+4;
    MemRAM[address]=(regs[1]);  MemRAM[address+1]=(regs[1]>>8);     MemRAM[address+2]=(regs[1]>>16);    MemRAM[address+3]=(regs[1]>>24);    address=address+4;
    MemRAM[address]=(regs[2]);  MemRAM[address+1]=(regs[2]>>8);     MemRAM[address+2]=(regs[2]>>16);    MemRAM[address+3]=(regs[2]>>24);    address=address+4;
    MemRAM[address]=(regs[3]);  MemRAM[address+1]=(regs[3]>>8);     MemRAM[address+2]=(regs[3]>>16);    MemRAM[address+3]=(regs[3]>>24);    address=address+4;
    MemRAM[address]=(regs[12]); MemRAM[address+1]=(regs[12]>>8);    MemRAM[address+2]=(regs[12]>>16);   MemRAM[address+3]=(regs[12]>>24);   address=address+4;
    MemRAM[address]=(regs[14]); MemRAM[address+1]=(regs[14]>>8);    MemRAM[address+2]=(regs[14]>>16);   MemRAM[address+3]=(regs[14]>>24);   address=address+4;
    MemRAM[address]=(regs[15]); MemRAM[address+1]=(regs[15]>>8);    MemRAM[address+2]=(regs[15]>>16);   MemRAM[address+3]=(regs[15]>>24);   address=address+4;
    MemRAM[address]=(flags[0]); MemRAM[address+1]=(flags[0]>>8);    MemRAM[address+2]=(flags[0]>>16);   MemRAM[address+3]=(flags[0]>>24);   address=address+4;
    MemRAM[address]=(flags[1]); MemRAM[address+1]=(flags[1]>>8);    MemRAM[address+2]=(flags[1]>>16);   MemRAM[address+3]=(flags[1]>>24);   address=address+4;
    MemRAM[address]=(flags[2]); MemRAM[address+1]=(flags[2]>>8);    MemRAM[address+2]=(flags[2]>>16);   MemRAM[address+3]=(flags[2]>>24);   address=address+4;
    MemRAM[address]=(flags[3]); MemRAM[address+1]=(flags[3]>>8);    MemRAM[address+2]=(flags[3]>>16);   MemRAM[address+3]=(flags[3]>>24);   address=address+4;
    regs[13]=regs[13]-44;
}
void POP_INT(uint32_t *regs, uint8_t *MemRAM, char *flags)//Funcion para sacar contenidos de la memoria Ram y guardar las banderas.
{
    uint32_t address;
    address=regs[13];
    regs[0] =(MemRAM[address]) | (MemRAM[address+1]<<8) | (MemRAM[address+2]<<16) | (MemRAM[address+3]<<24); address=address+4;
    regs[1] =(MemRAM[address]) | (MemRAM[address+1]<<8) | (MemRAM[address+2]<<16) | (MemRAM[address+3]<<24); address=address+4;
    regs[2] =(MemRAM[address]) | (MemRAM[address+1]<<8) | (MemRAM[address+2]<<16) | (MemRAM[address+3]<<24); address=address+4;
    regs[3] =(MemRAM[address]) | (MemRAM[address+1]<<8) | (MemRAM[address+2]<<16) | (MemRAM[address+3]<<24); address=address+4;
    regs[12]=(MemRAM[address]) | (MemRAM[address+1]<<8) | (MemRAM[address+2]<<16) | (MemRAM[address+3]<<24); address=address+4;
    regs[14]=(MemRAM[address]) | (MemRAM[address+1]<<8) | (MemRAM[address+2]<<16) | (MemRAM[address+3]<<24); address=address+4;
    regs[15]=(MemRAM[address]) | (MemRAM[address+1]<<8) | (MemRAM[address+2]<<16) | (MemRAM[address+3]<<24); address=address+4;
    flags[0]=(MemRAM[address]) | (MemRAM[address+1]<<8) | (MemRAM[address+2]<<16) | (MemRAM[address+3]<<24); address=address+4;
    flags[1]=(MemRAM[address]) | (MemRAM[address+1]<<8) | (MemRAM[address+2]<<16) | (MemRAM[address+3]<<24); address=address+4;
    flags[2]=(MemRAM[address]) | (MemRAM[address+1]<<8) | (MemRAM[address+2]<<16) | (MemRAM[address+3]<<24); address=address+4;
    flags[3]=(MemRAM[address]) | (MemRAM[address+1]<<8) | (MemRAM[address+2]<<16) | (MemRAM[address+3]<<24); address=address+4;
    regs[13]=regs[13]+44;
}
