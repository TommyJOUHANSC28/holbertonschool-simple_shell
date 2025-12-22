#include "shell.h"
#define SHELL_NAME "./hsh"
/**
 * handle_exit - Gère la commande builtin exit
 * @av: tableau des arguments (av[0] == "exit")
 *
 * Cette fonction quitte le shell avec le code fourni
 * ou 0 si aucun argument.
 */
void handle_exit(char **av)
{
	size_t i;
    int status = 0;

    if (av[1])  
    {    char *arg = av[1];
        for (i = 0; arg[i]; i++)
        {
            if (i == 0 && (arg[i] == '+' || arg[i] == '-'))  
                continue;
            if (!isdigit((unsigned char)arg[i]))  
            {
                fprintf(stderr, "%s: exit: %s: numeric argument required\n", SHELL_NAME, arg);
                
                for (i = 0; av[i]; i++)
                    free(av[i]);
                free(av);
                _exit(2);  
            }
        }

        
        if (av[2])
        {
            fprintf(stderr, "%s: exit: too many arguments\n", SHELL_NAME);
            return;
        }

        status = atoi(av[1]); 
        _exit(status);
    }

    
    for (i = 0; av[i]; i++)
        free(av[i]);
    free(av);
    _exit(status);  
}
