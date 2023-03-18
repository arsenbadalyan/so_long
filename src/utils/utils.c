#include "so_long.h"

char **dup_double(char **str, size_t size)
{
    char **dup;
    size_t i;

    i = 0;
    dup = (char **)malloc(sizeof(char *) * (size + 1));
    if(!dup)
        return (NULL);
    while(i < size)
    {
        dup[i] = ft_strdup(str[i]);
        if(!dup[i])
        {
            dup[i] = NULL;
            return ((char **)free_double(&dup));
        }
        i++;
    }
    dup[i] = NULL;
    return (dup);
}
