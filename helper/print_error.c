#include "cub3d.h"

int print_error(char *error)
{
    write(1, "Error: ", 7);
    write(1, error, ft_strlen(error));
    return (ERROR);
}

