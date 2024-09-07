#include "../includes/cub3d.h"

bool is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
        return (true);
    return (false);
}
