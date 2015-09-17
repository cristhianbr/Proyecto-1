#include "ALU.h"
#include "banderas.h"

void ADD(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la suma aritmetica
{
	*Rp=Rm+Rn;
    banderas(*Rp,Rm,Rn,flag);
}
void AND(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la multiplicacion logica
{
	*Rp=Rm&Rn;
	banderas(*Rp,Rm,Rn,flag);
}
void EOR(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la suma logica exclusiva
{
	*Rp=Rm^Rm;
	banderas(*Rp,Rm,Rn,flag);
}
void MOV(uint32_t *Rp, uint32_t Rm)			            	//funcion para mover un fichero a otra direccion
{
	*Rp=Rm;
}
void ORR(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la suma logica
{
	*Rp=Rm|Rn;
	banderas(*Rp,Rm,Rn,flag);
}
void SUB(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la resta aritmetica
{
	*Rp=Rm-Rn;
	banderas(*Rp,Rm,Rn,flag);
}
