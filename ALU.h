/**
*\brief Funcion que ejecuta una suma aritmetica.
*\param *Rp Direccion en donde se guardara el resultado de la suma aritmetica.
*\param Rm Registro a operar.
*\param Rn Registro a operar.
void add(unsigned long int *Rp, unsigned long int Rm, unsigned long int Rn);	//funcion de la suma aritmetica


/**
*\param *Rp Direccion en donde se guardara el resultado de la multiplicacion logica.
*\param Rm Registro a operar.
*\param Rn Registro a operar.
*/
void and(unsigned long int *Rp, unsigned long int Rm, unsigned long int Rn);	//funcion de la multiplicacion logica

/**
*\param *Rp Direccion en donde se guardara el resultado de la suma logica exclusiva.
*\param Rm Registro a operar.
*\param Rn Registro a operar.
*/
void eor(unsigned long int *Rp, unsigned long int Rm, unsigned long int Rn);	//funcion de la suma logica exclusiva

/**
*\param *Rp Direccion a la cual se desea mover el fichero.
*\param Rm Registro a operar.
*\param Rn Registro a operar.
*/
void mov(unsigned long int *Rp, unsigned long int Rm);			//funcion para mover un fichero a otra direccion

/**
*\param *Rp Direccion en donde se guardara el resultado de la suma logica
*\param Rm Registro que se movera a Rp.
*/
void orr(unsigned long int *Rp, unsigned long int Rm, unsigned long int Rn);	//funcion de la suma logica

/**
*\param *Rp Direccion en donde se guardara el resultado de la resta aritmetica.
*\param Rm Registro a operar.
*\param Rn Registro a operar.
*/
void sub(unsigned long int *Rp, unsigned long int Rm, unsigned long int Rn);	//funcion de la resta aritmetica

