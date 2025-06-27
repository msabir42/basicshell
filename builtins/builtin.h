#ifndef BUILTIN_H
#define BUILTIN_H  

#include <unistd.h>
#include <stdlib.h>
#include "../shell.h"


int     isbuiltin(char *cmd);

int     exec_cd(t_cmd *cmd);
int     exec_echo(t_cmd *cmd);
int     exec_exit(t_cmd *cmd);
int     exec_unset(t_cmd *cmd);
int     exec_pwd(t_cmd *cmd);
int     exec_export(t_cmd *cmd);
int     exec_env(t_cmd *cmd);
int     exec_builtin(t_cmd *cmd);  
#endif
