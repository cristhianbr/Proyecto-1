#include <stdio.h>
#include <stdlib.h>
#include "registros.h"
#include "ALU.h"
#include "banderas.h"
#include <stdint.h>
#include "curses.h"
#include "decoder.h"

int main(void)
{
    uint32_t reg[16]={0};       //se creo un arreglo de 13 variables de 32 bits para los 13 registros
	char bandera[4]={0};        //La bandera se definio como un arreglo de 4 variables siendo la primera la bandera de negativo
    int ch=0,j=0;

    int i, num_instructions;
    ins_t read;
    char** instructions;
    instruction_t instruction;
    num_instructions = readFile("prueba.txt", &read);
    if(num_instructions==-1)    {   return 0;   }
    if(read.array==NULL)        {   return 0;	}
    instructions = read.array;

    initscr();	            /* Inicia modo curses */
    curs_set(0);	            /* Cursor Invisible */
    raw();			            /* Activa modo raw */
	keypad(stdscr, TRUE);   	/* Obtener F1, F2, etc */
    noecho();	            	/* No imprimir los caracteres leidos */
    start_color();	            /* Permite manejar colores */
    init_pair(1, COLOR_WHITE, COLOR_CYAN); 	/* Pair 1 -> Texto blanco fondo cyan */
    bkgd(COLOR_PAIR(1));           //se rellena el todo el fondo de color cyan

	mostrar_registro(reg);
	move(4, 50); printw("Banderas");
	move(6, 50); printw("N=%d\n",bandera[0]);
    move(7, 50); printw("Z=%d\n",bandera[1]);
    move(8, 50); printw("C=%d\n",bandera[2]);
    move(9, 50); printw("S=%d\n",bandera[3]);
    move(20, 50); printw("Emulador ARM Cortex-M0");
    border( ACS_VLINE, ACS_VLINE,
            ACS_HLINE, ACS_HLINE,
            ACS_ULCORNER, ACS_URCORNER,
            ACS_LLCORNER, ACS_LRCORNER	);
    refresh();
	while(ch != 'q')
    {
        ch = getch();            /* Espera entrada del usuario */
        clear();
        instruction = getInstruction(instructions[reg[15]);
        decodeInstruction(instruction,reg,bandera);
        if (j!=0)
        {
            mostrar_registro(reg);
            move(4, 50); printw("Banderas");
            move(6, 50); printw("N=%d\n",bandera[0]);
            move(7, 50); printw("Z=%d\n",bandera[1]);
            move(8, 50); printw("C=%d\n",bandera[2]);
            move(9, 50); printw("V=%d\n",bandera[3]);
            move(20, 50); printw("Emulador ARM Cortex-M0");
            border( ACS_VLINE, ACS_VLINE,
                    ACS_HLINE, ACS_HLINE,
                    ACS_ULCORNER, ACS_URCORNER,
                    ACS_LLCORNER, ACS_LRCORNER	);
            refresh();	            /* Imprime en la pantalla Sin esto el printw no es mostrado */
        }
        j=1;
    }
    attroff(COLOR_PAIR(1));     	/* DEshabilita los colores Pair 1 */
    endwin();

    for(i=0; i<num_instructions; i++)   {   free(read.array[i]);	}
	free(read.array);

    	                    /* Finaliza el modo curses */
    return 0;
}
