/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:03:15 by sagemura          #+#    #+#             */
/*   Updated: 2024/08/28 14:14:05 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool check_file_extension(char *file_path)
{
    size_t len;

    len = ft_strlen(file_path);
    if(file_path[len - 4] == '.' && file_path[len - 3] == 'c' && file_path[len - 2] == 'u' && file_path[len - 1] == 'b')
        return (true);
    return (false);
}

int	check_parse(char *file_path)
{
    if(!check_file_extension(file_path))
        return (print_error("Invalid file extension"));
    
}