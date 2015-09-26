#include "ALU.h"
#include "banderas.h"
#define C 2
#define V 3

void ADDS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la suma aritmetica
{
	*Rp=Rm+Rn;
	if(((Rn>=(1<<31))&&(Rm>=(1<<31)))||((Rm>=(1<<31))&&(Rn<(1<<31))&&(*Rp<(1<<31)))||((Rn>=(1<<31))&&(Rm<(1<<31))&&(*Rp<(1<<31))))
    {
        flag[C]=1;
    }
    else {  flag[C]=0;  }
    if(((2147483647<Rm)&&(2147483647<Rn)&&(2147483647>=*Rp))||((2147483647>=Rm)&&(2147483647>=Rm)&&(2147483647<*Rp)))
    {
        flag[V]=1;
    }
    else {  flag[V]=0;  }
    banderas(*Rp,flag);
}

void ADCS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)
{
    Rm+=flag[C];
    *Rp=Rm+Rn;
    if(((Rn>=(1<<31))&&(Rm>=(1<<31)))||((Rm>=(1<<31))&&(Rn<(1<<31))&&(*Rp<(1<<31)))||((Rn>=(1<<31))&&(Rm<(1<<31))&&(*Rp<(1<<31))))
    {
        flag[C]=1;
    }
    else {  flag[C]=0;  }
    if(((2147483647<Rm)&&(2147483647<Rn)&&(2147483647>=*Rp))||((2147483647>=Rm)&&(2147483647>=Rm)&&(2147483647<*Rp)))
    {
        flag[V]=1;
    }
    else {  flag[V]=0;  }
    banderas(*Rp,flag);
}

void ANDS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la multiplicacion logica
{
	*Rp=Rm&Rn;
	banderas(*Rp,flag);
}
void EORS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la suma logica exclusiva
{
	*Rp=Rm^Rm;
	banderas(*Rp,flag);
}
void MOVS(uint32_t *Rp, uint32_t Rm, char *flag)			            	//funcion para mover un fichero a otra direccion
{
	*Rp=Rm;
	banderas(*Rp,flag);
}
void MOV(uint32_t *Rp, uint32_t Rm)			            	//funcion para mover un fichero a otra direccion
{
	*Rp=Rm;
}
void ORRS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la suma logica
{
	*Rp=Rm|Rn;
	banderas(*Rp,flag);
}
void SUBS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la resta aritmetica
{
	Rn=~Rn+1;
	*Rp=Rm+Rn;
	if(((Rn>=(1<<31))&&(Rm>=(1<<31)))||((Rm>=(1<<31))&&(Rn<(1<<31))&&(*Rp<(1<<31)))||((Rn>=(1<<31))&&(Rm<(1<<31))&&(*Rp<(1<<31))))
    {
        flag[C]=1;
    }
    else {  flag[C]=0;  }
    if(((2147483647<Rm)&&(2147483647<Rn)&&(2147483647>=*Rp))||((2147483647>=Rm)&&(2147483647>=Rm)&&(2147483647<*Rp)))
    {
        flag[V]=1;
    }
    else {  flag[V]=0;  }
	banderas(*Rp,flag);
}
void MUL(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)	//funcion de la multiplicacion de dos registros
{
	*Rp=Rm*Rn;
	banderas(*Rp,flag);
}
void SBCS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag)
{
    Rn=~Rn+1;
    Rm+=flag[C];
    *Rp=Rm+Rn;
    if(((Rn>=(1<<31))&&(Rm>=(1<<31)))||((Rm>=(1<<31))&&(Rn<(1<<31))&&(*Rp<(1<<31)))||((Rn>=(1<<31))&&(Rm<(1<<31))&&(*Rp<(1<<31))))
    {
        flag[C]=1;
    }
    else {  flag[C]=0;  }
    if(((2147483647<Rm)&&(2147483647<Rn)&&(2147483647>=*Rp))||((2147483647>=Rm)&&(2147483647>=Rm)&&(2147483647<*Rp)))
    {
        flag[V]=1;
    }
    else {  flag[V]=0;  }
    banderas(*Rp,flag);
}
