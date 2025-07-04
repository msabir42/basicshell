#include "../shell.h"

static t_env *find(t_env* env, char* key)
{
    while(env)
    {
        if (!ft_strcmp(env->key, key))
            return env;
        env = env->next;
        
    }
    return NULL;
}
void exec_export(t_cmd* cmd)
{
    char* arg = cmd->argv[1];
    char *equal;
    char *key;
    char* value;
    if (!arg || !ft_strchr(arg,"="))
    {
        write(1,"wrong input",12);
        return;
    }
    *equal = !ft_strchr(arg,"=");
    *equal = '\0';
    key = ft_strdup(arg);
    value = ft_strdup(equal + 1);
    *equal = '=';
    if (!key || !value)
    {
        return;
    }
    t_env* node = find(cmd->shell->env,key);
    if (node)
    {
        free(node->value);
        node->value = value;
        free(key);
    }
    else 
    {
        t_env *new = new_env(key, value);
        t_env *env = cmd->shell->env;
        if (!env)
            cmd->shell->env = new;
        else
        {
            while (env->next)
                env = env->next;
            env->next = new;
        }
    }

}