#include <stdint.h>
/**
*\brief Funcion que ejecuta una suma aritmetica.
*\param *Rp Direccion en donde se guardara el resultado de la suma aritmetica.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void add( uint32_t *Rp,  uint32_t Rm,  uint32_t Rn);	//funcion de la suma aritmetica


/**
*\param *Rp Direccion en donde se guardara el resultado de la multiplicacion logica.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void and( uint32_t *Rp,  uint32_t Rm,  uint32_t Rn);	//funcion de la multiplicacion logica

/**
*\param *Rp Direccion en donde se guardara el resultado de la suma logica exclusiva.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void eor( uint32_t *Rp,  uint32_t Rm,  uint32_t Rn);	//funcion de la suma logica exclusiva

/**
*\param *Rp Direccion a la cual se desea mover el fichero.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void mov(uint32_t *Rp, uint32_t Rm);			//funcion para mover un fichero a otra direccion

/**
*\param *Rp Direccion en donde se guardara el resultado de la suma logica
*\param Rm Registro que se movera a Rp.
*/
void orr(uint32_t *Rp, uint32_t Rm, uint32_t Rn);	//funcion de la suma logica

/**
*\param *Rp Direccion en donde se guardara el resultado de la resta aritmetica.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void sub(uint32_t *Rp, uint32_t Rm, uint32_t Rn);	//funcion de la resta aritmetica

