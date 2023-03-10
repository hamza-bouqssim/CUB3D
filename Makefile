# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 15:23:24 by hbouqssi          #+#    #+#              #
#    Updated: 2023/01/06 15:30:31 by sismaili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
GCC = cc -Wall -Wextra -Werror
MLX = mlx_lib/libmlx.a
SRC = main.c \
	ft_inits.c \
	all_draw.c \
	wall_check.c \
	tools/ft_strlen.c \
	tools/ft_split.c \
	tools/ft_strdup.c \
	tools/ft_strcmp.c \
	tools/ft_free.c \
	tools/ft_atoi.c \
	tools/is_digit.c \
	tools/ft_calloc.c \
	parsing/valid_path.c \
	parsing/fill_spl.c \
	parsing/elements_check.c \
	parsing/map_check.c \
	tools/get_next_line.c \
	tools/get_next_line_utils.c \
	minimap/minimap_draw.c \
	movements/key_hooks.c \
	movements/moves.c \
	3d_draw/horizontal_check.c \
	3d_draw/vertical_check.c \
	3d_draw/3d_draw.c \
	3d_draw/projection.c \
	utils.c \
	texture.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

%.o: %.c cub3d.h
	$(GCC) -c $< -o $@

$(NAME): $(OBJ) 
	$(GCC) $(OBJ) $(MLX) -g -lmlx -framework OpenGL -framework AppKit -o  $(NAME)

bonus: all

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all fclean clean re