/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:02 by sagemura          #+#    #+#             */
/*   Updated: 2024/09/07 23:03:47 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"


void	set_textures(t_game *game)
{
	game->textures = my_calloc(5, sizeof * game->textures, game->node);
	if (!game->textures)
		goodbye(game, ERROR, "Error allocating memory\n");
	game->textures[NORTH] = xpm_to_img(game->mlx, game->texinfo.north);
	game->textures[SOUTH] = xpm_to_img(game->mlx, game->texinfo.south);
	game->textures[WEST] = xpm_to_img(game->mlx, game->texinfo.west);
	game->textures[EAST] = xpm_to_img(game->mlx, game->texinfo.east);
}

void	set_data(t_game *game)
{
	ini_player(&game->player);
	ini_texture(&game->texinfo);
	set_textures(game);
	game->map = NULL;
	ini_mapinfo(&game->mapinfo);
	game->texture_pixels = NULL;
	game->textures = NULL;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error("Error initializing mlx\n");
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		print_error("Error initializing window\n");
	set_data(game);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks cub3D");
// }

int	main(int ac, char **av)
{
	t_game	game;

	game.node = malloc(sizeof(t_node));
	if (!game.node)
		return (print_error("Error allocating memory\n"));
	malloc_startup(game.node);
	if (ac != 2)
		return (print_error("Invalid number of arguments\n"));
    read_file(av[1], &game);
	game.node = malloc(sizeof(t_node));
	if (!game.node)
		return (print_error("Error allocating memory\n"));
	init_game(&game);
	render_images(&game);
    listen_for_key(&game);
    malloc_end(game.node);
    return (0);
}
