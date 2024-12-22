/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:28:34 by shuga             #+#    #+#             */
/*   Updated: 2024/12/22 16:50:38 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_texture_index(t_game *game, t_ray *ray)
{
	if (ray->side == SIDE_X)
	{
		if (ray->dir_x < 0)
			game->texinfo.index = WEST;
		else
			game->texinfo.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			game->texinfo.index = SOUTH;
		else
			game->texinfo.index = NORTH;
	}
}
