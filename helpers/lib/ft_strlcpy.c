#include "../../includes/cub3d.h"

size_t ft_strlcpy(char *dst, char *src, size_t dstsize)
{
    size_t i;

    i = 0;
    if (dstsize == 0)
        return (ft_strlen(src));
    while(i < dstsize - 1 && src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}

