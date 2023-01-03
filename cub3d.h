/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:19 by hbouqssi          #+#    #+#             */
/*   Updated: 2023/01/03 01:27:42 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx_lib/mlx.h"
# include <fcntl.h>
# include <limits.h>

# define BUFFER_SIZE 1
# define HEIGHT 1300
# define WIDTH 1300

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
    double	x1;
    double	y1;
	double	rot_angle;
	double	rot_speed;
	double	move_speed;
	double	direction;
	double	turn;
}	t_player;

typedef struct s_rays
{
	double	view_angle;
	double	num_rays;
	double	ray_angle;
	double	xintercept;
	double	yintercept;
	double	xstep;
	double	ystep;
	double	h_wall_x;
	double	h_wall_y;
	double	v_wall_x;
	double	v_wall_y;
	double	wall_x;
	double	wall_y;
	double	h_distance;
	double	v_distance;
	double	distance;
	int		is_down;
	int		is_right;
}	t_rays;

typedef	struct	s_texture
{
	t_image			no;
	t_image			so;
	t_image			we;
	t_image			ea;
	void			*no_img;
	unsigned int	*no_addr;
	int				no_width;
	int				no_height;
	void			*so_img;
	unsigned int	*so_addr;
	int				so_width;
	int				so_height;
	void			*we_img;
	unsigned int	*we_addr;
	int				we_width;
	int				we_height;
	void			*ea_img;
	unsigned int	*ea_addr;
	int				ea_width;
	int				ea_height;
	int			of_x;
	int			of_y;
}	t_texture;

typedef struct s_data
{
    void *mlx;
    void *win;
    int Columns;
    int Rows;
	int	width;
	int	height;
	int	scale;
	int	scale_3d;
    int w_pressed;
    int a_pressed;
    int s_pressed;
    int d_pressed;
    int ri_pressed;
    int le_pressed;
	t_player	player;
	t_rays	rays;
    t_image img;
	t_texture	texture;
	char	*line;
	char	**spl;
	char	**elements;
	char	**map;
	char	**f_rgb;
	char	**c_rgb;
	char	**path;
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
int 	ft_count_rows(char **str);
int		ft_count_columns(char **str);
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
void	my_mlx_pixel_put2(t_data *data, int x, int y, int color);
void    draw(t_data *data, int color, double x, double y);
void    minimap_draw(t_data *data);
int     ft_keys(t_data *data);
int     ft_moves(t_data *data);
int		ft_pressed(int key, t_data *data);
int		ft_released(int key, t_data *data);
void	w_move(t_data *data);
void	s_move(t_data *data);
void	d_move(t_data *data);
void	a_move(t_data *data);
int		wall_check(t_data *data, double y, double x);
void	draw_rays(t_data *data);
void	horizontal_init(t_data *data, int column);
void	vertical_init(t_data *data, int column);
double	distance_points(double x1, double y1, double x2, double y2);
void	projection(t_data *data, int i , unsigned int *addr);
void	wall_project(t_data *data);
void	all_draw(t_data *data);
void	init_rays(t_data *data);
void	get_add_image(t_data *data);
// void	texture_draw(t_data *data);
//________________________

#endif