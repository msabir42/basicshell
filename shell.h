#ifndef SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h" 

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
}                        t_token_type;

typedef struct s_token
{
    char                *value;
    t_token_type        type;
    char                quote;
    struct s_token        *next;
}       

typedef struct s_cmd
{
    char    **argv;        
    char    *infile;       
    char    *outfile;      
    int     append;        
    struct s_cmd *next;    
} t_cmd;


int main(int argc, char *argv[]);

#endif