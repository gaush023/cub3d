# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sagemura <sagemura@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 02:01:33 by sagemura          #+#    #+#              #
#    Updated: 2024/08/31 03:28:02 by sagemura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRCS = main.c \
	   helpers/check_file.c helpers/goodbye.c helpers/ini.c helpers/xpm_to_img.c \
	   helpers/print_error.c \
	   render/render_images.c \
	   helpers/lib/ft_strlen.c 
	   
MALLOC = malloc_lib.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
OBJS = $(SRCS:./%.c=./%.o)
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
