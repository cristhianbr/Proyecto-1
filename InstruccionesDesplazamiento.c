#include "InstruccionesDesplazamiento.h"
#include "banderas.h"
#define C 2
#define V 3

void LSLS(uint32_t *Rnd, uint32_t Rm, uint32_t Rn, char *flag)   //Desplazamiento logico a la izquierda, actualiza banderas.
{
	*Rnd=Rm<<Rn;
	if(((1<<(32-Rn))&Rm)&&(Rn!=0))  {   flag[C]=1;  }
	else    {   flag[C]=0;  }
	banderas(*Rnd,flag);
}
void LSRS(uint32_t *Rnd, uint32_t Rm, uint32_t Rn, char *flag)     //Desplazamiento logico a la derecha, actualiza banderas.
{
	*Rnd=Rm>>Rn;
	if(((1<<(Rn-1))&Rm)&&(Rn!=0))  {   flag[C]=1;  }
	else  {   flag[C]=0;  }
	banderas(*Rnd,flag);
}
void RORS(uint32_t *Rnd, uint32_t Rm, char *flag)      // Funcion para rotar registro a la derecha.
{
	uint32_t Raux1, Raux2;
	if(((1<<(Rm-1))&*Rnd)&&(Rm!=0))  {   flag[C]=1;  }
	else  {   flag[C]=0;  }                          // Defino variables auxiliares
	Raux2=*Rnd<<(32-Rm);                                                        // Muevo a la izquierda 32-Rm posiciones
	Raux1=*Rnd>>Rm;                                                             // Muevo a la derecha Rm posiciones
	*Rnd=Raux1+Raux2;
	banderas(*Rnd,flag);
}
void ASRS(uint32_t *Rnd, uint32_t Rm, char *flag) //Funcion Desplazamiento arcmetico a la derecha.
{
	int32_t b;
	if(((1<<(Rm-1))&*Rnd)&&(Rm!=0))  {   flag[C]=1;  }
	else  {   flag[C]=0;  }
	b=(int32_t)(*Rnd);
	b=b>>Rm;
	*Rnd=(uint32_t)(b);
	banderas(*Rnd,flag);
}
void BICS(uint32_t *Rnd, uint32_t Rm, char *flag) // AND entre el registro y el complemento del otro, actualiza banderas
{
	*Rnd&=~Rm;
	banderas(*Rnd,flag);
}
void MVNS(uint32_t *Rnd, uint32_t Rm, char *flag) //Funcion  que realiza el complemento de un registro
{
    *Rnd=~Rm;
    banderas(*Rnd,flag);
}
void CMN(uint32_t Rm, uint32_t Rn, char *flag) // Funcion que realiza una suma pero no guarda el resultado, solo modifica banderas
{
    uint32_t Rp;
    int32_t Rs;
    Rp=Rm+Rn;
    Rs=Rm+Rn;
    if(((Rn>=(1<<31))&&(Rm>=(1<<31)))||((Rm>=(1<<31))&&(Rn<(1<<31))&&(Rp<(1<<31)))||((Rn>=(1<<31))&&(Rm<(1<<31))&&(Rp<(1<<31))))
    {
        flag[C]=1;
    }
    else {  flag[C]=0;  }
    if (Rp==Rs)
    {
        flag[V]=1;
    }
    else {  flag[V]=0;  }
    banderas(Rp,flag);
}
void CMP(uint32_t Rm, uint32_t Rn, char *flag) // Funcion que realiza una resta pero no guarda el resultado, solo modifica banderas.
{
    uint32_t Rp;
    int32_t Rs;
    Rn=~Rn+1;
    Rp=Rm+Rn;
    Rs=Rm+Rn;
    if(((Rn>=(1<<31))&&(Rm>=(1<<31)))||((Rm>=(1<<31))&&(Rn<(1<<31))&&(Rp<(1<<31)))||((Rn>=(1<<31))&&(Rm<(1<<31))&&(Rp<(1<<31))))
    {
        flag[C]=1;
    }
    else {  flag[C]=0;  }
    if (Rp==Rs)
    {
        flag[V]=1;
    }
    else {  flag[V]=0;  }
    banderas(Rp,flag);
}
void RSBS(uint32_t *Rnd, uint32_t Rm, char *flag) // -Funcion que realiza el complemento de un registro
{
    *Rnd=(~Rm)+1;
    banderas(*Rnd,flag);
}
void REV(uint32_t *Rnd, uint32_t Rm) //Funcion que opera a nivel de bytes, revierte el orden de bytes en un registro de 32 bits.
{
    *Rnd=((Rm>>24)|(Rm<<24)|((Rm>>8)&(0x0000ff00))|((Rm<<8)&(0x00ff0000)));
}
void REV16(uint32_t *Rnd, uint32_t Rm) //Funcion que opera a nivel de bytes
{
    *Rnd=(((Rm>>8)&(0x00ff0000))|((Rm<<8)&(0xff000000))|((Rm>>8)&(0x000000ff))|((Rm<<8)&(0x0000ff00)));
}
void REVSH(uint32_t *Rnd, uint32_t Rm) //Funcion que guarda el primer byte con extencion de signo hasta completar los 32 bits.
{
    *Rnd=((Rm>>8)&(0x000000ff));
    if((1>>7)&Rm)
    {
        *Rnd=(1&0xfffffff00);
    }
    else
    {
        *Rnd=(0&0xfffffff00);
    }
}
void TST(uint32_t Rnd, uint32_t Rm,char *flag)
{
    Rnd&=Rm;
    banderas(Rnd,flag);
}
