/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:02 by sagemura          #+#    #+#             */
/*   Updated: 2024/08/28 14:23:03 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void ini_texture(t_texinfo *textures)
{
  textures->floor = 0;
  textures->ceiling = 0;
  textures->hex_floor = 0x0;
  textures->hex_ceiling = 0x0;
  textures->size = TEX_SIZE;
  textures->step = 0.0;
  textures->pos = 0.0;
  textures->x = 0;
  textures->y = 0;
}

void ini_ray(t_ray *ray)
{
  ray->camera_x = 0;
  ray->dir_x = 0;
  ray->dir_y = 0;
  ray->map_x = 0;
  ray->map_y = 0;
  ray->sidedist_x = 0;
  ray->sidedist_y = 0;
  ray->deltadist_x = 0;
  ray->deltadist_y = 0;
  ray->wall_dist = 0;
  ray->wall_x = 0;
  ray->side = 0;
  ray->line_height = 0;
  ray->draw_start = 0;
  ray->draw_end = 0;
}



void ini_player(t_player *player)
{
  player->direction = '\0';
  player->pos_x = 0;
  player->pos_y = 0;
  player->direction_x = 0;
  player->direction_y = 0;
  player->plane_x = 0;
  player->plane_y = 0;
  player->has_moved = 0;
  player->move_x = 0;
  player->move_y = 0;
  player->rotate = 0;
}

void ini_mapinfo(t_mapinfo *mapinfo)
{
  mapinfo->fd = 0;
  mapinfo->line_count = 0;
  mapinfo->path = NULL;
  mapinfo->file = NULL;
  mapinfo->height = 0;
  mapinfo->width = 0;
  mapinfo->index_end_of_map = 0;
}

void set_img_zero(t_img *img)
{
  img->img = NULL;
  img->addr = NULL;
  img->pixel_bits = 0;
  img->size_line = 0;
    img->endian = 0;
}

