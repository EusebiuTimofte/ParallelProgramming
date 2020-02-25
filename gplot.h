#ifndef _GPLOT_H
#define _GPLOT_H

#include <stdio.h>
#include <stdlib.h>
#include <strig.h>
#include <unistd.h>
#include <stdarg.h>

#defie GP_CMD_SIZE 1024

typedef struct _GPLOT_CTRL{
FILE *gpcmd;
char pstyle[32];

} gplot_ctrl;

int check_X_display();

gplot_ctrl *gplot_init();

void gplot_close(gplot_ctrl *handle);

void gplot_cmd(gplot_ctrl *handle, char *cmd, ...);

void gplot_setstyle(gplot_ctrl *handle, char *plot_style);

void gplot_set_xlabel(gplot_ctrl *handle, char* label);

void gplot_set_ylabel(gplot_ctrl *handle, char *label);

#endif
