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
    printf("game->mlx: %p\n", game->mlx);
    game->textures[NORTH] = xpm_to_img(game, game->texinfo.north);
    game->textures[SOUTH] = xpm_to_img(game, game->texinfo.south);
    game->textures[WEST] = xpm_to_img(game, game->texinfo.west);
    game->textures[EAST] = xpm_to_img(game, game->texinfo.east);
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
    printf("mlx: %p\n", game->mlx);
    printf("WIN_WIDTH: %d\n", WIN_WIDTH);
    printf("WIN_HEIGHT: %d\n", WIN_HEIGHT);
    game->window_width = WIN_WIDTH;
    game->window_height = WIN_HEIGHT;
    game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		print_error("Error initializing window\n");
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
    set_data(&game);
    render_images(&game);
    mlx_loop_hook(game.mlx, cub3d_render, &game);
    mlx_loop(game.mlx);
    listen_for_key(&game);
    malloc_end(game.node);
    return (0);
}
