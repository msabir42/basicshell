#include "../shell.h"


void exec_echo(t_cmd *cmd)
{
    int i;
    int newline;
    char *param;

    param = cmd->argv[1];
    i = 0;
    newline = 1;
    if (ft_strncmp(param,"-n",ft_strlen(param)))
    {
        newline = 0;
        i++;
    }
    while (param[i])
    {
        write(1,param[i],ft_strlen(param));
        if (param[i + 1])
            write(1, " ", 1);
        i++;
    }
    if(newline)
        write(1,"\n",1);

}