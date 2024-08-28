#include "../includes/cub3d.h"

void goodbye(t_game *game, int code, char *msg)
{
  if (msg)
    print_error(msg);
  else
    write(0, "Goodbye\n", 8);
  if (game)
      exit(code);
  if(game->window && game->mlx)
    mlx_destroy_window(game->mlx, game->window);
  if(game->mlx)
  {
    mlx_destroy_display(game->mlx);
    mlx_loop_end(game->mlx);
    my_free(game->mlx, game->node);
  }
  exit(code);
}
