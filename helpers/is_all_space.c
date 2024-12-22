/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:22:33 by shuga             #+#    #+#             */
/*   Updated: 2024/12/22 16:22:43 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_all_space(char *line)
{
	size_t i;

	i = 0;
	while (line[i] != '\n')
	{
		if (!is_space(line[i]))
			return (false);
		i++;
	}
	return (true);
}