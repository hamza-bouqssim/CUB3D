# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 15:23:24 by hbouqssi          #+#    #+#              #
#    Updated: 2022/12/17 20:21:18 by hbouqssi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D
GCC = gcc -Wall -Wextra -Werror -Ofast
SRC = main.c \
	tools/ft_strlen.c \
	parsing/valid_path.c \
	tools/get_next_line.c \
	tools/get_next_line_utils.c \
	tools/ft_split.c
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) 
	$(GCC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c cub3d.h ../get_next_line.h
	$(GCC) -c $< -o $@

bonus: all

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all fclean clean re