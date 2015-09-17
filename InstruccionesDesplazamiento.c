#include "InstruccionesDesplazamiento.h"
#include "banderas.h"


void LSLS(uint32_t *Rnd, uint32_t Rm, char *flag)   //Desplazamiento logico a la izquierda, actualiza banderas.
{
	*Rnd=*Rnd<<Rm;
	banderas(*Rnd,0,0,flag);
}

void LSRS(uint32_t *Rnd, uint32_t Rm, char *flag)     //Desplazamiento logico a la derecha, actualiza banderas.
{
	*Rnd=*Rnd>>Rm;
	banderas(*Rnd,0,0,flag);
}

void RORS(uint32_t *Rnd, uint32_t Rm, char *flag)      // Funcion para rotar registro a la derecha.
{
	uint32_t Raux1, Raux2;                          // Defino variables auxiliares
	Raux2=*Rnd<<(32-Rm);          // Muevo a la izquierda 32-Rm posiciones
	Raux1=*Rnd>>Rm;              // Muevo a la derecha Rm posiciones                       // Muevo a la derecha Rm posiciones
	*Rnd=Raux1+Raux2;
	banderas(*Rnd,0,0,flag);
}

void ASRS(uint32_t *Rnd, uint32_t Rm, char *flag)
{
	int32_t b;
	b=(int32_t)(*Rnd);
	b=b>>Rm;
	*Rnd=(uint32_t)(b);
	banderas(*Rnd,0,0,flag);
}

void BICS(uint32_t *Rnd, uint32_t Rm, char *flag) // AND entre el registro y el complemento del otro, actualiza banderas
{
	*Rnd&=~Rm;
	banderas(*Rnd,0,0,flag);
}

void NOP()
{

}

void MVNS(uint32_t *Rnd, uint32_t Rm, char *flag)
{
    *Rnd=~Rm;
    banderas(*Rnd,0,0,flag);
}

void CMN(uint32_t Rm, uint32_t Rn, char *flag)
{
    Rm+=Rn;
    banderas(Rm,0,0,flag);
}

void CMP(uint32_t Rm, uint32_t Rn, char *flag)
{
    Rm-=Rn;
    banderas(Rm,0,0,flag);
}

void RSBS(uint32_t *Rnd, uint32_t Rm, char *flag)
{
    *Rnd=0-Rm;
    banderas(*Rnd,0,0,flag);
}

void REV(uint32_t *Rnd, uint32_t Rm,char *flag)
{
    *Rnd=((Rm>>24)|(Rm<<24)|((Rm>>8)&(0x0000ff00))|((Rm<<8)&(0x00ff0000)));
}

void REV16S(uint32_t *Rnd, uint32_t Rm,char *flag)
{
    *Rnd=(((Rm>>8)&(0x00ff0000))|((Rm<<8)&(0xff000000))|((Rm>>8)&(0x000000ff))|((Rm<<8)&(0x0000ff00)));
}

void REVSHS(uint32_t *Rnd, uint32_t Rm,char *flag)
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

void TST(uint32_t Rnd, uint32_t Rm1,char *flag)
{
Rnd&=Rm1;

	banderas(Rnd,0,0,flag);
}





