#include "../shell.h"


void exec_env(t_cmd *cmd)
{
    t_env *env = cmd->shell->env;
    while(env)
    {
        if(env->value)
        {
            write(1,env->key,ft_strlen(env->key));
            write(1,"=",1);
            write(1,env->value,ft_strlen(env->value));
            write(1, "\n", 1);
        }
        env = env->next;
    }
}