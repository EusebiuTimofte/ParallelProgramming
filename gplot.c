#include <gplot.h>

int check_X_display()
{
	char* disp;
	disp = getenv("DISPLAY");
	if (disp == NULL)
	{
		return 1;
		fprintf(stderr, "nu exista X server!");
	}
	else return 0;
}

gplot_ctrl *gplot_init() {
	if (!check_X_display()) return NULL;
	gplot_ctrl *handler;
	handler = (gplot_ctrl*) malloc(sizeof(gplot_ctrl));	
	gplot_setstyle(handler, "points");
	
	handler->gpcmd = popen("gnuplot", "w");
	if ( handler->gpcmd != NULL) return handler;
	else
	{
		free(handler);
		fprintf(stderr, "Nu s-a conectat");
		return NULL;
	}
}
	

void gplot_close(gplot_ctrl *handler) {
	if (pclose(handler->gpcmd) == -1) {
		fprintf(stderr, "Conexiunea s-a intrerupt");
		return;
	}else
	{
		free(handler);
		handler = NULL;
		return;
	}
}

void gplot_setstyle(gplot_ctrl *handler, char *plot_style){
	if( strcmp(plot_style, "lines") &&
	strcmp(plot_style, "points") &&
	strcmp(plot_style, "linespoits") &&
	strcmp(plot_style, "impulses") &&
	strcmp(plot_style, "dots") &&
	strcmp(plot_style, "steps") &&
	strcmp(plot_style, "errorbars") &&
	strcmp(plot_style, "boxes") &&
	strcmp(plot_style, "boxerrorbars") ){
	fprintf(stderr, "Stil de reprezentare grafic neconuscut: setare stil points");
	strcpy(handler->pstyle, "points");
	}
	else
	{
		strcpy(handler->pstyle, plot_style);
	}
}


void gplot_set_xlabel(gplot_ctrl *handle, char* label){
	char cmd[GP_CMD_SIZE];
	cmd = spritf(cmd, "set xlabel\"%s\"", label);
	gplot_cmd(handle, cmd);
}

void gplot_set_ylabel(gplot_ctrl *handle, char* label){
	char cmd[GP_CMD_SIZE];
	cmd = spritf(cmd, "set ylabel\"%s\"", label);
	gplot_cmd(handle, cmd);
}


void gplot_cmd(gplot_ctrl *handler, char *cmd, ...){
	va_list ap;
	char local_cmd[GP_CMD_SIZE];
	va_start(ap, cmd);
	vsprintf(local_cmd, cmd, ap);
	va_end(ap);
	strcat(local_cmd, '\n');
	fputs(local_cmd, handler->gpcmd);
	fflush(handler->gpcmd);
	return;
}

	
