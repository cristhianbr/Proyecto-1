#include <stdio.h>
#include <stdlib.h>
#include "registros.h"
#include "ALU.h"
#include "banderas.h"
#include <stdint.h>
#include <curses.h>

int main(void)
{
    uint32_t reg[13];           //se creo un arreglo de 13 variables de 32 bits para los 13 registros
	char bandera[4];            //La bandera se definio como un arreglo de 4 variables siendo la primera la bandera de negativo
    int j,i;
    bandera[0]=0;   bandera[1]=0;   bandera[2]=0;   bandera[3]=0;
    initscr();		/* Inicia modo curses */
    curs_set(0);	/* Cursor Invisible */
    raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
    noecho();		/* No imprimir los caracteres leidos */
    start_color();	/* Permite manejar colores */
    init_pair(1, COLOR_WHITE, COLOR_BLACK);	/* Pair 1 -> Texto verde fondo Negro */
    attron(COLOR_PAIR(1));	/* Activa el color verde para el texto y negro para el fondo Pair 1*/
	mostrar_registro(reg);
	move(3, 50); printw("N=%d\n",bandera[0]);
    move(4, 50); printw("Z=%d\n",bandera[1]);
    move(5, 50); printw("C=%d\n",bandera[2]);
    move(6, 50); printw("S=%d\n",bandera[3]);
    border( ACS_VLINE, ACS_VLINE,
            ACS_HLINE, ACS_HLINE,
            ACS_ULCORNER, ACS_URCORNER,
            ACS_LLCORNER, ACS_LRCORNER	);
    refresh();
	i=0;
	while(1)
    {
        if (i==2)   {   ROR(&reg[1],1,bandera); move(2,28); printw("Operacion:\tROR"); refresh();  }
        if (i==3)   {   add(&reg[0],reg[2],reg[3],bandera); move(2,28); printw("Operacion:\tADD"); refresh(); }
        if (i==4)   {   And(&reg[4],reg[5],reg[6],bandera); move(2,28); printw("Operacion:\tAND"); refresh(); }
        if (i==5)   {   eor(&reg[7],reg[2],reg[9],bandera); move(2,28); printw("Operacion:\tEOR"); refresh(); }
        if (i==6)   {   orr(&reg[10],reg[4],reg[7],bandera); move(2,28); printw("Operacion:\tORR"); refresh(); }
        if (i==7)   {   LSLS(&reg[12],3,bandera); move(2,28); printw("Operacion:\tLSLS"); refresh(); }
        if (i==8)   {   break;  }
        if (i!=0)
        {
            for(j=0;j<=12;j++)          //se crea un ciclo for para dar valores a los registros y mostrar los registros en pantalla
            {
                move(3+j, 15);
                printw("R%d:\t%d\n", j,reg[j]);
            }
        }
        move(3, 50); printw("N=%d\n",bandera[0]);
        move(4, 50); printw("Z=%d\n",bandera[1]);
        move(5, 50); printw("C=%d\n",bandera[2]);
        move(6, 50); printw("S=%d\n",bandera[3]);
        border( ACS_VLINE, ACS_VLINE,
                ACS_HLINE, ACS_HLINE,
                ACS_ULCORNER, ACS_URCORNER,
                ACS_LLCORNER, ACS_LRCORNER	);
        refresh();	/* Imprime en la pantalla Sin esto el printw no es mostrado */
        getch();	/* Espera entrada del usuario */
        i+=1;          //Se crea un variable que va  a servir de contador
    }
    attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */
    endwin();	/* Finaliza el modo curses */
    return 0;
}
