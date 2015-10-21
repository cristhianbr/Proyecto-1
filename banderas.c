#include "banderas.h"
#define N 0
#define Z 1

void banderas(uint32_t Rp, char *flags)
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
}
