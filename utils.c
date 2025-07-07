#include "shell.h"


int ft_strcmp(char *s1, char *s2)
{
    unsigned char c1;
    unsigned char c2;

    if (!s1 || !s2)
        return 1;

    while (*s1 || *s2)
    {
        c1 = (unsigned char)*s1++;
        c2 = (unsigned char)*s2++;
        if (c1 != c2)
            return c1 - c2;
    }
    return 0;
}


char *ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
    if (!s1 || !s2 || !s3)
        return NULL;

    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    size_t len3 = ft_strlen(s3);
    size_t total_len = len1 + len2 + len3;

    char *result = malloc(total_len + 1);
    if (!result)
        return NULL;

    size_t i = 0;
    size_t j = 0;

    while (s1[j])
        result[i++] = s1[j++];

    j = 0;
    while (s2[j])
        result[i++] = s2[j++];

    j = 0;
    while (s3[j])
        result[i++] = s3[j++];

    result[i] = '\0';
    return result;
}

void free_split(char **arr)
{
    int i = 0;

    if (!arr)
        return;

    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}