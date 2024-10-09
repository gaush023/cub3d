#include "../includes/cub3d.h"

void read_texture_info(t_game *game)
{
    printf("\n---------------------------\n");
    printf("read_texture_info\n");
    printf("game->texinfo.north: %s\n", game->texinfo.north);
    printf("game->texinfo.south: %s\n", game->texinfo.south);
    printf("game->texinfo.west: %s\n", game->texinfo.west);
    printf("game->texinfo.east: %s\n", game->texinfo.east);

    printf("game->texinfo.floor: %d\n", *game->texinfo.floor);
    printf("game->texinfo.ceiling: %d\n", *game->texinfo.ceiling);
    printf("--------------------------------\n\n");
    return ;
}

