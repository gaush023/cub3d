/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:05:03 by shuga             #+#    #+#             */
/*   Updated: 2024/12/15 20:05:21 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_atoi(char *str, t_game *game)
{
	int	i;
	int	sign;
	int	result;
    bool    has_digit;

	i = 0;
	sign = 1;
	result = 0;
    has_digit = false;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
        has_digit = true;
		result = result * 10 + str[i] - '0';
		i++;
	}
    if (!has_digit)
        goodbye(game, ERROR, "Invalid rgb\n");
    return (result * sign);
}
