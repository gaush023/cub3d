#include "../includes/cub3d.h"

void init_texture_pixel(t_game *game)
{
    int i; 
    
    if(game->texture_pixels)
        my_free_tab((void **)game->texture_pixels, game->node);
    game->texture_pixels = my_calloc(game->window_width + 1, sizeof * game->texture_pixels, game->node);
    if (!game->texture_pixels)
        goodbye(game, ERROR, "Malloc failed\n");
    i = 0;
    printf("game->window_width = %d\n", game->window_width);
    while(i < game->window_width)
    {
        game->texture_pixels[i] = my_calloc(game->window_width + 1, sizeof * game->texture_pixels, game->node);
        if (!game->texture_pixels[i])
            goodbye(game, ERROR,"Malloc failed\n");
        i++;
    }
}

void render_images(t_game *game)
{
    init_texture_pixel(game);
    ini_ray(&game->ray);
    raycasting(&game->player, game);
    render_frame(game);
}

int cub3d_render(t_game *game)
{
    int tmp_times;

    tmp_times = game->player.has_moved;
    game->player.has_moved += move_player(game);
    if (game->player.has_moved != tmp_times)
        render_images(game);
    return (0);
}
