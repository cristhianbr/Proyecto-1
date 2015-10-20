#include <stdio.h>
#include <stdlib.h>
#include "registros.h"
#include "ALU.h"
#include "banderas.h"
#include <stdint.h>
#include "curses.h"
#include "decoder.h"
#include "mostrarRAM.h"
#include "io.h"

extern uint8_t irq[16];

int main(void)
{
    uint32_t reg[16]={0};       //se creo un arreglo de 13 variables de 32 bits para los 13 registros
	char bandera[4]={0};        //La bandera se definio como un arreglo de 4 variables siendo la primera la bandera de negativo
    int ch=0,j=0;
    uint16_t Mnem=0x0;
    uint8_t MemRAM[256],m=0;;
    reg[13]=0x100;
    for(j=0;j<=0xff;j++)
    {
        MemRAM[j]=0xff;
    }
    int num_instructions;
    ins_t read;
    char** instructions;
    instruction_t instruction;
    num_instructions = readFile("code.txt", &read);
    if(num_instructions==-1)    {   return 0;   }
    if(read.array==NULL)        {   return 0;	}
    instructions = read.array;

    initscr();	                /* Inicia modo curses */
    curs_set(0);	            /* Cursor Invisible */
    raw();			            /* Activa modo raw */
	keypad(stdscr, TRUE);   	/* Obtener F1, F2, etc */
    noecho();	            	/* No imprimir los caracteres leidos */
    start_color();	            /* Permite manejar colores */
    init_pair(1, COLOR_WHITE, COLOR_CYAN); 	/* Pair 1 -> Texto blanco fondo cyan */
    bkgd(COLOR_PAIR(1));           //se rellena el todo el fondo de color cyan
	mostrar_registro(reg);
    move(4, 40); printw("Banderas");
    move(6, 40); printw("N=%d\n",bandera[0]);
    move(7, 40); printw("Z=%d\n",bandera[1]);
    move(8, 40); printw("C=%d\n",bandera[2]);
    move(9, 40); printw("V=%d\n",bandera[3]);
    move(11, 40); printw("PC=%X\n",reg[15]*2);
    move(12, 40); printw("LR=%X\n",reg[14]*2);
    move(13, 40); printw("SP=%X\n",reg[13]);
    move(4, 55); printw("Emulador ARM Cortex-M0");
    mostrar_ram(MemRAM);
    initIO();showPorts();
    border( ACS_VLINE, ACS_VLINE,
            ACS_HLINE, ACS_HLINE,
            ACS_ULCORNER, ACS_URCORNER,
            ACS_LLCORNER, ACS_LRCORNER	);
    refresh();
	while(ch != 'q')
    {
        ch = getch();            /* Espera entrada del usuario */
        clear();
        showPorts();
        if(ch=='1')
        {
            changePinPortB(0,HIGH);
        }
        instruction = getInstruction(instructions[reg[15]]);
        decodeInstruction(instruction, reg, bandera, MemRAM, &Mnem);
        mostrar_registro(reg);
        move(2, 15); printw("%s",instructions[reg[15]-1]);
        move(2, 40); printw("Instruccion --> 0x%.4X",Mnem);
        move(4, 40); printw("Banderas");
        move(6, 40); printw("N=%d\n",bandera[0]);
        move(7, 40); printw("Z=%d\n",bandera[1]);
        move(8, 40); printw("C=%d\n",bandera[2]);
        move(9, 40); printw("V=%d\n",bandera[3]);
        move(11, 40); printw("PC=%X\n",reg[15]*2);
        move(12, 40); printw("LR=%X\n",reg[14]*2);
        move(13, 40); printw("SP=%X\n",reg[13]);
        move(4, 55); printw("Emulador ARM Cortex-M0");
        move(5, 55); printw("Presione q para Salir");
        mostrar_ram(MemRAM);
        border( ACS_VLINE, ACS_VLINE,
                ACS_HLINE, ACS_HLINE,
                ACS_ULCORNER, ACS_URCORNER,
                ACS_LLCORNER, ACS_LRCORNER	);
        refresh();	            /* Imprime en la pantalla Sin esto el printw no es mostrado */
        INT(irq, reg, MemRAM, bandera, &m);
    }
    attroff(COLOR_PAIR(1));     	/* DEshabilita los colores Pair 1 */
    endwin();
	free(read.array);

    /* Finaliza el modo curses */

    return 0;
}
