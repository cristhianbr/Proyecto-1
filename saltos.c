#include "banderas.h"
#define N 0
#define Z 1
#define C 2
#define V 3


void B(uint32_t *reg, int salto)// Esta funcion envia al PC a una direccion inmediata
{
    *reg+=salto;
}

void BEQ(uint32_t *reg, int salto, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta activa de lo contrario solo va a la siguiente instruccion
{
    if(flags[Z]=='1')
        *reg+=salto;
    else
        *reg+=1;
}

void BNE(uint32_t *reg, int salto, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta inactiva de lo contrario solo va a la siguiente instruccion
{
    if(flags[Z]=='0')
        *reg+=salto;

    else
        *reg+=1;

}

void BCS(uint32_t *reg, int salto, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de carry esta activa de lo contrario solo va a la siguiente instruccion
{
    if(flags[C]=='1')
        *reg+=salto;

    else
        *reg+=1;

}

void BCC(uint32_t *reg, int salto, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta inactiva de lo contrario solo va a la siguiente instruccion
{
    if(flags[C]=='0')
        *reg+=salto;

    else
        *reg+=1;

}

void BMI(uint32_t *reg, int salto, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de negativo esta activa de lo contrario solo va a la siguiente instruccion
{
    if(flags[N]=='1')
        *reg+=salto;

    else
        *reg+=1;

}

void BPL(uint32_t *reg, int salto, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de negativo esta inactiva de lo contrario solo va a la siguiente instruccion
{
    if(flags[N]=='0')
        *reg+=salto;

    else
        *reg+=1;

}

void BVS(uint32_t *reg, int salto, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de sobre flujo esta activa de lo contrario solo va a la siguiente instruccion
{
    if(flags[V]=='1')
        *reg+=salto;

    else
        *reg+=1;

}

void BVC(uint32_t *reg, int salto, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de sobre flujo esta inactiva de lo contrario solo va a la siguiente instruccion
{
    if(flags[V]=='0')
        *reg+=salto;

    else
        *reg+=1;

}

void BHI(uint32_t *reg, int salto, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta inactiva y la bandera de carry activa de lo contrario solo va a la siguiente instruccion
{
    if((flags[C]=='1')&&(flags[Z]=='0'))
        *reg+=salto;

    else
        *reg+=1;

}

void BLS(uint32_t *reg, int salto, char *flags)// Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta activa o la bandera de carry inactiva de lo contrario solo va a la siguiente instruccion
{
    if((flags[C]=='0')||(flags[Z]=='1'))
        *reg+=salto;

    else
        *reg+=1;

}

void BGE(uint32_t *reg, int salto, char *flags)// Esta funcion envia al PC a una direccion inmediata si las banderas de negativo y sobre flujo estan activas o inactivas al mismo tiempo de lo contrario solo va a la siguiente instruccion
{
    if(flags[N]==flags[V])
        *reg+=salto;

    else
        *reg+=1;

}

void BLT(uint32_t *reg, int salto, char *flags)// Esta funcion envia al PC a una direccion inmediata si las banderas de negativo y sobre flujo se encuentran en estados diferentes es decir una activa y la otra inactiva y viceversa de lo contrario solo va a la siguiente instruccion
{
    if(flags[N]!=flags[V])
        *reg+=salto;

    else
        *reg+=1;

}

void BGT(uint32_t *reg, int salto, char *flags)//Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta inactiva y la bandera de negatvo esta en el mismo estado de la de sobre flujo de lo contrario solo va a la siguiente instruccion
{
    if((flags[Z]=='0')&&(flags[N]==flags[V]))
        *reg+=salto;

    else
        *reg+=1;

}

void BLE(uint32_t *reg, int salto, char *flags)//Esta funcion envia al PC a una direccion inmediata si la bandera de cero esta inactiva o la bandera de negatvo esta en el un estado diferente de la de sobre flujo de lo contrario solo va a la siguiente instruccion
{
    if((flags[Z]=='0')||(flags[N]!=flags[V]))
        *reg+=salto;

    else
        *reg+=1;

}

void BLA(uint32_t *reg, int salto)// Esta funcion envia al PC a una direccion inmediata
{
    *reg+=salto;

}

void BL(uint32_t *reg, uint32_t *reg2, int salto)//Esta funcion envia al PC a una direccion inmediata y manda al RL a la siguiente instruccion teniendo en cuenta la consideracion de que PC emplea 32 bits
{
    *reg+=salto;
    *reg2+=2;
}

void BX(uint32_t *reg, uint32_t Rm)
{
    *reg=Rm;//Esta funcion guardo el contenido de un registro en el PC
}

void BLX(uint32_t *reg, uint32_t *reg2, uint32_t Rm)//Esta funcion guardo el contenido de un registro en el PC y pone a RL en la siguiente instruccion teniendo en cuenta la consideracion de que PC emplea 32 bits
{
    *reg=Rm;
    *reg2+=2;
}


