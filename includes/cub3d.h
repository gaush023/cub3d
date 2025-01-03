/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:17 by sagemura          #+#    #+#             */
/*   Updated: 2024/09/07 23:45:47 by sagemura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "library.h"
# include "struct.h"
# include "define.h"

extern int x; 

// helper functions
int		print_error(char *error);
void	goodbye(t_game *game, int code, char *msg);
void	ini_texture(t_texinfo *textures);
void	ini_player(t_player *player);
void	ini_mapinfo(t_mapinfo *mapinfo);
void	ini_ray(t_ray *ray);
void set_img_zero(t_img *img);
int		*xpm_to_img(t_game *game, char *path);
bool is_space(char c);
int close_game(t_game *game);

//render functions
void	render_images(t_game *game);
void    render_frame(t_game *game);
int raycasting(t_player *player, t_game *game);
int cub3d_render(t_game *game);

//lib functions
size_t    ft_strlen(char *s);
size_t    ft_strlcpy(char *dst, char *src, size_t dstsize);
char *ft_strchr(const char *s, int c);
int ft_isdigit(int c);
int ft_atoi(char *str);
bool ft_isalpha(int c);
int ft_isalnum(int c);

//read_file functions
void read_file(char *file, t_game *game);
char *get_next_line(int fd, t_game *game);
void    read_map_info(char *file_path, t_game *game);
void    read_texture_info(t_game *game);
void check_file_extension(char *file_path, t_game *game);
void check_file_data(t_game *game);
void get_celling_floor_color(t_game *game);

//move functions
void listen_for_key(t_game *game);
void init_player_direction(t_game *game);
int move_player(t_game *game);
int validate_move(t_game *game, double new_x, double new_y);
int rotate_player(t_game *game, double rotate_direction);


#endif
