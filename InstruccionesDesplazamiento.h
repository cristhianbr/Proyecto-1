#include <stdint.h>

/**
*\brief Funcion desplazamiento logico hacia la izquierda.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void LSLS(uint32_t *Rnd, uint32_t Rm, char *Rl);

/**
*\brief Funcion desplazamiento logico hacia la derecha.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void LSRS(uint32_t *Rnd, uint32_t Rm, char *Rl);

/**
*\brief Funcion para rotacion logica hacia la derecha.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a rotar.
*/
void ROR(uint32_t *Rnd, uint32_t Rm, char *Rl);

/**
*\brief Funcion para rotacion logica un registro hacia la derecha.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void ASRS(uint32_t *Rnd, uint32_t Rm, char *Rl);

/**
*\brief Funcion que realiza el ADN entre un registro y el complemento del otro
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void BICS(uint32_t *Rnd, uint32_t Rm, char *Rl);

/**
*\brief Funcion que no hace nada, en un ciclo de reloj
*/

void NOP();

/**
*\brief Funcion que Realiza el complemento de un registro
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void MVNS(uint32_t *Rnd, uint32_t Rm, char *Rl);

/**
*\brief Funcion que suma pero no modifica registro, solo activa banderas.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void CMN(uint32_t Rm, uint32_t Rn, char *Rl);

/**
*\brief Funcion que resta pero no modifica registro, solo activa banderas.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void CMP(uint32_t Rm, uint32_t Rn, char *Rl);

/**
*\brief Funcion
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void RSBS(uint32_t *Rnd, uint32_t Rm, char *Rl);

/**
*\brief Funcion
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void REVS(uint32_t *Rnd, uint32_t Rm,char *Rl);

void REV16S(uint32_t *Rnd, uint32_t Rm,char *Rl);

void REVSHS(uint32_t *Rnd, uint32_t Rm, char *Rl);

void TST(uint32_t Rm, uint32_t Rm1,char *Rl);
