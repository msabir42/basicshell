#include "shell.h"



void exec_pipes(t_cmd *cmd)
{
    int fd[2];
    pid_t first, second;

    if (!cmd || !cmd->next)
        return;

    if (pipe(fd) == -1)
    {
        perror("pipe failed");
        return;
    }

    first = fork();
    if (first == 0)
    {
        dup2(fd[1], STDOUT_FILENO); 
        close(fd[0]);               
        close(fd[1]);

        exec_command(cmd);
        exit(1);
    }

    
    second = fork();
    if (second == 0)
    {
        dup2(fd[0], STDIN_FILENO);  
        close(fd[1]);               
        close(fd[0]);

        exec_command(cmd->next);
        exit(1);
    }


    close(fd[0]);
    close(fd[1]);
    waitpid(first, NULL, 0);
    waitpid(second, NULL, 0);
}