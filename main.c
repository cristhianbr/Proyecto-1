#include <stdio.h>
#include <stdlib.h>
#include "registros.h"
#include "ALU.h"
#include "banderas.h"
#include <stdint.h>
#include <curses.h>

int main(void)
{
    uint32_t reg[13]={0};       //se creo un arreglo de 13 variables de 32 bits para los 13 registros
	char bandera[4]={0};        //La bandera se definio como un arreglo de 4 variables siendo la primera la bandera de negativo
    int i;
    initscr();		            /* Inicia modo curses */
    curs_set(0);	            /* Cursor Invisible */
    raw();			            /* Activa modo raw */
	keypad(stdscr, TRUE);   	/* Obtener F1, F2, etc */
    noecho();	            	/* No imprimir los caracteres leidos */
    start_color();	            /* Permite manejar colores */
    init_pair(1, COLOR_WHITE, COLOR_CYAN); 	/* Pair 1 -> Texto verde fondo Negro */
    bkgd(COLOR_PAIR(1));
	mostrar_registro(reg);
	move(4, 50); printw("N=%d\n",bandera[0]);
    move(5, 50); printw("Z=%d\n",bandera[1]);
    move(6, 50); printw("C=%d\n",bandera[2]);
    move(7, 50); printw("S=%d\n",bandera[3]);
    move(20, 50); printw("Emulador ARM Cortex-M0");
    border( ACS_VLINE, ACS_VLINE,
            ACS_HLINE, ACS_HLINE,
            ACS_ULCORNER, ACS_URCORNER,
            ACS_LLCORNER, ACS_LRCORNER	);
    refresh();
	i=0;
	while(1)
    {
        getch();            /* Espera entrada del usuario */
        clear();
        if (i==1)   {   ROR(&reg[1],1,bandera); move(2,28); printw("Operacion:\tROR\tR1->1"); refresh();  }
        if (i==2)   {   add(&reg[12],reg[2],3,bandera); move(2,28); printw("Operacion:\tADD\tR12=R2+3"); refresh(); }
        if (i==3)   {   And(&reg[4],reg[5],reg[6],bandera); move(2,28); printw("Operacion:\tAND\tR4=R5&R6"); refresh(); }
        if (i==4)   {   eor(&reg[7],reg[2],reg[9],bandera); move(2,28); printw("Operacion:\tEOR\tR7=R2^R9"); refresh(); }
        if (i==5)   {   orr(&reg[10],reg[4],5,bandera); move(2,28); printw("Operacion:\tORR\tR10=R4|4"); refresh(); }
        if (i==6)   {   LSLS(&reg[12],3,bandera); move(2,28); printw("Operacion:\tLSLS\tR12->3"); refresh(); }
        if (i==7)   {   LSRS(&reg[10],6,bandera); move(2,28); printw("Operacion:\tLSRS\tR10->6"); refresh(); }
        if (i==8)   {   ASRS(&reg[6],2,bandera); move(2,28); printw("Operacion:\tASRS\tR6->2 "); refresh(); }
        if (i==9)   {   break;  }
        if (i!=0)
        {
            mostrar_registro(reg);
            move(4, 50); printw("N=%d\n",bandera[0]);
            move(5, 50); printw("Z=%d\n",bandera[1]);
            move(6, 50); printw("C=%d\n",bandera[2]);
            move(7, 50); printw("S=%d\n",bandera[3]);
            move(20, 50); printw("Emulador ARM Cortex-M0");
            border( ACS_VLINE, ACS_VLINE,
                    ACS_HLINE, ACS_HLINE,
                    ACS_ULCORNER, ACS_URCORNER,
                    ACS_LLCORNER, ACS_LRCORNER	);
            refresh();	                /* Imprime en la pantalla Sin esto el printw no es mostrado */
        }
        i+=1;                       //Se crea un variable que va  a servir de contador
    }
    attroff(COLOR_PAIR(1));     	/* DEshabilita los colores Pair 1 */
    endwin();	                    /* Finaliza el modo curses */
    return 0;
}
