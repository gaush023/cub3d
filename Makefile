# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 02:01:33 by sagemura          #+#    #+#              #
#    Updated: 2024/09/07 21:37:26 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRCS = main.c \
	   helpers/goodbye.c helpers/ini.c helpers/xpm_to_img.c helpers/print_error.c helpers/is_space.c \
	   render/render_images.c render/raycasting.c render/render_frame.c\
	   helpers/lib/ft_strlen.c helpers/lib/ft_strchr.c  helpers/lib/ft_strlcpy.c \
	   read_file/read_file.c  read_file/check_file_extension.c read_file/check_file_data.c read_file/read_map_info.c read_file/read_texture_info.c read_file/get_next_line.c \


MALLOC = malloc_lib.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
MALLOC_DIR = ./helpers/malloc_lib

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MALLOC_DIR)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) $(MALLOC_DIR)/$(MALLOC)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(MALLOC_DIR)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(MALLOC_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
