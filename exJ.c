#include "gplot.h"
#include <gsl/gsl_sf_bessel.h>
#include <math.h>

#define NMAX 200
#define MY_MEM_ERR 1
#define MY_FILE_ERR 2
#define MY_CALL_ERR 3
#define MY_SUCCES 0

int main(int argc, char **argv){

	if(argc !=2){
		printf("\n Utilizare: %s nume_fisier \n",argv [0]);
		printf("nume_fisier este numele fisierului de date binare care va fi creat\n");
		printf("Progamul calculeaza (x,J0(x)) pe un grid cu pasul 0,1 pe intervalul [0,20]\n");
		return MY_CALL_ERR;
	}
	
	double step = 0.1;
	double x = 0;
	double valori[400];
	int i = 0;
	for ( i; i < 400; i = i+2) {
		valori[i] = x;
		valori[i+1] = gsl_sf_bessel_J0(x);
		x = (x+i*step) /2;
	}
	
	FILE *f;
	f = fopen(argv[1], "w+");
	for ( i = 0; i< 400; i = i+2) {
		fprintf(f, "%.5lf\t%.5lf\n", valori[i], valori[i+i]);
	}
	
	fclose(f);
	
	gplot_ctrl* gplot;
	gplot = gplot_init();
	gplot_set_xlabel(gplot, "ceva");
	gplot_set_ylabel(gplot, "altceva");
	gplot_pstyle(gplot, "lines");
	gplot_cmd(gplot, "plot '%s' u 1:2 w %s", argv[1], gplot->pstyle);
	printf("Ruleaza \n");
    printf("Apasa o tasta \n");
	scanf("%c", &cbrt);
	
	gplot_close(gplot);		
}
