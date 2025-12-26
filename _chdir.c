#include "shell.h"
/**
* _chdir - fonction qui permet de changer de répertoire actuel
* @path - chemin cible
* Return: 0 succès, -1 échec
*/
int _chdir(char *path)
{
char *oldpwd;
char *newpwd;
char *av_oldpwd[4];
char *av_pwd[4];
oldpwd = _getcwd();
if (!oldpwd)
return (-1);
if (chdir(path) == -1)
{
perror("cd");
free(oldpwd);
return(-1);
}
newpwd = _getcwd();
if (!newpwd)
{
free (oldpwd);
return (-1);
}
av_oldpwd[0] = "setenv";
av_oldpwd[1] = "OLDPWD";
av_oldpwd[2] = oldpwd;
av_oldpwd[3] = NULL;
av_pwd[0] = "setenv";
av_pwd[1] = "PWD";
av_pwd[2] = newpwd;
av_pwd[3] = NULL;
_setenv(av_oldpwd);
_setenv(av_pwd);
free(oldpwd);
free(newpwd);
return (0);
}
