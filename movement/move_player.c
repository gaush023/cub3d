#include "../includes/cub3d.h"

static int move_forward(t_game *game)
{
    double new_x;
    double new_y;

    new_x = game->player.pos_x + game->player.direction_x * MOVESPEED;
    new_y = game->player.pos_y + game->player.direction_y * MOVESPEED;
    return (validate_move(game, new_x, new_y));
}

static int move_backward(t_game *game)
{
    double new_x;
    double new_y;

    new_x = game->player.pos_x - game->player.direction_x * MOVESPEED;
    new_y = game->player.pos_y - game->player.direction_y * MOVESPEED;
    return (validate_move(game, new_x, new_y));
}

static int move_left(t_game *game)
{
    double new_x;
    double new_y;

    new_x = game->player.pos_x + game->player.direction_y * MOVESPEED;
    new_y = game->player.pos_y - game->player.direction_x * MOVESPEED;
    return (validate_move(game, new_x, new_y));
}

static int move_right(t_game *game)
{
    double new_x;
    double new_y;

    new_x = game->player.pos_x - game->player.direction_y * MOVESPEED;
    new_y = game->player.pos_y + game->player.direction_x * MOVESPEED;
    return (validate_move(game, new_x, new_y));
}

int move_player(t_game *game)
{
    int moved;

    moved = 0;
    if(game->player.move_y == 1)
        moved += move_forward(game);
    if(game->player.move_y == -1)
        moved += move_backward(game);
    if(game->player.move_x == -1)
        moved += move_right(game);
    if(game->player.move_x == 1)
        moved += move_left(game);
    if(game->player.rotate == 1)
        moved += rotate_player(game, game->player.rotate);
    printf("player->pos_x = %f\n", game->player.pos_x);
    printf("player->pos_y = %f\n", game->player.pos_y);
    return (moved);
}

