#include "io.h"

extern uint8_t irq[16];	// Arreglo de interrupciones
						// Cada elemento es una interrupción por pin

int main(void)
{
	uint8_t data;
	
	initIO();	// Inicializa los puertos de E/S
	
	data = 1;
	IOAccess(13, &data, Write);	// Escribe en el registro de interrupciones
								// Habilita la interrupción 0 del puerto B
	data = 0xAA;
	IOAccess(10, &data, Write);	// Escribe 0xAA al DDRB

	data=0xFF;
	IOAccess(11, &data, Write);	// Escribe 0xFF al PORTB

	IOAccess(12, &data, Read);	// Lee el PINB
	
	IOAccess(1, &data, Write);	// Escribe el valor del PINB al PORTA

	changePinPortB(0,HIGH);		// Cambia el valor del Pin a Alto

	showPorts();				// Muestra en pantalla el estado del puerto

	getch();	
		
	endwin();

	return 0;
}
