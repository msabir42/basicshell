#include "shell.h"


void exec_all_pipes(t_cmd *cmd)
{
    int fd[2];
    int prev_pipe = -1; 
    pid_t pid;

    while (cmd)
    {
        if (cmd->next && pipe(fd) == -1)
        {
            perror("pipe failed");
            exit(1);
        }

        pid = fork();
        if (pid == -1)
        {
            perror("fork failed");
            exit(1);
        }

        if (pid == 0)
        {
    
            if (prev_pipe != -1)
            {
                dup2(prev_pipe, STDIN_FILENO);
                close(prev_pipe);
            }

            // 🔹 
            if (cmd->next)
            {
                close(fd[0]); 
                dup2(fd[1], STDOUT_FILENO);
                close(fd[1]);
            }

            exec_command(cmd); 
            exit(1); 
        }

  
        if (prev_pipe != -1)
            close(prev_pipe);
        if (cmd->next)
        {
            close(fd[1]);      
            prev_pipe = fd[0]; 
        }

        cmd = cmd->next;
    }


    while (wait(NULL) > 0);
}
