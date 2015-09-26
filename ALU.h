#include <stdint.h>
/**
*\brief Funcion que ejecuta una suma aritmetica.
*\param *Rp Direccion en donde se guardara el resultado de la suma aritmetica.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void ADDS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);	//funcion de la suma aritmetica, modifica banderas

/**
*\brief Funcion que ejecuta una suma aritmetica.
*\param *Rp Direccion en donde se guardara el resultado de la suma aritmetica.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void ADCS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);      //funcion de la summa aritemtica la cual suma el valor de la bandera de carry, modifica banderas

/**
*\param *Rp Direccion en donde se guardara el resultado de la multiplicacion logica.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void ANDS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);	//funcion de la multiplicacion logica, modifica banderas

/**
*\param *Rp Direccion en donde se guardara el resultado de la suma logica exclusiva.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void EORS( uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);	//funcion de la suma logica exclusiva

/**
*\param *Rp Direccion a la cual se desea mover el fichero.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void MOV(uint32_t *Rp, uint32_t Rm);			//funcion para mover un fichero a otra direccion

/**
*\param *Rp Direccion a la cual se desea mover el fichero.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void MOVS(uint32_t *Rp, uint32_t Rm, char *flag);

/**
*\param *Rp Direccion en donde se guardara el resultado de la suma logica
*\param Rm Registro que se movera a Rp.
*/
void ORRS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);	//funcion de la suma logica

/**
*\param *Rp Direccion en donde se guardara el resultado de la resta aritmetica.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void SUBS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);	//funcion de la resta aritmetica

/**
*\param *Rp Direccion en donde se guardara el resultado de la multiplicacion aritmetica.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/

void MUL(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);

/**
*\param *Rp Direccion en donde se guardara el resultado de la resta CON CARRY.
*\param Rm Registro 1 a operar.
*\param Rn Registro 2 a operar.
*/
void SBCS(uint32_t *Rp, uint32_t Rm, uint32_t Rn, char *flag);
