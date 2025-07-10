#include "shell.h"

int redirect(t_redirections *redir)
{
    int fd;

    if (redir->infile)
    {
        fd = open(redir->infile, O_RDONLY);
        if (fd == -1)
            return 1;
        dup2(fd,STDIN_FILENO);
        close(fd);
    }
    if (redir->outfile)
    {
        int flags = O_WRONLY | O_CREAT; 
        if (redir->append)
            flags |= O_APPEND;
        else
            flags |= O_TRUNC;
        fd = open(redir->outfile,flags,0644);
        if(fd == -1)
            return 1;
        dup2(fd,STDOUT_FILENO);
        close(fd);
    }
    return 0;
}
