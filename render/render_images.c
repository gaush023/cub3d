#include "../includes/cub3d.h"


void init_texture_pixel(t_game *game)
{
    int i; 
    
    if(game->texture_pixels)
        my_free_tab((void **)game->texture_pixels, game->node);
    game->texture_pixels = my_malloc(game->window_width + 1, sizeof * game->texture_pixels,game->node);
    if (!game->texture_pixels)
        goodbye("Error\nMalloc failed\n", game);
    i = 0;
    while(i < game->window_width)
    {
        game->texture_pixels[i] = my_malloc(game->window_width + 1, sizeof * game->texture_pixels, game->node);
        if (!game->texture_pixels[i])
            goodbye("Error\nMalloc failed\n", game);
        i++;
    }
}

void render_images(t_game *game)
{
    init_texture_pixel(game);
    init_ray(game);
    raycasting(&game->player, game);
    render_frane(game);
}
