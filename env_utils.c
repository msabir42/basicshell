#include "shell.h"

t_env *new_env(char* key, char* value)
{
    t_env *new = malloc(sizeof(t_env));
    if(!new)
        return NULL;
    new->key = key;
    new->value = value;
    new->next = NULL;
    return new;

}

t_env* init_env(char** envp)
{
    t_env* head;
    t_env* tail;
    t_env* node;
    char  *key;
    char  *value;
    char  *delimiter;

    head = NULL;
    tail = NULL;

    while(*envp)
    {
        delimiter = ft_strchr(*envp, "=");
        if(delimiter)
        {
            key = ft_substr(*envp,0,*envp - delimiter);
            value = ft_strdup(delimiter+1);
            if(key && value)
            {
                node = new_env(key,value);
                if (node)
                {
                    if (!head)
                        head = node;
                    else 
                        tail->next = node;
                    tail = node;
                }
                else
                {
                    free(key);
                    free(value);
                }
            }
             else
            {
                free(key);
                free(value);
            }
        }
        envp++;
        }
    return head;
}


void free_env(t_env* env)
{
    t_env *tmp;
    if(env)
    {
        tmp = env->next;
        free(env->key);
        free(env->value);
        free(env);
        env = tmp;
    }
}

char *get_env_value(t_env *env, const char *key)
{
    if (env)
    {
        if (ft_strcmp(env->key, key))
        {
            return (env->value);
        }
        env = env->next;
    }
    return NULL;
}
static int env_len(t_env *env)
{
    int count = 0;
    while (env)
    {
        count++;
        env = env->next;
    }
    return count;
}

char **env_to_array(t_env *env)
{
    int i = 0;
    int len = env_len(env);

    char **output = malloc(sizeof(char *) * (len + 1));
    if (!output)
        return NULL;

    while (env)
    {
        output[i] = ft_strjoin3(env->key, "=", env->value);
        if (!output[i])
        {
            while (i--)
                free(output[i]);
            free(output);
            return NULL;
        }
        env = env->next;
        i++;
    }
    output[i] = NULL;
    return output;
}

void set_env_value(t_env **env, const char *key, const char *value) 
{
    if (env)
    {
        
    }
}