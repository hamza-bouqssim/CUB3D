/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:19 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/12/24 19:45:28 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
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

typedef struct s_player
{
    double	x;
    double	y;
	double	rot_angle;
	double	see_angle;
	double	rot_speed;
	double	move_speed;
	double	direction;
	double	turn;
}	t_player;

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
    char **splitted_array;
	t_player	player;
    t_image img;
	char	*line;
	char	**spl;
	char	**elements;
	char	**map;
}   t_data;

//________________________
//___________ f_prototypes
char	*get_next_line(int fd);
int     ft_strlen(char *str);
int		valide_path(char *path, char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup( char *s1);
char	**ft_split(char const *s, char c);
int 	ft_countRows(char **str);
void	fill_spl(t_data *data, int fd);
int		ft_isspace(int c);
int		ft_strcmp(const char *s1, const char *s2);
void    ft_free(char **spl);
int		ft_atoi(const char *str);
int		is_digit(char *str);
int		check_elements(t_data *data);
int		map_check(t_data *data);
int     close_win(void *param);
void	image(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    draw(t_data *data, int color, int scale, double x, double y);
void    draw_player(t_data *data, int color, int scale, double x, double y);
void    draw_map(t_data *data);
int     ft_keys(int keycode, t_data *data);
int     ft_moves(int key, t_data *data);
//________________________

#endif