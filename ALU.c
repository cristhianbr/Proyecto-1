#include "ALU.h"

void add(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *Rl)	//funcion de la suma aritmetica
{
	*Rp=Rm+Rn;

    banderas(Rp,Rm,Rn,Rl);
}
void and(uint32_t *Rp,uint32_t Rm, uint32_t Rn)	//funcion de la multiplicacion logica
{
	*Rp=Rm&Rn;
}
void eor(uint32_t *Rp, uint32_t Rm, uint32_t Rn)	//funcion de la suma logica exclusiva
{
	*Rp=Rm^Rm;
}
void mov(uint32_t *Rp,  uint32_t Rm)				//funcion para mover un fichero a otra direccion
{
	*Rp=Rm;
}
void orr(uint32_t *Rp,  uint32_t Rm,  uint32_t Rn)	//funcion de la suma logica
{
	*Rp=Rm|Rn;
}
void sub(uint32_t *Rp,  uint32_t Rm,  uint32_t Rn)	//funcion de la resta aritmetica
{
	*Rp=Rm-Rn;
}
