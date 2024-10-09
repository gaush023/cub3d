#include "../includes/cub3d.h"

static bool is_valid_pos(t_game *game, double x, double y)
{
   if(x < 0.25 || x >= game->mapinfo.width - 1.25)
        return (false);
    if(y < 0.25 || y >= game->mapinfo.height - 0.25)
        return (false);
    if(game->mapinfo.file[(int)y][(int)x] == '1')
        return (false);
    return (true);
}

int validate_move(t_game *game, double new_x, double new_y)
{
    int moved;  

    moved = 0;
    if(is_valid_pos(game, new_x, game->player.pos_y))
    {
        game->player.pos_x = new_x;
        moved = 1;
    }
    if(is_valid_pos(game, game->player.pos_x, new_y))
    {
        game->player.pos_y = new_y;
        moved = 1;
    }
    return (moved);
}
