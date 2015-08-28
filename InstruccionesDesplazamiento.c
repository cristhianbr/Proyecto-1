#include "InstruccionesDesplazamiento.h"
void ROR(uint32_t *Rdn, uint32_t Rm)
{
	uint32_t R1, R2;
	R1=*Rnd/(2^Rm);
	R2=*Rnd*(2^(32-Rm));
	*Rnd=R1+R2;
}
