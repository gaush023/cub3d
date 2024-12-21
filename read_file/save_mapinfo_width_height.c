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

void check_first_last_line(char **map, t_game *game, int row)
{
    size_t i;

    i = 0;
    while (is_space(map[row][i]))
        i++;
    while (map[row][i + 1] != '\n')
    {
        if(!is_space(map[row][i]) && map[row][i] != '1')
            goodbye(game, ERROR, "Invalid map\n");
        i++;
    }
}

bool is_within(char *map, int j)
{

    int tmp_pos;
  
    if(j == 0)
        return true;
    tmp_pos = j;
    while(map[j] != '\n' && map[j] != '1')
        j++;
    if(map[j] == '\n')
        return false;
    j = tmp_pos;
    while(j == 0 && map[j] != '1')
        j--;
    if(j == 0)
        return false;
    return true;
}

void check_map(char **map, t_game *game)
{
    int i;
    int j;
    
    check_first_last_line(map, game, 0);
    check_first_last_line(map, game, game->mapinfo.height - 1);
    i = 1;
    while(i < game->mapinfo.height - 1)
    {
        j = 0;
        while (map[i][j] != '\n')
        {
            if(map[i][j] == '0')
            {
                if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
                {
                    goodbye(game, ERROR, "A Invalid map\n");
                }
                if(!is_within(map[i], j))
                {
                    goodbye(game, ERROR, "I nvalid map\n");
                }
            }
            else if(!is_space(map[i][j]) && map[i][j] != '1' && map[i][j] != game->player.direction)
           {
                goodbye(game, ERROR, "Invalid maaaap\n");
            }
            j++;
        }
        i++;
    }
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
    check_map(game->map, game);
}
