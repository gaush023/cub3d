#include "../includes/cub3d.h"


static bool is_valid_pos(t_game *game, double x, double y)
{
    
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
}
