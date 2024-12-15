/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:31:01 by shuga             #+#    #+#             */
/*   Updated: 2024/12/15 20:03:34 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	is_valid_pos(t_game *game, double x, double y)
{
	if (x < 0.25 || x >= game->mapinfo.width - 1.25)
		return (false);
	if (y < 0.25 || y >= game->mapinfo.height - 0.25)
		return (false);
	return (true);
}

int	validate_move(t_game *game, double new_x, double new_y)
{
	int	moved;
	int	tmp_val;

	moved = 0;
	if (is_valid_pos(game, new_x, game->player.pos_y))
	{
		tmp_val = game->player.pos_x;
		game->player.pos_x = new_x;
		if (game->map[(int)game->player.pos_y][(int)game->player.pos_x] == '1')
			game->player.pos_x = tmp_val + 0.5;
		else
			moved = 1;
	}
	if (is_valid_pos(game, game->player.pos_x, new_y))
	{
		tmp_val = game->player.pos_y;
		game->player.pos_y = new_y;
		if (game->map[(int)game->player.pos_y][(int)game->player.pos_x] == '1')
			game->player.pos_y = tmp_val + 0.5;
		else
			moved = 1;
	}
	return (moved);
}
