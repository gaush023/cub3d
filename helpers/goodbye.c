#include "../includes/cub3d.h"

void goodbye(t_game *game, int code, char *msg)
{
  if (msg)
    print_error(msg);
  else
    write(0, "Goodbye\n", 8);
  if (game)
      exit(code);
  if(game->mlx)
      my_free(game->mlx, game->node);
  malloc_end(game->node);
  exit(code);
}
