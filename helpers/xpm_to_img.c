/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:02 by sagemura          #+#    #+#             */
/*   Updated: 2024/08/31 02:21:52 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void ini_texture_img(t_game *game, t_img *image, char *path)
{
    set_img_zero(image);
    printf("path: %s\n", path);
    printf("loading texture\n");
    printf("game->mlx: %p\n", game->mlx);
    image->img = mlx_xpm_file_to_image(game->mlx, path, &game->texinfo.size, &game->texinfo.size);
    printf("done\n");
    if (!image->img)
        goodbye(game, ERROR, "Error loading texture\n");
    image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits, &image->size_line, &image->endian);
    printf("image->pixel_bits: %d\n", image->pixel_bits);
    printf("image->size_line: %d\n", image->size_line);
    printf("image->endian: %d\n", image->endian);
    printf("image->addr: %p\n", image->addr);
    printf("image->img: %p\n", image->img);
    printf("game->texinfo.size: %d\n", game->texinfo.size);
}

int *xpm_to_img(t_game *game, char *path)
{
    t_img tmp;
    int *buffer;
    int x;
    int y;

    ini_texture_img(game, &tmp, path);
    buffer = my_calloc(1, sizeof * buffer * game->texinfo.size * game->texinfo.size, game->node);
    if (!buffer)
      goodbye(game, ERROR, "Error allocating memory\n");
    y = 0;
    while(y < game->texinfo.size)
    {
      x = 0;
      while(x < game->texinfo.size)
      {
        buffer[y * game->texinfo.size + x] =  tmp.addr[y * game->texinfo.size + x];
        ++x;
      }
      y++;
    }
    mlx_destroy_image(game->mlx, tmp.img);
    return (buffer);
}

