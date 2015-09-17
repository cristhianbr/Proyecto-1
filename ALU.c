#include "ALU.h"
#include "banderas.h"

void add(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la suma aritmetica
{
	*Rp=Rm+Rn;
    banderas(*Rp,Rm,Rn,flag);
}
void And(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la multiplicacion logica
{
	*Rp=Rm&Rn;
	banderas(*Rp,Rm,Rn,flag);
}
void eor(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la suma logica exclusiva
{
	*Rp=Rm^Rm;
	banderas(*Rp,Rm,Rn,flag);
}
void mov(uint32_t *Rp, uint32_t Rm)			            	//funcion para mover un fichero a otra direccion
{
	*Rp=Rm;
}
void orr(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la suma logica
{
	*Rp=Rm|Rn;
	banderas(*Rp,Rm,Rn,flag);
}
void sub(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la resta aritmetica
{
	*Rp=Rm-Rn;
	banderas(*Rp,Rm,Rn,flag);
}
