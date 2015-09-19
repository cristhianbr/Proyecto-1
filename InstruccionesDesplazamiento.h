#include <stdint.h>

/**
*\brief Funcion desplazamiento logico hacia la izquierda.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*\param flag Puntero con la direccion de el arreglo de banderas.
*/
void LSLS(uint32_t *Rnd, uint32_t Rm, uint32_t Rn, char *flag);

/**
*\brief Funcion desplazamiento logico hacia la derecha.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*\param flag Puntero con la direccion de el arreglo de banderas.
*/
void LSRS(uint32_t *Rnd, uint32_t Rm, uint32_t Rn, char *flag);

/**
*\brief Funcion para rotacion logica hacia la derecha.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a rotar.
*\param flag Puntero con la direccion de el arreglo de banderas.
*/
void RORS(uint32_t *Rnd, uint32_t Rm, char *flag);

/**
*\brief Funcion para rotacion logica un registro hacia la derecha.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*\param flag Puntero con la direccion de el arreglo de banderas.
*/
void ASRS(uint32_t *Rnd, uint32_t Rm, char *flag);

/**
*\brief Funcion que realiza el ADN entre un registro y el complemento del otro
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*\param flag Puntero con la direccion de el arreglo de banderas.
*/
void BICS(uint32_t *Rnd, uint32_t Rm, char *flag);

/**
*\brief Funcion que no hace nada, en un ciclo de reloj
*/

void NOP();

/**
*\brief Funcion que Realiza el complemento de un registro
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*\param flag Puntero con la direccion de el arreglo de banderas.
*/
void MVNS(uint32_t *Rnd, uint32_t Rm, char *flag);

/**
*\brief Funcion que suma pero no modifica registro, solo activa banderas.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*\param flag Puntero con la direccion de el arreglo de banderas.
*/
void CMN(uint32_t Rm, uint32_t Rn, char *flag);

/**
*\brief Funcion que resta pero no modifica registro, solo activa banderas.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*\param flag Puntero con la direccion de el arreglo de banderas.
*/
void CMP(uint32_t Rm, uint32_t Rn, char *flag);

/**
*\brief Funcion que realiza el complemento a 1 de un registro
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*\param flag Puntero con la direccion de el arreglo de banderas.
*/
void RSBS(uint32_t *Rnd, uint32_t Rm, char *flag);

/**
*\brief Funcion que opera a nivel de bytes, revierte el orden de bytes en un registro de 32 bits.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*\param flag Puntero con la direccion de el arreglo de banderas.
*/
void REV(uint32_t *Rnd, uint32_t Rm);

/**
*\brief Funcion que opera a nivel de bytes, revierte el orden en cada media palabra de 16 bits en un registro de 32 bits.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void REV16(uint32_t *Rnd, uint32_t Rm);

/**
*\brief Funcion que opera a nivel de bytes, guarda el primer byte con extencion de signo hasta completar los 32 bits.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void REVSH(uint32_t *Rnd, uint32_t Rm);


/**
*\brief Funcion que realiza una AND entre dos registros, no gustada el resultado, solo modifica banderas.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*\param flag Puntero con la direccion de el arreglo de banderas.
*/
void TST(uint32_t Rnd, uint32_t Rm,char *flag);

