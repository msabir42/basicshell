#ifndef SHELL_H
#define SHELL_H  

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <sys/types.h> 
#include <sys/wait.h>    
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

typedef struct  s_redirections
{
    char        *infile;
    char        *outfile;
    int         append;   
} t_redirections;

typedef struct s_cmd
{
    char        **argv;
    
    t_shell     *shell;
    t_redirections *redir;
    struct s_cmd *next;
} t_cmd;

typedef struct s_shell
{
    t_env   *env;
    t_cmd   *cmds;
    int     exit_status;
} t_shell;


// utils
int     ft_strcmp(char *s1, char *s2);
char *ft_strjoin3(const char *s1, const char *s2, const char *s3);
void free_split(char **arr);

// env funcs
t_env *new_env(char* key, char* value);
char *get_env_value(t_env *env, const char *key);
char **env_to_array(t_env *env);
static int env_len(t_env *env);

// exec
char* get_path(char* command, t_env *env);
void exec_command(t_cmd* cmd);
void exec_native(t_cmd *cmd);
// exec builtin
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
