#include "../includes/cub3d.h"

int key_press_handler(int keycode, t_game *game)
{
    if(keycode == XK_Escape)
        close_game(game);  
    if(keycode == XK_Left)
        game->player.rotate -= 1;
    if(keycode == XK_Right)
        game->player.rotate += 1;
    if(keycode == XK_w)
        game->player.move_y = 1;
    if(keycode == XK_a)
        game->player.move_x = -1;
    if(keycode == XK_s)
        game->player.move_y = -1;
    if(keycode == XK_d)
        game->player.move_x = 1;
    return (0);
}

int key_release_handler(int keycode, t_game *game)
{
    if(keycode == XK_Escape)
        close_game(game);
    if(keycode == XK_w && game->player.move_y == 1)
        game->player.move_y = 0;
    if(keycode == XK_s && game->player.move_y == -1)
        game->player.move_y = 0;
    if(keycode == XK_a && game->player.move_x == -1)
        game->player.move_x += 1;
    if(keycode == XK_d && game->player.move_x == 1)
        game->player.move_x -= 1;
    if(keycode == XK_Left && game->player.rotate <= 1)
        game->player.rotate = 0;
    if(keycode == XK_Right && game->player.rotate >= -1)
        game->player.rotate = 0;
    return (0);
}


void listne_for_key(t_game *game)
{
    init_player_direction(game);
    mlx_hook(game->win, ClientMessage, NoEventMask, close_game, game);
    mlx_hook(game->win, KeyPress, KeyPressMask, key_press_handler, game);
    mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release_handler, game);   
}

