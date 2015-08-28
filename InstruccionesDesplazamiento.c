#include <math.h>
#include "InstruccionesDesplazamiento.h"
void LSLS(uint32_t *Rnd, uint32_t Rm) //Desplazamiento logico a la izquierda.
{
	*Rnd=*Rnd*pow(2,Rm);
}

void LSLS(uint32_t *Rnd, uint32_t Rm) //Desplazamiento logico a la derecha.
{
	*Rnd=*Rnd/pow(2,Rm);
}

void ROR(uint32_t *Rdn, uint32_t Rm) // Funcion para rotar registro a la derecha.
{
	uint32_t Raux1, Raux2;   // Defino variables auxiliares
	R1=*Rnd/pow(2,Rm);       // Muevo a la derecha Rm posiciones
	R2=*Rnd*pow(2,(32-Rm));  // Muevo a la izquierda 32-Rm posiciones
	*Rnd=R1+R2;              
}

void ASRS(uint32_t *Rdn, uint32_t Rm);
{
	
}