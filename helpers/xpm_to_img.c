/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:02 by sagemura          #+#    #+#             */
/*   Updated: 2024/12/15 20:56:22 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ini_texture_img(t_game *game, t_img *image, char *path)
{
	set_img_zero(image);
	image->img = mlx_xpm_file_to_image(game->mlx, path, &game->texinfo.size,
			&game->texinfo.size);
	if (!image->img)
		goodbye(game, ERROR, "loading texture\n");
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
}

int	*xpm_to_img(t_game *game, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	ini_texture_img(game, &tmp, path);
	buffer = calloc(1, sizeof * (buffer) * game->texinfo.size
			* game->texinfo.size);
	if (!buffer)
		goodbye(game, ERROR, "allocating memory\n");
	y = 0;
	while (y < game->texinfo.size)
	{
		x = 0;
		while (x < game->texinfo.size)
		{
			buffer[y * game->texinfo.size + x] = tmp.addr[y * game->texinfo.size
				+ x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, tmp.img);
	return (buffer);
}
