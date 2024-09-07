/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:03:15 by sagemura          #+#    #+#             */
/*   Updated: 2024/08/31 03:21:30 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void check_file_extension(char *file_path, t_game *game)
{
    size_t len;

    len = ft_strlen(file_path);
    if(file_path[len - 4] == '.' && file_path[len - 3] == 'c' && file_path[len - 2] == 'u' && file_path[len - 1] == 'b')
        return ;
    goodbye(game, ERROR, "Invalid file extension\n");
}

