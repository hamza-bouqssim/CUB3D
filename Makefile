# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 15:23:24 by hbouqssi          #+#    #+#              #
#    Updated: 2022/12/20 21:49:47 by sismaili         ###   ########.fr        #
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
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) 
	$(GCC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c cub3d.h
	$(GCC) -c $< -o $@

bonus: all

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all fclean clean re