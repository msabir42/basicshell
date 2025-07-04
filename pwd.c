#include "../shell.h"


void exec_pwd(t_cmd *cmd)
{
    char pwd[4096];

    (void)cmd; 

    if (!getcwd(pwd, sizeof(pwd)))
    {
        perror("cant get current directory");
        return;
    }
    write(1, pwd, ft_strlen(pwd));
    write(1, "\n", 1);
}