/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:31:27 by shuga             #+#    #+#             */
/*   Updated: 2024/12/11 01:31:33 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define XK_Escape 53 // Escape key
#define XK_Left 123  // Left arrow key
#define XK_Right 124 // Right arrow key
#define XK_w 13      // 'w' key
#define XK_a 0       // 'a' key
#define XK_s 1       // 's' key
#define XK_d 2       // 'd' key

// X11 event masks
#define KeyPress 2
#define KeyRelease 3
#define ClientMessage 33
#define NoEventMask 0L
#define KeyPressMask (1L << 0)
#define KeyReleaseMask (1L << 1)

int	key_press_handler(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_game(game);
	if (keycode == XK_Left)
		game->player.rotate -= 1;
	if (keycode == XK_Right)
		game->player.rotate += 1;
	if (keycode == XK_w)
		game->player.move_y = 1;
	if (keycode == XK_a)
		game->player.move_x = -1;
	if (keycode == XK_s)
		game->player.move_y = -1;
	if (keycode == XK_d)
		game->player.move_x = 1;
	return (0);
}

int	key_release_handler(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_game(game);
	if (keycode == XK_w && game->player.move_y == 1)
		game->player.move_y = 0;
	if (keycode == XK_s && game->player.move_y == -1)
		game->player.move_y = 0;
	if (keycode == XK_a && game->player.move_x == -1)
		game->player.move_x += 1;
	if (keycode == XK_d && game->player.move_x == 1)
		game->player.move_x -= 1;
	if (keycode == XK_Left && game->player.rotate <= 1)
		game->player.rotate = 0;
	if (keycode == XK_Right && game->player.rotate >= -1)
		game->player.rotate = 0;
	return (0);
}

void	listen_for_key(t_game *game)
{
	init_player_direction(game);
	mlx_hook(game->win, ClientMessage, NoEventMask, close_game, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press_handler, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release_handler, game);
}
