#include <stdint.h>
#include <stdlib.h>

uint32_t address=0;


void LDR(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram)//Funcion para cargar contenidos de 4 posiciones de la memoria Ram.
{
    address=Rm+Rn;
    *Rt=Ram[address+3]<<24;
    *Rt=(*Rt)|(Ram[address+2]<<16);
    *Rt=(*Rt)|(Ram[address+1]<<8);
    *Rt=(*Rt)|(Ram[address]);
}

void LDRB(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram)//Funcion para cargar contenido de una posicion de la memoria Ram.
{
    address=Rm+Rn;
    *Rt=(uint32_t) (Ram[address]);
}

void LDRH(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram)//Funcion para cargar contenidos de 2 posiciones de la memoria Ram.
{
    address=Rm+Rn;
    *Rt=Ram[address];
    *Rt=(uint32_t)((*Rt)|(Ram[address+1]<<8));
}

void LDRSB(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram)//Funcion para cargar contenido de una posicion de la memoria Ram y hacer extension de signo.
{
    uint32_t Aux, Aux2, Aux3=~0;

    address=Rm+Rn;
    *Rt=Ram[address];
    Aux=(uint8_t)(*Rt);
    Aux2=Aux>>7;

	if(Aux2==1)
    {
		Aux3=(Aux3<<8);
        *Rt=(Aux)|(Aux3);
    }
	else
		*Rt=Ram[address];
}

void LDRSH(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram)//Funcion para cargar contenidos de 2 posiciones de la memoria Ram y hacer extension.

{
    uint32_t Aux, Aux2,Aux3=~0;

    address=Rm+Rn;
    *Rt=Ram[address];
    address=(*Rt)|Ram[address+1];
    Aux=(uint16_t)(*Rt);
    Aux2=Aux>>15;

	if(Aux2==1)
		{
		Aux3=(Aux3<<16);
		*Rt=(Aux)|(Aux3);
		}
	else
		*Rt=address;

}


void STR(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram)//Funcion para almacenar 4 bytes en la memoria Ram.
{
    address=Rm+Rn;
    Ram[address+3]=(uint8_t)(*Rt>>24);
    Ram[address+2]=(uint8_t)(*Rt>>16);
    Ram[address+1]=(uint8_t)(*Rt>>8);
    Ram[address]=(uint8_t)(*Rt);

}

void STRB(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram)//Funcion para almacenar 1 byte en la memoria Ram.
{
    address=Rm+Rn;
    Ram[address]=(uint8_t)(*Rt);
}

void STRH(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram)//Funcion para almacenar 2 bytes en la memoria Ram.

{
     Ram[address+1]=(uint8_t)(*Rt>>8);
     Ram[address]=(uint8_t)(*Rt);
}
