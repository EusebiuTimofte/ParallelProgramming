#ifndef _GPLOT_H_
#define _GPLOT_H_
//^din start evita supradefinirea

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

/*lungimea maxima a liniei de comanda */
#define GP_CMD_SIZE 1024

typedef struct _GPLOT_CTRL_{
    FILE *gpcmd; //string de control pt subproces
    char pstyle[32]; //tip de reprezentare grafica
}gplot_ctrl;

/*******************************************************************************************************************************************
 * Nume : check_X_display()
 * Rol : verifica existenta var de mediu DISPLAY (posibilitatea reprezentarii grafice)
 * Intrare : nimic
 * Iesire : val int 0 daca DISPLAY definita
 *          1 altfel
 * Obs
 : * *****************************************************************************************************************************************/

int check_X_display();

/*******************************************************************************************************************************************
 * Nume : gplot_init()
 * Rol : initializeaza sesiunea de comunicare cu subprocesul gnuplot (procesare grafica puternica orientata script)
 * Intrare : nimic
 * Iesire : un pointer pe stream-ul asociat procesului gnuplot
 * Obs
 : * *****************************************************************************************************************************************/

gplot_ctrl * gplot_init();

//Laborator 2

/*******************************************************************************************************************************************
 * Nume : gplot_close(gplot_ctrl * handle)
 * Rol : inchide subprocesul deschis anterior, elibereaza resursele alocate
 * Intrare : handle pentru sesiunea de control a subprocesului deschisa anterior
 * Iesire : nimic
 * Obs
 : * *****************************************************************************************************************************************/

void gplot_close(gplot_ctrl *handle);

/*******************************************************************************************************************************************
 * Nume : gplot_cmd(gplot_ctrl * handle, char * cmd, ...)
 * Rol : controleaza subprocesul pe care nit l-a deschis
 * Intrare : handle pentru subprocesul activ si o lista variabila de argumente reprezentand variabile string
  * Iesire : nimic
 * Obs : Sintaxa parametrului cmd nu este testata
 * *****************************************************************************************************************************************/

void gplot_cmd( gplot_ctrl * handle, char * cmd, ...);

/*******************************************************************************************************************************************
 * Nume : gplot_pstyle(gplot_ctrl * handle, char * pstyle)
 * Rol :  definirea stilului de reprezentare grafica
 * Intrare : handle pentru subprocesul activ si un string reprezentand stilul de reprezentare grafica
  * Iesire : nimic
 * Obs
 :  * *****************************************************************************************************************************************/

void gplot_pstyle(gplot_ctrl * handle, char * pstyle);

/*******************************************************************************************************************************************
 * Nume : gplot_set_xlabel(gplot_ctrl * handle, char * label)
 * Rol :  redefinirea numelui axei
 x * Intrare : handle pentru subprocesul activ si un string reprezentand numele
  * Iesire : nimic
 * Obs
 :  * *****************************************************************************************************************************************/
void gplot_set_xlabel(gplot_ctrl * handle, char * label);

/*******************************************************************************************************************************************
 * Nume : gplot_set_ylabel(gplot_ctrl * handle, char * label)
 * Rol :  redefinirea numelui axei y
 * Intrare : handle pentru subprocesul activ si un string reprezentand numele
 * Iesire : nimic
 * Obs
 :  * *****************************************************************************************************************************************/
void gplot_set_ylabel(gplot_ctrl * handle, char * label);







/* se scrie numai deasupra acestei linii */

#endif
