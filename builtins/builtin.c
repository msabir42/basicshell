#include "../shell.h"

int ft_strcmp(char *s1, char *s2)
{
    unsigned char c1;
    unsigned char c2;

    if (!s1 || !s2)
        return 1;

    while (*s1 || *s2)
    {
        c1 = (unsigned char)*s1++;
        c2 = (unsigned char)*s2++;
        if (c1 != c2)
            return c1 - c2;
    }
    return 0;
}
int isbuiltin(char* cmd)
{
    if (!cmd)
        return 0;
    return (
        !ft_strcmp(cmd,"cd") ||
        !ft_strcmp(cmd,"export") ||
        !ft_strcmp(cmd,"echo") ||
        !ft_strcmp(cmd,"exit") ||
        !ft_strcmp(cmd,"pwd") ||
        !ft_strcmp(cmd,"unset") ||
        !ft_strcmp(cmd,"env")
    )
}

void exec_builtin(t_cmd* cmd)
{
    if (!ft_strcmp(cmd->argv[0],"cd") )
        return (exec_cd);
    if (!ft_strcmp(cmd->argv[0],"echo") )
        return (exec_echo);
    if (!ft_strcmp(cmd->argv[0],"unset") )
        return (exec_unset);
    if (!ft_strcmp(cmd->argv[0],"env") )
        return (exec_env);
    if (!ft_strcmp(cmd->argv[0],"pwd") )
        return (exec_pwd);
    if (!ft_strcmp(cmd->argv[0],"exit") )
        return (exec_exit);
    if (!ft_strcmp(cmd->argv[0],"export") )
        return (exec_export);
    return -1;
}