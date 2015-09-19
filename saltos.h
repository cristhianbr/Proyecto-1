/**
*\brief Funcion que suma a la posicion actual un inmediato, y llega a la pasicion en el PC deseada.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*/
void B(uint32_t *reg, int inm);

/**
*\brief  Funcion que salta si la bandera de Zero esta activa .
*\param *reg Direccion del PC.
*\param inm  Inmediato.
*/
void BEQ(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que salta si la bandera de Zero no esta activa.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BNE(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que salta si la bandera de Carry esta activa.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BCS(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que salta si la bandera de Carry no esta activa.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BCC(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que salta si la bandera de Negativo esta activa.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BMI(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que salta si la bandera de Negativo no esta activa.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BPL(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que alta si la bandera de Sobreflujo esta activa.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BVS(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que Salta si la bandera de Sobreflujo no esta activa
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BVC(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que salta si la bandera de Carry esta activa y la bandera de Zero no esta acativa.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BHI(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que salta si la bandera de Carry no esta activa y la bandera de Zero esta acativa.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BLS(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que salta si la bandera de Sobreflujo y la bandera de Negativo estan ambas activas o ambas inactivas.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BGE(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion salta si la bandera de Sobleflijo esta activa y la de NEgativo esta inactiva, o viceversa.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BLT(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que alta si la bandera de Carry esta activa y la bandera de Zero no esta acativa.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BGT(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que salta si la bandera de Zero esta inactiva y la bandera de Negatvo esta en el mismo estado de la de Sobreflujo.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*\param *flags Direccion del arreglo de banderas
*/
void BLE(uint32_t *reg, int inm, char *flags);

/**
*\brief Funcion que salta un inmediato en PC .
*\param *reg Direccion del PC.
*\param inm Inmediato.
*/
void BLA(uint32_t *reg, int inm);

/**
*\brief Funcion queenvia al PC a una direccion inmediata y manda al LR a la siguiente instruccion teniendo en cuenta la consideracion de que PC emplea 32 bits.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*/
void BL(uint32_t *reg, uint32_t *reg2, int inm);

/**
*\brief Funcion que guarda el contenido de un registro en el PC y pone a LR en la siguiente instruccion teniendo en cuenta la consideracion de que PC emplea 32 bits.
*\param *reg Direccion del PC.
*\param inm Inmediato.
*/
void BX(uint32_t *reg, uint32_t Rm);

/**
*\brief Esta funcion guardo el contenido de un registro en el PC y pone a LR en la siguiente instruccion teniendo en cuenta la consideracion de que PC emplea 32 bits
*\param *reg Direccion del PC.
*\param inm Inmediato.
*/
void BLX(uint32_t *reg, uint32_t *reg2, uint32_t Rm);
