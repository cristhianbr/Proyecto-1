#include "banderas.h"
#include <math.h>

void banderas(uint32_t Rp, uint32_t Rm, uint32_t Rn, char *Flags)
{
    if ((1<<31)&Rp)     //sentencia para la bandera que indica numero negativo
    {
        Flags[N]=1;
    }
    else
    {
        Flags[N]=1;
    }
    if (Rp==0)          //sentencia para la bandera que indica el numero cero
    {
        Flags[Z]=1;
    }
    else
    {
        Flags[Z]=0;
    }
    if (((((1<<31)&Rm)&&((1<<31)&Rn))&&((0<<31)&Rp))||((((1<<31)&Rm)||((1<<31)&Rn))&&((0<<31)&Rp)))
    {                    //sentencia para la bandera que indica un carry
        Flags[C]=1;
    }
    else
    {
        Flags[C]=0;
    }
    if  (((pow(2,31)-1)==Rm)==((pow(2,31)-1)==Rn))        //sentencia para la bandera que indica que hay un sobreflujo
    {
        if (((pow(2,31)-1)==Rm)!=((pow(2,31)-1)==Rp))
        {
            Flags[V]=1;
        }
    }
    else
    {
        Flags[V]=0;
    }
}
