#include <stdint.h>

#define N 0
#define Z 1
#define C 2
#define V 3

/**
*\brief Funcion para evaluar banderas en las operaciones logicas
*\param Rp Resultado de la operacion logico artmetica.
*\param Rm Operando 1
*\param Rn Operando 2
*\param *Flags Puntero que apunta al arreglo que contiene las banderas.
*/
void banderas(uint32_t Rp, uint32_t Rm, uint32_t Rn, char *Flags);
