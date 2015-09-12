#include "InstruccionesDesplazamiento.h"
#include "banderas.h"


void LSLS(uint32_t *Rnd, uint32_t Rm, char *Rl)   //Desplazamiento logico a la izquierda.
{
	*Rnd=*Rnd<<Rm;
	banderas(*Rnd,0,0,Rl);
}

void LSRS(uint32_t *Rnd, uint32_t Rm, char *Rl)     //Desplazamiento logico a la derecha.
{
	*Rnd=*Rnd>>Rm;
	banderas(*Rnd,0,0,Rl);
}

void ROR(uint32_t *Rnd, uint32_t Rm, char *Rl)      // Funcion para rotar registro a la derecha.
{
	uint32_t Raux1, Raux2;                          // Defino variables auxiliares
	Raux2=*Rnd<<(32-Rm);          // Muevo a la izquierda 32-Rm posiciones
	Raux1=*Rnd>>Rm;              // Muevo a la derecha Rm posiciones                       // Muevo a la derecha Rm posiciones
	*Rnd=Raux1+Raux2;
	banderas(*Rnd,0,0,Rl);
}

void ASRS(uint32_t *Rnd, uint32_t Rm, char *Rl)
{
	int32_t b;
	b=(int32_t)(*Rnd);
	b=b>>Rm;
	*Rnd=(uint32_t)(b);
	banderas(*Rnd,0,0,Rl);
}

void BICS(uint32_t *Rnd, uint32_t Rm, char *Rl) // AND entre el registro y el complemento del otro
{
	*Rnd&=~Rm;
	banderas(*Rnd,0,0,Rl);
}

void NOP()
{

}

void MVNS(uint32_t *Rnd, uint32_t Rm, char *Rl)
{
    *Rnd=~Rm;
    banderas(*Rnd,0,0,Rl);
}

void CMN(uint32_t Rm, uint32_t Rn, char *Rl)
{
    Rm+=Rn;
    banderas(Rm,0,0,Rl);
}

void CMP(uint32_t Rm, uint32_t Rn, char *Rl)
{
    Rm-=Rn;
    banderas(Rm,0,0,Rl);
}

void RSBS(uint32_t *Rnd, uint32_t Rm, char *Rl)
{
    *Rnd=0-Rm;
    banderas(*Rnd,0,0,Rl);
}

void REVS(uint32_t *Rnd, uint32_t Rm,char *Rl)
{
    *Rnd=((Rm>>24)|(Rm<<24)|((Rm>>8)&(0x0000ff00))|((Rm<<8)&(0x00ff0000)));
    banderas(Rnd,0,0,Rl);
}

void REV16S(uint32_t *Rnd, uint32_t Rm,char *Rl)
{
    *Rnd=(((Rm>>8)&(0x00ff0000))|((Rm<<8)&(0xff000000))|((Rm>>8)&(0x000000ff))|((Rm<<8)&(0x0000ff00)));
    banderas(Rnd,0,0,Rl);
}

void REVSHS(uint32_t *Rnd, uint32_t Rm,char *Rl)
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

     banderas(Rnd,0,0,Rl);
}

void TST(uint32_t Rnd, uint32_t Rm1,char *Rl)
{
Rnd&=Rm1;

	banderas(Rnd,0,0,Rl);
}





