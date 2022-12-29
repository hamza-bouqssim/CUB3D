# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 15:23:24 by hbouqssi          #+#    #+#              #
#    Updated: 2022/12/29 20:29:00 by sismaili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
GCC = gcc -Wall -Wextra -Werror -Ofast
SRC = main.c \
	tools/ft_strlen.c \
	tools/ft_split.c \
	tools/ft_strdup.c \
	tools/ft_strcmp.c \
	tools/ft_free.c \
	tools/ft_atoi.c \
	tools/is_digit.c \
	parsing/valid_path.c \
	parsing/fill_spl.c \
	parsing/elements_check.c \
	parsing/map_check.c \
	tools/get_next_line.c \
	tools/get_next_line_utils.c \
	minimap/draw_rays.c \
	minimap/horizontal_check.c \
	minimap/vertical_check.c \
	minimap/drawing_functions.c \
	movements/key_hooks.c \
	movements/moves.c \
	utils.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

%.o: %.c cub3d.h
	$(GCC) -c $< -o $@ -g

$(NAME): $(OBJ) 
	$(GCC) $(OBJ) -g -lmlx -framework OpenGL -framework AppKit -o  $(NAME)

bonus: all

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all fclean clean re