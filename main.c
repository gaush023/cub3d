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

#include "cub3d.h"

static void ini_texture(t_texinfo *textures)
{
  textures->north = NULL;
  textures->south = NULL;
  textures->west = NULL;
  textures->east = NULL;
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

static void ini_player(t_player *player)
{
  player->direction = "\0";
  player->pos_x = 0;
  player->pos_y = 0;
  player->direction_x = 0;
  player->direction_y = 0;
  player->plane_x = 0;
  player->plane_y = 0;
  player->has_moved = 0;
  player->mov_x = 0;
  player->mov_y = 0;
  player->rotate = 0;
}

static void ini_mapinfo(t_mapinfo *mapinfo)
{
  mapinfo->fd = 0;
  mapinfo->line_count = 0;
  mapinfo->path = NULL;
  mapinfo->file = NULL;
  mapinfo->height = 0;
  mapinfo->width = 0;
  mapinfo->index_end_of_map = 0;
}

void set_textures(t_game *game)
{
  game->textures = my_calloc(5, sizeof(t_texinfo));
  if (!game->textures)
    goodbye(game, ERROR, "Error allocating memory\n");
  game->textures[NORTH] = xpm_to_image(game->mlx, game->textures[NORTH], game->textures.north);
  game->textures[SOUTH] = xpm_to_image(game->mlx, game->textures[SOUTH], game->textures.south);
  game->textures[WEST] = xpm_to_image(game->mlx, game->textures[WEST], game->textures.west);
  game->textures[EAST] = xpm_to_image(game->mlx, game->textures[EAST], game->textures.east);

}

void set_data(t_game *game)
{
  ini_player(game->player);
  ini_texture(game->textures);
  set_textures(game);
  game->map = NULL;
  ini_mapinfo(game->mapinfo);
  game->textures_pixel = NULL; 
  game->textures = NULL;
}


void init_game(t_game *game)
{
  game->mlx = mlx_init();
  if (!game->mlx)
    print_error("Error initializing mlx\n");
  game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D"); 
  if (!game->win)
    print_error("Error initializing window\n");
  set_data(game);
  mlx_loop(game->mlx);
  

}

int	main(int ac, char **av)
{
  t_game game;

	if (ac != 2)
		return (print_error("Invalid number of arguments\n"));
	if (check_parse(av[1]) == ERROR)
		return (print_error("Error parsing the file\n"));
  game.node = malloc(sizeof(t_node));
  if (!game.node)
    return (print_error("Error allocating memory\n"));
  malloc_startup(game.node);
  init_game(&game);


  malloc_end(game.node);
  return (0);
}
