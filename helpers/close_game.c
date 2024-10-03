#include "../includes/cub3d.h"

int close_game(t_game *game)
{
    if(!game)
    {
        malloc_end(game->node);
        exit(0);
    }
    if(game->win && game->mlx)
        mlx_destroy_window(game->mlx, game->win);
    if(game->mlx)
    {
       // mlx_destroy_display(game->mlx); for linux
       // mlx_loop_end(game->mlx); for linux
       my_free(game->mlx, game->node);
    }
    my_free(game,game->node);
    malloc_end(game->node);
    exit(0);
}

