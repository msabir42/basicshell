#include "../shell.h"


int exec_cd(t_cmd *cmd){
    if (!cmd->argv[1])
        return 0;
    if (cmd->argv[1] == '-')
        chdir()
}