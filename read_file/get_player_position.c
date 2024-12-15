/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:30:25 by shuga             #+#    #+#             */
/*   Updated: 2024/12/15 20:55:09 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	is_all_space(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (!is_space(line[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	is_all_one(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && !is_space(line[i]))
			return (false);
		i++;
	}
	if (is_all_space(line))
		return (false);
	return (true);
}

static void	get_player_position_helper(t_game *game, size_t row, size_t column,
		size_t map_start_row)
{
	game->player.pos_x = (double)column + 0.5;
	game->player.pos_y = (double)(row - map_start_row) + 0.5;
	game->player.direction = game->mapinfo.file[row][column];
	game->mapinfo.file[row][column] = '0';
	save_mapinfo_width_height(game, map_start_row);
}

static size_t	get_ini_maprow(t_game *game)
{
	size_t	row;

	row = 0;
	while (game->mapinfo.file[row] != NULL
		&& is_all_one(game->mapinfo.file[row]) == false)
		row++;
	return (row);
}

void	get_player_position(t_game *game)
{
	size_t	row;
	size_t	column;
	size_t	map_start_row;

	row = get_ini_maprow(game);
	column = 0;
	map_start_row = row;
	row++;
	while (game->mapinfo.file[row] != NULL
		&& is_all_one(game->mapinfo.file[row]) == false)
	{
		while (game->mapinfo.file[row][column] != '\0')
		{
			if (game->mapinfo.file[row][column] == 'N'
				|| game->mapinfo.file[row][column] == 'S'
				|| game->mapinfo.file[row][column] == 'W'
				|| game->mapinfo.file[row][column] == 'E')
				return (get_player_position_helper(game, row, column,
						map_start_row));
			column++;
		}
		column = 0;
		row++;
	}
}
