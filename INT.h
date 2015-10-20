/**
*\brief Funcion para cargar los registros y banderas en la memoria Ram cuando se ejecuta una interrupcion.
*\param *irq Puntero con la direccion del arreglo que guarda las interrupciones.
*\param *reg Puntero con la direccion del arreglo en donde estan los registros.
*\param MemRAM Puntero con la direccion de la memoria Ram.
*\param *m Puntero que determina si hay una interrupcion o no.
*/
void INT(uint8_t *irq, uint32_t *reg, uint8_t *MemRam, char *flags, uint8_t *m);
