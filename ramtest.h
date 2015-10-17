/**
*\brief Funcion para guardar el contenido de registros en la memoria Ram.
*\param *regs Puntero con la direccion del arreglo de registros.
*\param *MemRAM Puntero con la direccion de la memoria Ram.
*\param *reg Puntero con la direccion del arreglo  que determinan que registros se van a guardar (1 y 0).
*/
void PUSH(uint32_t *regs, uint8_t *MemRAM, uint8_t *Reg);
/**
*\brief Funcion para sacar contenidos de la memoria Ram.
*\param *regs Puntero con la direccion del arreglo de registros.
*\param *MemRAM Puntero con la direccion de la memoria Ram.
*\param *reg Puntero con la direccion del arreglo  que determinan que registros se van a sacar (1 y 0).
*/
void POP(uint32_t *regs, uint8_t *MemRAM, uint8_t *Reg);
/**
*\brief Funcion para guardar contenidos de registros en la memoria Ram y guardar las banderas.
*\param *regs Puntero con la direccion del arreglo de registros.
*\param *MemRAM Puntero con la direccion de la memoria Ram.
*\param *flags Puntero con la direccion del arreglo  que contienen las banderas.
*/
void PUSH_INT(uint32_t *regs, uint8_t *MemRAM, char *flags);
/**
*\brief Funcion para sacar contenidos de la memoria Ram y guardar las banderas.
*\param *regs Puntero con la direccion del arreglo de registros.
*\param *MemRAM Puntero con la direccion de la memoria Ram.
*\param *flags Puntero con la direccion del arreglo  que contienen las banderas.
*/
void POP_INT(uint32_t *regs, uint8_t *MemRAM, char *flags);
