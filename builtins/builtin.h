#ifndef BUILTIN_H   
#include <unistd.h>
#include <stdlib.h>

typedef struct s_cmd
{
    char    **argv;        
    char    *infile;       
    char    *outfile;      
    int     append;        
    struct s_cmd *next;    
} t_cmd;

int ft_strcmp(char *s1, char *s2);
int isbuiltin(char* cmd);
void exec_cd();
void exec_echo();
void exec_exit();
void exec_unset();
void exec_pwd();
void exec_export();
void exec_env();
void exec_builtin(t_cmd* cmd);


#endif