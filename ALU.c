#include "ALU.h"
#include "banderas.h"

void add(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *Rl)	//funcion de la suma aritmetica
{
	*Rp=Rm+Rn;
    banderas(*Rp,Rm,Rn,Rl);
}
void And(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *Rl)	//funcion de la multiplicacion logica
{
	*Rp=Rm&Rn;
	banderas(*Rp,Rm,Rn,Rl);
}
void eor(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *Rl)	//funcion de la suma logica exclusiva
{
	*Rp=Rm^Rm;
	banderas(*Rp,Rm,Rn,Rl);
}
void mov(uint32_t *Rp, uint32_t Rm)				//funcion para mover un fichero a otra direccion
{
	*Rp=Rm;
}
void orr(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *Rl)	//funcion de la suma logica
{
	*Rp=Rm|Rn;
	banderas(*Rp,Rm,Rn,Rl);
}
void sub(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *Rl)	//funcion de la resta aritmetica
{
	*Rp=Rm-Rn;
	banderas(*Rp,Rm,Rn,Rl);
}
