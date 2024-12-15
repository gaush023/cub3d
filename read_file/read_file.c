/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:30:25 by shuga             #+#    #+#             */
/*   Updated: 2024/12/15 19:34:23 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	read_file(char *file_path, t_game *game)
{
	ini_player(&game->player);
	ini_texture(&game->texinfo);
	ini_mapinfo(&game->mapinfo);
	check_file_extension(file_path, game);
	read_map_info(file_path, game);
	check_file_data(game);
	get_celling_floor_color(game);
	get_player_position(game);
}
