/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:03:15 by sagemura          #+#    #+#             */
/*   Updated: 2024/12/15 20:02:57 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_file_extension(char *path, t_game *game)
{
	size_t	len;

	len = ft_strlen(path);
	if (path[len - 4] == '.' && path[len - 3] == 'c' && path[len - 2] == 'u'
		&& path[len - 1] == 'b')
		return ;
	goodbye(game, ERROR, "Invalid file extension\n");
}
