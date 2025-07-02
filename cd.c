#include "shell.h"



t_env *find(t_env* env, char* key)
{
    while(env)
    {
        if (!ft_strcmp(env->key, key))
            return env;
        env = env->next;
        
    }
    return NULL;
}

 void update_env(t_env *env, const char *key, const char *value)
 {
    t_env* node = find(env,key);
    if (node)
    {
        free(node->value);
        node->value = ft_strdup(value);
    }
    else 
    {
        t_env* new = new_env(ft_strdup(key),ft_strdup(value));
        if (!new)
            return;
        while (env && env->next)
            env = env->next;
        if (env)
            env->next = new;
    }
 }
int exec_cd(t_cmd *cmd)
{
    char* path = cmd->argv[1];
    char current_dir[4096];
    t_env *env = cmd->shell->env;
     if (!getcwd(current_dir, sizeof(current_dir)))
    {
        perror("cd: getcwd");
        return;
    }
    if (!path)
    {
        t_env *home = find(env,"HOME");
        if (!home || !home->value)
        {
            perror("home not set");
            return 0;
        }
        path = home->value;
    }
    else if (!ft_strcmp(path,"-"))
    {
        t_env *old = find(env,"OLDPWD");
        if (!old || !old->value)
        {
            perror("OLDPWD not set");
            return 0;
        }
        path = old->value;
        write(1,path,ft_strlen(path));
        write(1,"\n",1);
    }
    if (chdir(path) != 0)
    {
        write(2, "cd: ", 4);
        perror(path);
        return;
    }
    update_env(env, "OLDPWD", current_dir);
    if (getcwd(current_dir, sizeof(current_dir)))
    update_env(env, "PWD", current_dir);

    
}