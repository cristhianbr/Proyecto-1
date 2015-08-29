#include "banderas.h"
#include <math.h>

void banderas(uint32_t Rp, uint32_t Rm, uint32_t Rn, char *Rl)
{
    if ((1<<31)&Rp)     //sentencia para la bandera que indica numero negativo
    {
        Rl[0]=1;
    }
    else
    {
        Rl[0]=0;
    }
    if (Rp==0)          //sentencia para la bandera que indica el numero cero
    {
        Rl[1]=1;
    }
    else
    {
        Rl[1]=0;
    }
    if (((((1<<31)&Rm)&&((1<<31)&Rn))&&((0<<31)&Rp))||((((1<<31)&Rm)||((1<<31)&Rn))&&((0<<31)&Rp)))
    {                    //sentencia para la bandera que indica un carry
        Rl[2]=1;
    }
    else
    {
        Rl[2]=0;
    }
    if  ((((1<<31)-1)&Rm)==(((1<<31)-1)&Rn))        //sentencia para la bandera que indica que hay un sobreflujo
    {
        if((((1<<31)-1)&Rm)!=((((1<<31)-1)&Rp)))
        {
            Rl[3]=1;
        }
    }
    else
    {
        Rl[3]=0;
    }
}
