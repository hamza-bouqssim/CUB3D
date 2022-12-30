#include "../cub3d.h"

static void	draw_3d(t_data *data, int color, double x, double wall_strip)
{
	double	y;
	double	j;

	y = (HEIGHT / 2) - (wall_strip / 2);
	if (y < 0)
		y = 0;
	j = y;
	while (y < j + wall_strip)
	{
		my_mlx_pixel_put(data, x, y, color);
		y++;
		if (y > HEIGHT)
			break ;
	}
}

void	projection(t_data *data, int i, int color)
{
	double	raydistance;
	double	distance_proj_plane;
	double	wall_strip;

	raydistance = data->rays.distance;
	distance_proj_plane = (WIDTH / 2) / tan(data->rays.view_angle / 2);
	if (raydistance < 1)
		raydistance = 1;
	wall_strip = (data->scale / raydistance) * distance_proj_plane;
	draw_3d(data, color, i, wall_strip);
}
