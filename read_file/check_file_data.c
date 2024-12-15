/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:29:21 by shuga             #+#    #+#             */
/*   Updated: 2024/12/15 19:29:52 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_file_data(t_game *game)
{
	if (is_four_xpmlines(game) == ERROR)
		goodbye(game, ERROR, "Invalid map\n xpm data is not enough\n");
	return ;
}
