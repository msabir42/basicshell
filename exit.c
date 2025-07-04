#include "../shell.h"


void exec_exit(t_cmd* cmd)
{
    int status;
    status = 0;
    char *msg;
    msg = "exit\n";
    write(1,msg,ft_strlen(msg));
    if (cmd->argv[1])
        status = ft_atoi(cmd->argv[1]);
    exit(status);
}