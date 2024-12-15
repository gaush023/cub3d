/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:31:08 by shuga             #+#    #+#             */
/*   Updated: 2024/12/15 20:03:47 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	for_north_south(t_player *player)
{
	if (player->direction == 'N')
	{
		player->direction_x = 0;
		player->direction_y = -1;
		player->plane_y = 0;
		player->plane_x = 0.66;
	}
	else if (player->direction == 'S')
	{
		player->direction_x = 0;
		player->direction_y = 1;
		player->plane_y = 0;
		player->plane_x = -0.66;
	}
}

static void	for_east_west(t_player *player)
{
	if (player->direction == 'E')
	{
		player->direction_x = 1;
		player->direction_y = 0;
		player->plane_y = 0.66;
		player->plane_x = 0;
	}
	else if (player->direction == 'W')
	{
		player->direction_x = -1;
		player->direction_y = 0;
		player->plane_y = -0.66;
		player->plane_x = 0;
	}
}

void	init_player_direction(t_game *game)
{
	for_north_south(&game->player);
	for_east_west(&game->player);
}
