#include "shell.h"

char* get_path(char* command, t_env *env)
{
    char* path;
    char ** paths;
    int i;

    i = 0;
    path = get_env_value(env,"PATH");
    if (!path)
    {
        return NULL;
    }
    paths = ft_split(path,':');
    if (!paths)
    {
        return NULL;
    }
    while (paths[i])
    {
        char* full_path;
        full_path = ft_strjoin3(paths[i],"/",command);
        if (access(full_path,X_OK) == 0)
        {
            free_split(paths);
            return full_path;
        }
        i++;
        free(full_path);

    }
    free_split(paths);
    return NULL;

}


void exec_native(t_cmd *cmd)
{
    char *path;
    char **vars;
    path = get_path(cmd->argv[0],cmd->shell->env);
    if (!path)
    {
        write(2,"command not found",18);
        return;
    }
    vars = env_to_array(cmd->shell->env);
    if (!vars)
    {
        write(2,"no env vars",12);
        free(path);
        return;
    }
    pid_t pid = fork();
    if (pid == 0)
    {
        execve(path,cmd->argv,vars);
        perror("execve failed");
        exit(1);
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid,&status,0);
        cmd->shell->exit_status = WEXITSTATUS(status);

    }
    else 
    {
        perror("fork failed");
    }
    free(path);
    free_split(vars);
}
void exec_command(t_cmd* cmd)
{
    if (!cmd | !cmd->argv | !cmd->argv[0])
        return;
    if (isbuiltin(cmd->argv[0]))
        exec_builtin(cmd);
    else
        exec_native(cmd);
}