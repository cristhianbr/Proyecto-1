#include "banderas.h"
#include <math.h>

void banderas(uint32_t Rp, uint32_t Rm, uint32_t Rn, char *Flags)
{
    if ((1<<31)&Rp)     //sentencia para la bandera que indica numero negativo
    {
        Flags[0]=1;
    }
    else
    {
        Flags[0]=0;
    }
    if (Rp==0)          //sentencia para la bandera que indica el numero cero
    {
        Flags[1]=1;
    }
    else
    {
        Flags[1]=0;
    }
    if (((((1<<31)&Rm)&&((1<<31)&Rn))&&((0<<31)&Rp))||((((1<<31)&Rm)||((1<<31)&Rn))&&((0<<31)&Rp)))
    {                    //sentencia para la bandera que indica un carry
        Flags[2]=1;
    }
    else
    {
        Flags[2]=0;
    }
    if  (((pow(2,31)-1)==Rm)==((pow(2,31)-1)==Rn))        //sentencia para la bandera que indica que hay un sobreflujo
    {
        if (((pow(2,31)-1)==Rm)!=((pow(2,31)-1)==Rp))
        {
            Flags[3]=1;
        }
    }
    else
    {
        Flags[3]=0;
    }
}
