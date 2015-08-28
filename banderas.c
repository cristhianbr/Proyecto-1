#include "banderas.h"
#include <math.h>

void banderas(uint32_t Rp, uint32_t Rm, uint32_t Rn, char *Rl)
{
    if ((1<<31)&Rp)
    {
        Rl[0]=1;
    }
    else
    {
        Rl[0]=0;
    }
    if (Rp==0)
    {
        Rl[1]=1;
    }
    else
    {
        Rl[1]=0;
    }
    if (((((1<<31)&Rm)&&((1<<31)&Rn))&&((0<<31)&Rp))||((((1<<31)&Rm)||((1<<31)&Rn))&&((0<<31)&Rp)))
    {
        Rl[2]=1;
    }
    else
    {
        Rl[2]=0;
    }
    if  ((((1<<31)-1)&Rm)==(((1<<30)-1)&Rn))
    {
        if((((1<<31)-1)&Rm)!=((((1<<30)-1)&Rp)))
        {
            Rl[3]=1;
        }
    }
    else
    {
        Rl[3]=0;
    }
}
