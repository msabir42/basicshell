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