/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:17 by sagemura          #+#    #+#             */
/*   Updated: 2024/08/28 14:06:59 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H 
# define STRUCT_H

enum e_direction
{
  NORTH = 0,
  SOUTH = 1,
  WEST = 2,
  EAST = 3
};

typdef struct s_player
{
  char *direction;
  double pos_x;
  double pos_y;
  double direction_x;
  double direction_y;
  double plane_x;
  double plane_y;
  int has_moved;
  int mov_x;
  int mov_y;
  int rotate;
} t_player;

typdef struct s_texinfo
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

typdef struct s_mapinfo
{
  int fd;
  int line_count;
  char *path;
  char **file;
  int height;
  int width;
  int index_end_of_map;
} t_mapinfo;

typedef struct s_game
{
  void *mlx;
  void *win;
  t_player *player;
  char **map;
  int **texture_pixels;
  int **textures;
} t_game;

#endif
