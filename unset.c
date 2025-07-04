#include "../shell.h"



void exec_unset(t_cmd *cmd)
{
    char *key = cmd->argv[1];
    t_env* env = cmd->shell->env;
    t_env *tmp = NULL;
    while (env)
    {
        if (!ft_strcmp(env->key,key))
        {
            
        }
    }

}