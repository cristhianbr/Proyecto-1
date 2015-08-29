#include <math.h>
#include "InstruccionesDesplazamiento.h"

void LSLS(uint32_t *Rnd, uint32_t Rm)   //Desplazamiento logico a la izquierda.
{
	*Rnd=*Rnd*pow(2,Rm);
}

void LSRS(uint32_t *Rnd, uint32_t Rm)   //Desplazamiento logico a la derecha.
{
	*Rnd=*Rnd/(pow(2,Rm));
}

void ROR(uint32_t *Rnd, uint32_t Rm)    // Funcion para rotar registro a la derecha.
{
	uint32_t Raux1, Raux2;              // Defino variables auxiliares
	Raux2=*Rnd*pow(2,(32-Rm));          // Muevo a la izquierda 32-Rm posiciones
	Raux1=*Rnd/(pow(2,Rm));              // Muevo a la derecha Rm posiciones
	*Rnd=Raux1+Raux2;
}

void ASRS(uint32_t *Rdn, uint32_t Rm)
{
	int32_t b;
	b=(int32_t)(*Rdn);
	b=b/(pow(2,Rm));
	Rdn=(uint32_t)(b);
}
