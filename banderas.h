#include <stdint.h>

/**
*\brief Funcion para evaluar banderas en las operaciones logicas
*\param Rp Resultado de la operacion logico artmetica.
*\param Rm Operando 1
*\param Rn Operando 2
*\param *flags Puntero que apunta al arreglo que contiene las banderas.
*/
void banderas(uint32_t Rp, uint32_t Rm, uint32_t Rn, char *flags);

void banderas2(uint32_t Rp,char *flags);
