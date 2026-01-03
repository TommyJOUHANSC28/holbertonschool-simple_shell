#include "shell.h"
/**
* sigint_handler - Affiche un retour à la ligne et ton prompt
* @sig: interger
* Return: un retour à la ligne
*/
void sigint_handler(int sig)
{
(void)sig;  
write(STDOUT_FILENO, "\n$ ", 3);  
}
