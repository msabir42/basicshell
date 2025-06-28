#include "../shell.h"



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
        return (exec_cd(cmd));
    if (!ft_strcmp(cmd->argv[0],"echo") )
        return (exec_echo(cmd));
    if (!ft_strcmp(cmd->argv[0],"unset") )
        return (exec_unset(cmd));
    if (!ft_strcmp(cmd->argv[0],"env") )
        return (exec_env(cmd));
    if (!ft_strcmp(cmd->argv[0],"pwd") )
        return (exec_pwd(cmd));
    if (!ft_strcmp(cmd->argv[0],"exit") )
        return (exec_exit(cmd));
    if (!ft_strcmp(cmd->argv[0],"export") )
        return (exec_export(cmd));
    return -1;
}