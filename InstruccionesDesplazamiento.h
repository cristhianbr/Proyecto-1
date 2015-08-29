#include <stdint.h>

/**
*\brief Funcion desplazamiento logico hacia la izquierda.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void LSLS(uint32_t *Rnd, uint32_t Rm);

/**
*\brief Funcion desplazamiento logico hacia la derecha.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void LSRS(uint32_t *Rnd, uint32_t Rm);

/**
*\brief Funcion para rotacion logica hacia la derecha.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a rotar.
*/
void ROR(uint32_t *Rnd, uint32_t Rm);

/**
*\brief Funcion para rotacion logica un registro hacia la derecha.
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void ASRS(uint32_t *Rdn, uint32_t Rm);

/**
*\brief Funcion
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void BICS(uint32_t *Rdn, uint32_t Rm);
/**
*\brief Funcion
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/

void MVNS(uint32_t *Rdn, uint32_t Rm);

/**
*\brief Funcion
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void RSBS(uint32_t *Rdn, uint32_t Rm);

/**
*\brief Funcion
*\param *Rdn Puntero con la direccion de el registro que se va a mover, y en donde se guardara el resultado obtenido.
*\param Rm Numero de posiciones a mover.
*/
void REVS(uint32_t *Rdn, uint32_t Rm);
