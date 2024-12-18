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

void	init_raycasting_info(int x, t_ray *ray, t_player *player, t_game *game)
{
	(void)game;
	ini_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = player->direction_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->direction_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->deltadist_x = fabs(1.0 / ray->dir_x);
	ray->deltadist_y = fabs(1.0 / ray->dir_y);
}

static void	caluc_line_height(t_ray *ray, t_player *player, t_game *game)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(game->window_height / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + game->window_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->window_height / 2;
	if (ray->draw_end >= game->window_height)
		ray->draw_end = game->window_height - 1;
	if (ray->side == SIDE_X)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	get_texture_index(t_game *game, t_ray *ray)
{
	if (ray->side == SIDE_X)
	{
		if (ray->dir_x < 0)
			game->texinfo.index = WEST;
		else
			game->texinfo.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			game->texinfo.index = SOUTH;
		else
			game->texinfo.index = NORTH;
	}
}

#define MAX_DISTANCE 8.0
#define FOG_COLOR 0x333333 

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


void	update_texture_pixel(t_game *game, t_texinfo *tex, t_ray *ray, int x)
{
	int	y;
	int	color;
    double fog_factor;

    color = 0;
	get_texture_index(game, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1
			&& ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - game->window_height / 2 + ray->line_height
			/ 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = game->textures[tex->index][tex->y * tex->size + tex->x];
		if (tex->index == NORTH || tex->index == SOUTH)
			color = (color >> 1) & GREY;
        fog_factor = calc_fog_factor(ray->wall_dist, MAX_DISTANCE);
        color = mix_color(color, FOG_COLOR, fog_factor);
        if(color > 0)
            game->texture_pixels[y][x] = color;
		y++;
	}
}

int	raycasting(t_player *player, t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;

    while (x < game->window_width)
	{
		init_raycasting_info(x, &ray, player, game);
		set_dda(&ray, player);
		perform_dda(game, &ray);
		 if (ray.wall_dist > 10)
        {
            int y = 0;
            while (y < game->window_height)
            {
                game->texture_pixels[y][x] = 0x000000; // 真っ暗に描画
                y++;
            }
            x++;
            continue;
        }

        caluc_line_height(&ray, player, game);
		update_texture_pixel(game, &game->texinfo, &ray, x);
		x++;
	}
	return (SUCCESS);
}
