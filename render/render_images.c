#include "../includes/cub3d.h"


void init_texture_pixel(t_game *game)
{
  int i; 

  if(game->textures_pixel)
    my_free_tab((void **)game->textures_pixel, game->node);
  game->textures_pixels = my_calloc(5, sizeof(int *));

}

void render_images(t_game *game)
{
  init_texture_pixel(game);

}
