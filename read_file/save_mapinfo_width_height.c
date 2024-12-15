/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_mapinfo_width_height.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:30:25 by shuga             #+#    #+#             */
/*   Updated: 2024/12/15 19:53:58 by shuga            ###   ########.fr       */
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

void	save_mapinfo_width_height(t_game *game, size_t map_start_row)
{
	size_t	row;
	size_t	column;
	int		i;

	i = 0;
	game->map = NULL;
	row = map_start_row;
	row++;
	game->mapinfo.height = 0;
	while (game->mapinfo.file[row] != NULL
		&& is_all_space(game->mapinfo.file[row]) == false)
		row++;
	game->mapinfo.height = row - map_start_row;
	column = 0;
	while (game->mapinfo.file[map_start_row][column] != '\0')
		column++;
	game->mapinfo.width = column;
	game->map = calloc(game->mapinfo.height, sizeof *(game->map));
	while (i != game->mapinfo.height)
	{
		game->map[i] = ft_strdup(game->mapinfo.file[map_start_row]);
		map_start_row++;
		i++;
	}
}
