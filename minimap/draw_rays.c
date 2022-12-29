#include "../cub3d.h"

double	distance_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

static void	ray_line(t_data *data, double x1, double y1)
{
	double	x;
	double	y;
	double	x_inc;
	double	y_inc;
	int		steps;

	x = data->player.x;
	y = data->player.y;
	steps = fmax(fabs(x1 - x), fabs(y1 - y));
	x_inc = (x1 - x) / (double)steps;
	y_inc = (y1 - y) / (double)steps;
	while (steps > 0)
	{
		my_mlx_pixel_put(data, x, y, 0xFFA500);
		x += x_inc;
		y += y_inc;
		steps--;
	}
}

static void	get_distance(t_data *data)
{
	if (data->rays.h_distance < data->rays.v_distance)
	{
		data->rays.wall_x = data->rays.h_wall_x;
		data->rays.wall_y = data->rays.h_wall_y;
		data->rays.distance = data->rays.h_distance;
	}
	else
	{
		data->rays.wall_x = data->rays.v_wall_x;
		data->rays.wall_y = data->rays.v_wall_y;
		data->rays.distance = data->rays.v_distance;
	}
}

static void	init_rays(t_data *data)
{
	data->rays.view_angle = 60 * (M_PI / 180);
	data->rays.num_rays = data->width;
	data->rays.ray_angle = data->player.rot_angle - (data->rays.view_angle / 2);
	data->rays.ray_angle = fmod(data->rays.ray_angle, 2 * M_PI);
	if (data->rays.ray_angle < 0)
		data->rays.ray_angle = (2 * M_PI) + data->rays.ray_angle;
	data->rays.wall_x = 0;
	data->rays.wall_y = 0;
	data->rays.distance = 0;
	data->rays.is_down = 0;
	data->rays.is_right = 0;
	if (data->rays.ray_angle > 0 && data->rays.ray_angle < M_PI)
		data->rays.is_down = 1;
	if (data->rays.ray_angle < M_PI / 2 || data->rays.ray_angle > 3 * M_PI / 2)
		data->rays.is_right = 1;
}

void	draw_rays(t_data *data)
{
	int	i;

	i = 0;
	init_rays(data);
	while (i < data->rays.num_rays)
	{
		data->rays.is_down = 0;
		data->rays.is_right = 0;
		if (data->rays.ray_angle > 0 && data->rays.ray_angle < M_PI)
			data->rays.is_down = 1;
		if (data->rays.ray_angle < M_PI / 2
			|| data->rays.ray_angle > 3 * M_PI / 2)
			data->rays.is_right = 1;
		data->rays.ray_angle = fmod(data->rays.ray_angle, 2 * M_PI);
		if (data->rays.ray_angle < 0)
			data->rays.ray_angle = (2 * M_PI) + data->rays.ray_angle;
		horizontal_init(data, i);
		vertical_init(data, i);
		get_distance(data);
		ray_line(data, data->rays.wall_x, data->rays.wall_y);
		data->rays.ray_angle += data->rays.view_angle / data->rays.num_rays;
		i++;
	}
}
