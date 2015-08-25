#include "ALU.h"

void add(unsigned long int *Rp, unsigned long int Rm, unsigned long int Rn)	//funcion de la suma aritmetica
{
	*Rp=Rm+Rn;
}
void and(unsigned long int *Rp, unsigned long int Rm, unsigned long int Rn)	//funcion de la multiplicacion logica
{
	*Rp=Rm&Rn;
}
void eor(unsigned long int *Rp, unsigned long int Rm, unsigned long int Rn)	//funcion de la suma logica exclusiva
{
	*Rp=Rm^Rm;
}
void mov(unsigned long int *Rp, unsigned long int Rm)				//funcion para mover un fichero a otra direccion
{
	*Rp=Rm;
}
void orr(unsigned long int *Rp, unsigned long int Rm, unsigned long int Rn)	//funcion de la suma logica
{
	*Rp=Rm|Rn;
}
void sub(unsigned long int *Rp, unsigned long int Rm, unsigned long int Rn)	//funcion de la resta aritmetica
{
	*Rp=Rm-Rn;
}