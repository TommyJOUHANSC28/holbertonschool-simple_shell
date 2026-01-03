#include "shell.h"
/** déclaration de variables globales*/
/* STATUS */
int last_status = 0;

/* HISTORY */
char *history[HIST_MAX] = {NULL};
int hist_count = 0;

/* ALIAS */
alias_t *alias_list = NULL;

/* LINE*/
char *line = NULL;


