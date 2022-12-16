# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 15:23:24 by hbouqssi          #+#    #+#              #
#    Updated: 2022/12/16 18:24:03 by sismaili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D
GCC = gcc -Wall -Wextra -Werror -Ofast
SRC = main.c \
	tools/ft_strlen.c \
	parsing/valid_path.c
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