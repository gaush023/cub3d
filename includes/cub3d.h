/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuga <shuga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:28:17 by sagemura          #+#    #+#             */
/*   Updated: 2024/12/15 20:56:31 by shuga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "define.h"
# include "library.h"
# include "struct.h"

// helper functions
int		print_error(char *error);
void	goodbye(t_game *game, int code, char *msg);
void	ini_texture(t_texinfo *textures);
void	ini_player(t_player *player);
void	ini_mapinfo(t_mapinfo *mapinfo);
void	ini_ray(t_ray *ray);
void	set_img_zero(t_img *img);
int		*xpm_to_img(t_game *game, char *path);
bool	is_space(char c);
int		close_game(t_game *game);
void	free_tab(void **tab);

//render functions
void	render_images(t_game *game);
void	render_frame(t_game *game);
int		raycasting(t_player *player, t_game *game);
int		cub3d_render(t_game *game);
void	perform_dda(t_game *game, t_ray *ray);
void	set_dda(t_ray *ray, t_player *player);

//lib functions
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdub(char *str);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
bool	ft_isalpha(int c);
int		ft_isalnum(int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

//read_file functions
void	read_file(char *file, t_game *game);
char	*get_next_line(int fd);
void	read_map_info(char *file_path, t_game *game);
void	check_file_extension(char *file_path, t_game *game);
void	check_file_data(t_game *game);
void	get_celling_floor_color(t_game *game);
bool	is_four_xpmlines(t_game *game);
void	save_mapinfo_width_height(t_game *game, size_t map_start_row);
void	get_player_position(t_game *game);

//move functions
void	listen_for_key(t_game *game);
void	init_player_direction(t_game *game);
int		move_player(t_game *game);
int		validate_move(t_game *game, double new_x, double new_y);
int		rotate_player(t_game *game, double rotate_direction);

#endif
