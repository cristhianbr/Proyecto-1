#include <stdint.h>
/**
*\brief Funcion que ejecuta una suma aritmetica.
*\param *Rp Direccion en donde se guardara el resultado de la suma aritmetica.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void ADD(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);	//funcion de la suma aritmetica, modifica banderas


/**
*\param *Rp Direccion en donde se guardara el resultado de la multiplicacion logica.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void AND(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);	//funcion de la multiplicacion logica, modifica banderas

/**
*\param *Rp Direccion en donde se guardara el resultado de la suma logica exclusiva.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void EOR( uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);	//funcion de la suma logica exclusiva

/**
*\param *Rp Direccion a la cual se desea mover el fichero.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void MOV(uint32_t *Rp, uint32_t Rm, char *flag);			//funcion para mover un fichero a otra direccion

/**
*\param *Rp Direccion en donde se guardara el resultado de la suma logica
*\param Rm Registro que se movera a Rp.
*/
void ORR(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);	//funcion de la suma logica

/**
*\param *Rp Direccion en donde se guardara el resultado de la resta aritmetica.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void SUB(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);	//funcion de la resta aritmetica

