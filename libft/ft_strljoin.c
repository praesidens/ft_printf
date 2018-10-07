#include "libft.h"

char        *ft_strljoin(char **s1, char **s2)
{
    char    *res;

    res = NULL;
    if (!s1 && !s2)
        return (NULL);
    else if (!*s1 && *s2)
    {
        res = *s2;
        *s2 = NULL;
    }
    else if (*s1 && !*s2)
    {
        res = *s1;
        *s1 = NULL;
    }
    else
    {
        res = ft_strjoin(*s1, *s2);
        ft_strdel(s1);
        ft_strdel(s2);
    }
    return (res);
}