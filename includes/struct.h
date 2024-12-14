/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:17 by sagemura          #+#    #+#             */
/*   Updated: 2024/12/11 01:36:01 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
#include "library.h"

enum e_direction
{
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3
};

typedef struct s_player
{
  char direction;
  double pos_x;
  double pos_y;
  double direction_x;
  double direction_y;
  double plane_x;
  double plane_y;
  int has_moved;
  int move_x;
  int move_y;
  int rotate;
} t_player;

typedef struct s_texinfo
{
  char *north;
  char *south;
  char *west;
  char *east;
  int *floor;
  int *ceiling;
  unsigned long hex_floor;
  unsigned long hex_ceiling;
  int size;
  int index;
  double step;
  double pos;
  int x;
  int y;
} t_texinfo;

typedef struct s_mapinfo
{
  int fd;
  int line_count;
  char *path;
  char **file;
  int height;
  int width;
  int index_end_of_map;
} t_mapinfo;

typedef struct s_ray
{
  double camera_x;
  double dir_x;
  double dir_y;
  int map_x;
  int map_y;
  int step_x;
  int step_y;
  double sidedist_x;
  double sidedist_y;
  double deltadist_x;
  double deltadist_y;
  double wall_dist;
  double wall_x;
  int side;
  int line_height;
  int draw_start;
  int draw_end;
} t_ray;

typedef struct s_img
{
  void *img;
  int *addr;
  int pixel_bits;
  int size_line;
  int endian;
} t_img;

typedef struct s_game
{
  void *mlx;
  void *win;
  int window_width;
  int window_height;
  t_player player;
  t_mapinfo mapinfo;
  t_texinfo texinfo;
  t_ray ray;
  char **map;
  int **texture_pixels;
  int **textures;
} t_game;

#endif
