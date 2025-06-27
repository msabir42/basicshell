#ifndef SHELL_H
#define SHELL_H  

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h" 

typedef struct s_env
{
    char            *key;
    char            *value;
    struct s_env    *next;
} t_env;

typedef enum e_token_type
{
    WORD,
    FILE_NAME,
    CMD,
    DELIMITER,
    ARG,
    PIPE,
    REDIR_IN,
    REDIR_OUT,
    HEREDOC,
    APPEND,
} t_token_type;

typedef struct s_token
{
    char            *value;
    t_token_type    type;
    char            quote;
    struct s_token  *next;
} t_token;

typedef struct s_cmd
{
    char        **argv;
    char        *infile;
    char        *outfile;
    int         append;
    struct s_cmd *next;
} t_cmd;

typedef struct s_shell
{
    t_env   *env;
    t_cmd   *cmds;
    int     exit_status;
} t_shell;

int     ft_strcmp(char *s1, char *s2);

#endif
