/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:17 by sagemura          #+#    #+#             */
/*   Updated: 2024/08/31 03:22:10 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "library.h"
# include "struct.h"
# include "define.h"

// helper functions
int		print_error(char *error);
int		check_file(char *file_path);
void	goodbye(t_game *game, int code, char *msg);
void	ini_texture(t_texinfo *textures);
void	ini_player(t_player *player);
void	ini_mapinfo(t_mapinfo *mapinfo);
void	ini_ray(t_ray *ray);
void set_img_zero(t_img *img);
int		*xpm_to_img(t_game *game, char *path);

//render functions
void	render_images(t_game *game);
void    render_frame(t_game *game);
//lib functions
size_t    ft_strlen(const char *s);

//read_file functions
void read_file(char *file, t_game *game);

#endif
