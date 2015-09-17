#include "banderas.h"
#include <math.h>
#define N 0
#define Z 1
#define C 2
#define V 3

void banderas(uint32_t Rp, uint32_t Rm, uint32_t Rn, char *flags)
{
    if ((1<<31)&Rp)     //sentencia para la bandera que indica numero negativo
    {
        flags[N]=1;
    }
    else
    {
        flags[N]=0;
    }
    if (Rp==0)          //sentencia para la bandera que indica el numero cero
    {
        flags[Z]=1;
    }
    else
    {
        flags[Z]=0;
    }
    if (((((1<<31)&Rm)&&((1<<31)&Rn))&&((0<<31)&Rp))||((((1<<31)&Rm)||((1<<31)&Rn))&&((0<<31)&Rp)))
    {                    //sentencia para la bandera que indica un carry
        flags[C]=1;
    }
    else
    {
        flags[C]=0;
    }
    if  (((pow(2,31)-1)==Rm)==((pow(2,31)-1)==Rn))        //sentencia para la bandera que indica que hay un sobreflujo
    {
        if (((pow(2,31)-1)==Rm)!=((pow(2,31)-1)==Rp))
        {
            flags[V]=1;
        }
    }
    else
    {
        flags[V]=0;
    }
}
