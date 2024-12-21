/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:02 by sagemura          #+#    #+#             */
/*   Updated: 2024/12/11 02:39:31 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	set_textures(t_game *game)
{
	game->textures = calloc(5, sizeof * game->textures);
	if (!game->textures)
		goodbye(game, ERROR, "Error allocating memory\n");
    game->textures[NORTH] = xpm_to_img(game, game->texinfo.north);
	game->textures[SOUTH] = xpm_to_img(game, game->texinfo.south);
	game->textures[WEST] = xpm_to_img(game, game->texinfo.west);
    game->textures[EAST] = xpm_to_img(game, game->texinfo.east);
}

void	set_data(t_game *game)
{
	set_textures(game);
	game->texture_pixels = NULL;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	init_player_direction(game);
	if (!game->mlx)
		print_error("Error initializing mlx\n");
	game->window_width = WIN_WIDTH;
	game->window_height = WIN_HEIGHT;
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win)
		print_error("Error initializing window\n");
}

int	main(int ac, char **av)
{
	t_game	game;
    
    gettimeofday(&game.last_time, NULL);
	if (ac != 2)
		return (print_error("Invalid number of arguments\n"));
	read_file(av[1], &game);
	init_game(&game);
	set_data(&game);
	render_images(&game);
	listen_for_key(&game);
	mlx_loop_hook(game.mlx, cub3d_render, &game);
	mlx_loop(game.mlx);
	return (0);
}
