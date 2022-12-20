/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:19 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/12/20 20:51:44 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# define BUFFER_SIZE 1
# define HEIGHT 1000
# define WIDTH 1000

//keys
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define ESC 53
# define PLUS 69
# define MINES 78
# define C 8
//________________________

//___________ Lists
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_data
{
    void *mlx;
    void *win;
    int Columns;
    int Rows;
    int x;
    int y;
    int i;
    int j;
    int xp;
    int yp;
    int ap;
    int bp;
    int playerX;
    int playerY;
    double player_x;
    double player_y;
    char **splitted_array;
    t_image img;
}   t_data;

//________________________
//___________ f_prototypes
char	*get_next_line(int fd);
int     ft_strlen(char *str);
int	    valide_path(char *path);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup( char *s1);
char	**ft_split(char const *s, char c);
int ft_countRows(char **str);
//________________________
#endif