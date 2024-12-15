/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goodbye.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:34:12 by shuga             #+#    #+#             */
/*   Updated: 2024/12/15 20:08:53 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	goodbye(t_game *game, int code, char *msg)
{
	if (msg)
		print_error(msg);
	else
		write(0, "Goodbye\n", 8);
	if (game)
		exit(code);
	if (game->mlx)
		free(game->mlx);
	exit(code);
}
