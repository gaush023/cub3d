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

static void set_texture_zero(t_img *img)
{
  img->img = NULL;
  img->addr = NULL;
  img->bits_per_pixel = 0;
  img->line_length = 0;
  img->endian = 0;
}

static void ini_texture_img(t_game *game, t_img *image, char *path)
{
  set_texture_zero(image);
  image->img = mlx_xpm_file_to_image(game->mlx, path, &game->texinfo.size, &game->texinfo.size);
  if (!image->img)
    goodbye(game, ERROR, "Error loading texture\n");
  image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits, &image->size_line, &image->endian);
}

int xpm_to_img(t_game *game, char *path){ 
{
    t_img *tmp;
    int *buffer;
    int x;
    int y;

    ini_texture_img(gaem, &tmp, path);
    buffer = my_calloc(1, sizeof * buffer * game->texinfo.size * game->texinfo.size);
    if (!buffer)
      goodbye(game, ERROR, "Error allocating memory\n");
    y = 0;
    while(y < game->texinfo.size)
    {
      x = 0;
      while(x < game->texinfo.size)
      {
        buffer[y * game->texinfo.size + x] =  tmp.addr[y * data->texinfo.size + x];
        ++x;
      }
      y++;
    }
    mlx_destroy_image(game->mlx, tmp.img);
    return (buffer);
              
}

