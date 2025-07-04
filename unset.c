#include "../shell.h"



void exec_unset(t_cmd *cmd)
{
    char *key = cmd->argv[1];
    t_env* env = cmd->shell->env;
    t_env *previous = NULL;
    while (env)
    {
        if (!ft_strcmp(env->key,key))
        {
            if (previous)
                previous->next = env->next;
            else
                cmd->shell->env = env->next;
            free(env->key);
            free(env->value);
            free(env);
            return;
        }
        previous = env;
        env = env->next;
    }

}