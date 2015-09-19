#include "banderas.h"
#define N 0
#define Z 1
#define C 2
#define V 3


void B(uint32_t *reg, int inm)// Esta funcion envia al PC a una direccion inmediata
{
    reg[15]+=inm;
}

void BEQ(uint32_t *reg, int inm, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta activa de lo contrario solo va a la siguiente instruccion
{
    if(flags[Z]=='1')
        reg[15]+=inm;
    else
        reg[15]+=1;
}

void BNE(uint32_t *reg, int inm, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta inactiva de lo contrario solo va a la siguiente instruccion
{
    if(flags[Z]=='0')
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BCS(uint32_t *reg, int inm, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de carry esta activa de lo contrario solo va a la siguiente instruccion
{
    if(flags[C]=='1')
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BCC(uint32_t *reg, int inm, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta inactiva de lo contrario solo va a la siguiente instruccion
{
    if(flags[C]=='0')
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BMI(uint32_t *reg, int inm, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de negativo esta activa de lo contrario solo va a la siguiente instruccion
{
    if(flags[N]=='1')
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BPL(uint32_t *reg, int inm, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de negativo esta inactiva de lo contrario solo va a la siguiente instruccion
{
    if(flags[N]=='0')
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BVS(uint32_t *reg, int inm, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de sobre flujo esta activa de lo contrario solo va a la siguiente instruccion
{
    if(flags[V]=='1')
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BVC(uint32_t *reg, int inm, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de sobre flujo esta inactiva de lo contrario solo va a la siguiente instruccion
{
    if(flags[V]=='0')
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BHI(uint32_t *reg, int inm, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta inactiva y la bandera de carry activa de lo contrario solo va a la siguiente instruccion
{
    if((flags[C]=='1')&&(flags[Z]=='0'))
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BLS(uint32_t *reg, int inm, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta activa o la bandera de carry inactiva de lo contrario solo va a la siguiente instruccion
{
    if((flags[C]=='0')||(flags[Z]=='1'))
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BGE(uint32_t *reg, int inm, char *flags)// Esta funcion envia al PC a una direccion inmediata si las banderas de negativo y sobre flujo estan activas o inactivas al mismo tiempo de lo contrario solo va a la siguiente instruccion
{
    if(flags[N]==flags[V])
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BLT(uint32_t *reg, int inm, char *flags)// Esta funcion envia al PC a una direccion inmediata si las banderas de negativo y sobre flujo se encuentran en estados diferentes es decir una activa y la otra inactiva y viceversa de lo contrario solo va a la siguiente instruccion
{
    if(flags[N]!=flags[V])
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BGT(uint32_t *reg, int inm, char *flags)//Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta inactiva y la bandera de negatvo esta en el mismo estado de la de sobre flujo de lo contrario solo va a la siguiente instruccion
{
    if((flags[Z]=='0')&&(flags[N]==flags[V]))
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BLE(uint32_t *reg, int inm, char *flags)//Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta inactiva o la bandera de negatvo esta en el un estado diferente de la de sobre flujo de lo contrario solo va a la siguiente instruccion
{
    if((flags[Z]=='0')||(flags[N]!=flags[V]))
        reg[15]+=inm;

    else
        reg[15]+=1;

}

void BLA(uint32_t *reg, int inm)// Esta funcion envia al PC a una direccion inmediata
{
    reg[15]+=inm;

}

void BL(uint32_t *reg, uint32_t *reg2, int inm)//Esta funcion envia al PC a una direccion inmediata y manda al LR a la siguiente instruccion teniendo en cuenta la consideracion de que PC emplea 32 bits
{
    *reg+=inm;
    *reg2+=2;
}

void BX(uint32_t *reg, uint32_t Rm)
{
    reg[15]=Rm;//Esta funcion guardo el contenido de un registro en el PC
}

void BLX(uint32_t *reg, uint32_t *reg2, uint32_t Rm)//Esta funcion guardo el contenido de un registro en el PC y pone a LR en la siguiente instruccion teniendo en cuenta la consideracion de que PC emplea 32 bits
{
    *reg=Rm;
    *reg2+=2;
}


