#include "../includes/cub3d.h"

void	print_maps(t_game *game)
{
	size_t	row;
	size_t	column;

	row = 0;
	column = 0;
	while (game->mapinfo.file[row] != NULL)
	{
		column = 0;
		while (game->mapinfo.file[row][column])
		{
			write(1, &game->mapinfo.file[row][column], 1);
			column++;
		}
		row++;
	}
	write(1, "\n", 1);
	return ;
}

void	which_direction_and_copy(t_game *game, size_t row, size_t column)
{
	if (game->mapinfo.file[row][column] == 'N' && game->mapinfo.file[row][column
		+ 1] == 'O')
		game->texinfo.north = my_strndup(&game->mapinfo.file[row][column],
				ft_strlen(&game->mapinfo.file[row][column]) - 1, game->node);
	else if (game->mapinfo.file[row][column] == 'S'
		&& game->mapinfo.file[row][column + 1] == 'O')
		game->texinfo.south = my_strndup(&game->mapinfo.file[row][column],
				ft_strlen(&game->mapinfo.file[row][column]) - 1, game->node);
	else if (game->mapinfo.file[row][column] == 'W'
		&& game->mapinfo.file[row][column + 1] == 'E')
		game->texinfo.west = my_strndup(&game->mapinfo.file[row][column],
				ft_strlen(&game->mapinfo.file[row][column]) - 1, game->node);
	else if (game->mapinfo.file[row][column] == 'E'
		&& game->mapinfo.file[row][column + 1] == 'A')
		game->texinfo.east = my_strndup(&game->mapinfo.file[row][column],
				ft_strlen(&game->mapinfo.file[row][column]) - 1, game->node);
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

bool	is_four_xpmlines(t_game *game)
{
	size_t	row;
	size_t	column;

	row = 0;
	column = 0;
	while (game->mapinfo.file[row] != NULL)
	{
		column = 0;
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
		row++;
	}
	return (ERROR);
}



void	check_file_data(t_game *game)
{
	print_maps(game);
	if (is_four_xpmlines(game) == ERROR)
		goodbye(game, ERROR, "Invalid map\n xpm data is not enough\n");
    get_celling_floor_color(game);
	printf("game->texinfo.north: %s$\n", game->texinfo.north);
	printf("game->texinfo.south: %s$\n", game->texinfo.south);
	printf("game->texinfo.west: %s$\n", game->texinfo.west);
	printf("game->texinfo.east: %s$\n", game->texinfo.east);
	return ;
}
