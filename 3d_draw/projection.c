#include "../cub3d.h"

void	draw_sky(t_data *data, double x, double y)
{
	long	color;
	int		i;

	i = 0;
	color = ft_atoi(data->c_rgb[0]) << 16;
	color += ft_atoi(data->c_rgb[1]) << 8;
	color += ft_atoi(data->c_rgb[2]);
	while (i < y)
	{
		my_mlx_pixel_put(data, x, i, color);
		i++;
	}
}

void	draw_floor(t_data *data, double x, double y)
{
	long	color;

	color = ft_atoi(data->f_rgb[0]) << 16;
	color += ft_atoi(data->f_rgb[1]) << 8;
	color += ft_atoi(data->f_rgb[2]);
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}

static void	draw_3d(t_data *data, int x, double wall_strip, unsigned int *addr)
{
	int	y;
	int	j;
	int	distance_from_top;

	y = (HEIGHT / 2) - (wall_strip / 2);
	if (y < 0)
		y = 0;
	j = y;
	draw_sky(data, x, y);
	while (y < j + wall_strip)
	{
		distance_from_top = y + (wall_strip / 2) - (HEIGHT / 2)  ;
		data->texture.of_y = distance_from_top * ((double)64 / wall_strip);
		my_mlx_pixel_put(data, x, y, addr[(unsigned int)(data->texture.of_y * 64) + (unsigned int)data->texture.of_x]);
		y++;
		if (y > HEIGHT)
			break ;
	}
	draw_floor(data, x, y);
}

void	projection(t_data *data, int i, unsigned int *addr)
{
	double	raydistance;
	double	distance_proj_plane;
	double	wall_strip;

	raydistance = data->rays.distance;
	distance_proj_plane = (WIDTH / 2) / tan(data->rays.view_angle / 2);
	if (raydistance < 1)
		raydistance = 1;
	wall_strip = (64 / raydistance) * distance_proj_plane;
	draw_3d(data, i, wall_strip, addr);
}
