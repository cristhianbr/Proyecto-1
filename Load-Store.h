/**
*\brief Funcion para cargar contenidos de 4 posiciones de la memoria Ram.
*\param *Rt Puntero con la direccion del registro en el que se van a almacernar los contenidos cargados desde la memoria Ram.
*\param Rm Operando 1.
*\param Rn Operando 2.
*\param *Ram Puntero con la direccion de la memoria Ram.
*/
void LDR(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram);
/**
*\brief Funcion para cargar contenido de una posicion de la memoria Ram.
*\param *Rt Puntero con la direccion del registro en el que se van a almacernar el contenido cargado desde la memoria Ram.
*\param Rm Operando 1.
*\param Rn Operando 2.
*\param *Ram Puntero con la direccion de la memoria Ram.
*/
void LDRB(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram);
/**
*\brief Funcion para cargar contenidos de 2 posiciones de la memoria Ram.
*\param *Rt Puntero con la direccion del registro en el que se van a almacernar los contenidos cargados desde la memoria Ram.
*\param Rm Operando 1.
*\param Rn Operando 2.
*\param *Ram Puntero con la direccion de la memoria Ram.
*/
void LDRH(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram);
/**
*\brief Funcion para cargar contenido de una posicion de la memoria Ram y hacer extension de signo.
*\param *Rt Puntero con la direccion del registro en el que se van a almacernar el contenido cargado desde la memoria Ram.
*\param Rm Operando 1.
*\param Rn Operando 2.
*\param *Ram Puntero con la direccion de la memoria Ram.
*/
void LDRSB(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram);
/**
*\brief Funcion para cargar contenidos de 2 posiciones de la memoria Ram y hacer extension .
*\param *Rt Puntero con la direccion del registro en el que se van a almacernar los contenidos cargados desde la memoria Ram.
*\param Rm Operando 1.
*\param Rn Operando 2.
*\param *Ram Puntero con la direccion de la memoria Ram.
*/
void LDRSH(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram);
/**
*\brief Funcion para almacenar 4 bytes en la memoria Ram.
*\param *Rt Puntero con la direccion del registro del que se van a sacar los bytes para almacenar en la memoria Ram.
*\param Rm Operando 1.
*\param Rn Operando 2.
*\param *Ram Puntero con la direccion de la memoria Ram.
*/
void STR(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram);
/**
*\brief Funcion para almacenar 1 byte en la memoria Ram.
*\param *Rt Puntero con la direccion del registro del que se va a sacar el byte para almacenar en la memoria Ram.
*\param Rm Operando 1.
*\param Rn Operando 2.
*\param *Ram Puntero con la direccion de la memoria Ram.
*/
void STRB(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram);
/**
*\brief Funcion para almacenar 2 bytes en la memoria Ram.
*\param *Rt Puntero con la direccion del registro del que se van a sacar los bytes para almacenar en la memoria Ram.
*\param Rm Operando 1.
*\param Rn Operando 2.
*\param *Ram Puntero con la direccion de la memoria Ram.
*/
void STRH(uint32_t *Rt, uint8_t Rm, uint8_t Rn, uint8_t *Ram);

