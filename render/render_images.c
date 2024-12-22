/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:29:01 by shuga             #+#    #+#             */
/*   Updated: 2024/12/22 16:44:23 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_texture_pixel(t_game *game)
{
	int	i;

	if (game->texture_pixels)
		free_tab((void **)game->texture_pixels);
	game->texture_pixels = calloc(game->window_width + 1,
			sizeof *(game->texture_pixels));
	if (!game->texture_pixels)
		goodbye(game, ERROR, "Malloc failed\n");
	i = 0;
	while (i < game->window_width)
	{
		game->texture_pixels[i] = calloc(game->window_width + 1,
				sizeof *(game->texture_pixels));
		if (!game->texture_pixels[i])
			goodbye(game, ERROR, "Malloc failed\n");
		i++;
	}
}

void	render_images(t_game *game)
{
	init_texture_pixel(game);
	ini_ray(&game->ray);
	raycasting(&game->player, game);
	render_frame(game);
}

int	cub3d_render(t_game *game)
{
	game->player.has_moved += move_player(game);
	if (game->player.has_moved == 0)
		return (0);
	render_images(game);
	return (0);
}
