#include "gplot.h"

int check_x_display(){
	char *display=getenv("DISPLAY");
	if(display==NULL){
		fprintf(stderr,"Nu exista xserver!");
		return 1;
        }
	else return 0;
}

gplot_ctrl* gplot_init(){
	if (check_x_display()==1)
		return NULL;
	gplot_ctrl *handle=(gplot_ctrl*)malloc(sizeof(gplot_ctrl));
	gplot_pstyle(handle,"points");
	handle->gpcmd=popen("gnuplot","w");
	if (handle->gpcmd!=NULL)
		return handle;
	else {
		fprintf(stderr,"Nu s-a realizat conexiunea");
		free(handle);	
		return NULL;		
		}	
}

void gplot_close(gplot_ctrl *handle)
{
  if (pclose(handle->gpcmd)==-1)
	{
	fprintf(stderr,"connexiune esuata!");
	return;
	}
   else {
	free(handle);
	handle=NULL;
	return;
       }
}

void gplot_set_xlabel(gplot_ctrl *handle, char *label){
    char cmd[GP_CMD_SIZE];
    sprintf(cmd,"set xlabel \"%s\"", label);
    gplot_cmd(handle, cmd);
}

void gplot_set_ylabel(gplot_ctrl *handle, char *label){
    char cmd[GP_CMD_SIZE];
    sprintf(cmd,"set ylabel \"%s\"", label);
    gplot_cmd(handle , cmd);
}

void gplot_cmd(gplot_ctrl *handler,char *cmd, ...){

va_list ap;
char local_cmd[GP_CMD_SIZE];
va_start(ap,cmd);
vsprintf(local_cmd,cmd,ap);
va_end(ap);
strcat(local_cmd,"\n");
fputs(local_cmd,handler->gpcmd);
fflush(handler->gpcmd);
return;

}



void gplot_pstyle(gplot_ctrl *handle, char *plot_style){
    if(strcmp(plot_style, "lines") &&
    strcmp(plot_style, "points") &&
    strcmp(plot_style, "linespoints") &&
    strcmp(plot_style, "inpulses") &&
    strcmp(plot_style, "dots") &&
    strcmp(plot_style, "steps") &&
    strcmp(plot_style, "errorbars") &&
    strcmp(plot_style, "boxes") &&
    strcmp(plot_style, "boxerrorbars")){
        fprintf(stderr, "stil de reprezentare grafic necunoscut; setare stil points");
        strcpy(handle -> pstyle, "points");
    }
    else{
        strcpy(handle-> pstyle, plot_style);
    }

 }
