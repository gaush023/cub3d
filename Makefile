# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 0:w
#    2:01:33 by sagemura          #+#    #+#              #
#    Updated: 2024/09/07 21:37:26 by sagemura         ###   ########.fr        #
#                                                                              #j
# **************************************************************************** #

NAME = cub3D
SRCS = main.c \
	   helpers/is_all_space.c helpers/free_tab.c helpers/goodbye.c helpers/ini.c helpers/xpm_to_img.c helpers/print_error.c helpers/is_space.c helpers/close_game.c \
	   render/get_texture_index.c render/fog.c render/dda.c render/render_images.c render/raycasting.c render/render_frame.c\
	   helpers/lib/ft_strndup.c helpers/lib/ft_strlen.c helpers/lib/ft_strchr.c helpers/lib/ft_strdup.c helpers/lib/ft_strjoin.c  helpers/lib/ft_strlcpy.c helpers/lib/ft_isdigit.c helpers/lib/ft_atoi.c helpers/lib/ft_isalpha.c helpers/lib/ft_isalnum.c\
	   read_file/save_mapinfo_width_height.c read_file/read_file.c read_file/get_player_position.c read_file/is_four_xpmlines.c read_file/check_file_extension.c read_file/check_file_data.c read_file/read_map_info.c read_file/get_next_line.c read_file/get_celling_floor_color.c\
	   movement/check_player_pos.c movement/init_player_direction.c movement/key_handler.c movement/move_player.c movement/rotate_player.c 

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS =  -L./minilibx-linux -lmlx -lXext -lX11 -lm 
#MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS) $(MLXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
