#include <math.h>
#include "InstruccionesDesplazamiento.h"
#include "banderas.h"

void LSLS(uint32_t *Rnd, uint32_t Rm, char *Rl)   //Desplazamiento logico a la izquierda.
{
	*Rnd=*Rnd*pow(2,Rm);
	banderas(*Rnd,0,0,Rl);
}

void LSRS(uint32_t *Rnd, uint32_t Rm, char *Rl)     //Desplazamiento logico a la derecha.
{
	*Rnd=*Rnd/(pow(2,Rm));
	banderas(*Rnd,0,0,Rl);
}

void ROR(uint32_t *Rnd, uint32_t Rm, char *Rl)      // Funcion para rotar registro a la derecha.
{
	uint32_t Raux1, Raux2;                          // Defino variables auxiliares
	Raux2=*Rnd*pow(2,(32-Rm));                      // Muevo a la izquierda 32-Rm posiciones
	Raux1=*Rnd/(pow(2,Rm));                         // Muevo a la derecha Rm posiciones
	*Rnd=Raux1+Raux2;
	banderas(*Rnd,0,0,Rl);
}

void ASRS(uint32_t *Rnd, uint32_t Rm, char *Rl)
{
	int32_t b;
	b=(int32_t)(*Rnd);
	b=b/(pow(2,Rm));
	*Rnd=(uint32_t)(b);
	banderas(*Rnd,0,0,Rl);
}
