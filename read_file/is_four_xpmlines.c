/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_four_xpmlines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:29:21 by shuga             #+#    #+#             */
/*   Updated: 2024/12/15 20:01:10 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*re_xpmpath(char *path)
{
	char	*tmp;
	size_t	tmp_pos;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ft_isalpha(path[i]) == true)
		i++;
	while (is_space(path[i]) == true)
		i++;
	tmp_pos = i;
	while (path[i] != '\n')
		i++;
	tmp = calloc(1, sizeof *(tmp * (i - tmp_pos + 1)));
	while (tmp_pos < i)
	{
		tmp[j] = path[tmp_pos];
		j++;
		tmp_pos++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void	which_direction_and_copy(t_game *game, size_t row, size_t column)
{
	if (game->mapinfo.file[row][column] == 'N' && game->mapinfo.file[row][column
		+ 1] == 'O')
		game->texinfo.north = re_xpmpath(&game->mapinfo.file[row][column]);
	else if (game->mapinfo.file[row][column] == 'S'
			&& game->mapinfo.file[row][column + 1] == 'O')
		game->texinfo.south = re_xpmpath(&game->mapinfo.file[row][column]);
	else if (game->mapinfo.file[row][column] == 'W'
			&& game->mapinfo.file[row][column + 1] == 'E')
		game->texinfo.west = re_xpmpath(&game->mapinfo.file[row][column]);
	else if (game->mapinfo.file[row][column] == 'E'
			&& game->mapinfo.file[row][column + 1] == 'A')
		game->texinfo.east = re_xpmpath(&game->mapinfo.file[row][column]);
	else
		goodbye(game, ERROR, "Invalid map\nxpm file is invalid direction\n");
}

void	copy_xpm_path(t_game *game, size_t row, size_t column)
{
	size_t	start_pos;
	int		count;

	count = 0;
	start_pos = column;
	while (game->mapinfo.file[row][column] != '\n')
		column++;
	while (game->mapinfo.file[row][column] != '.' && count < 5)
	{
		column--;
		count++;
	}
	if (count != 4)
		goodbye(game, ERROR, "Invalid map\nxpm file is invalid extension\n");
	if (game->mapinfo.file[row][column + 1] != 'x'
		&& game->mapinfo.file[row][column + 2] != 'p'
		&& game->mapinfo.file[row][column + 3] != 'm')
		goodbye(game, ERROR, "Invalid map\nxpm file is invalid extension\n");
	column = start_pos;
	which_direction_and_copy(game, row, column);
}

static bool	is_four_xpmlines_helper(t_game *game, size_t row, size_t column)
{
	while (game->mapinfo.file[row][column] != '\0')
	{
		while (is_space(game->mapinfo.file[row][column]) == true)
			column++;
		if (game->mapinfo.file[row][column] == 'N'
			|| game->mapinfo.file[row][column] == 'S'
			|| game->mapinfo.file[row][column] == 'W'
			|| (game->mapinfo.file[row][column] == 'E'
				&& game->mapinfo.file[row][column + 1] == 'A'))
			copy_xpm_path(game, row, column);
		if (game->texinfo.north != NULL && game->texinfo.south != NULL
			&& game->texinfo.west != NULL && game->texinfo.east != NULL)
			return (SUCCESS);
		column++;
	}
	return (!SUCCESS);
}

bool	is_four_xpmlines(t_game *game)
{
	size_t	row;
	size_t	column;

	row = 0;
	column = 0;
	while (game->mapinfo.file[row] != NULL)
	{
		column = 0;
		if (is_four_xpmlines_helper(game, row, column) == SUCCESS)
			return (SUCCESS);
		row++;
	}
	return (ERROR);
}
