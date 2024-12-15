/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:03:15 by sagemura          #+#    #+#             */
/*   Updated: 2024/12/15 20:07:59 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_file_extension(char *path)
{
	size_t	len;

	len = ft_strlen(file_path);
	if (path[len - 4] == '.' && path[len - 3] == 'c' && path[len - 2] == 'u'
		&& path[len - 1] == 'b')
		goodbye("Invalid file extension\n");
}
