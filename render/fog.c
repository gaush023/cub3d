/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:28:34 by shuga             #+#    #+#             */
/*   Updated: 2024/12/15 20:24:16 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int mix_color(int base_color, int fog_color, double factor)
{
    if(factor > 1.0)
        factor = 1.0;
    if(factor < 0.0)
        factor = 0.0;
   
    int r = ((base_color >> 16) & 0xFF) * (1.0 - factor) + ((fog_color >> 16) & 0xFF) * factor;
    int g = ((base_color >> 8) & 0xFF) * (1.0 - factor) + ((fog_color >> 8) & 0xFF) * factor;
    int b = (base_color & 0xFF) * (1.0 - factor) + (fog_color & 0xFF) * factor;

    return ((r << 16) | (g << 8) | b);
}

double calc_fog_factor(double distance, double max_distance)
{
    return distance/ max_distance;
}

