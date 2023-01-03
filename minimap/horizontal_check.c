#include "../cub3d.h"

static void	distance_init(t_data *data, int found_wall)
{
	if (found_wall)
	data->rays.h_distance = distance_points(data->player.x, data->player.y,
				data->rays.h_wall_x, data->rays.h_wall_y);
	else
		data->rays.h_distance = INT_MAX;
}

static void	horizontal_check(t_data *data, double next_x, double next_y)
{
	int		found_wall;

	found_wall = 0;
	while (next_x >= 0 && next_x <= data->width
		&& next_y >= 0 && next_y <= data->height)
	{
		if (wall_check(data, next_y - (!data->rays.is_down), next_x))
		{
			found_wall = 1;
			data->rays.h_wall_x = next_x;
			data->rays.h_wall_y = next_y;
			break ;
		}
		else
		{
			next_x += data->rays.xstep;
			next_y += data->rays.ystep;
		}
	}
	distance_init(data, found_wall);
}

void	horizontal_init(t_data *data, int column)
{
	double	next_x;
	double	next_y;

	(void)column;
	data->rays.h_wall_x = 0;
	data->rays.h_wall_y = 0;
	data->rays.yintercept = floor(data->player.y / data->scale_3d) * data->scale_3d;
	if (data->rays.is_down)
		data->rays.yintercept += data->scale_3d;
	data->rays.xintercept = data->player.x
		+ (data->rays.yintercept - data->player.y) / tan(data->rays.ray_angle);
	data->rays.ystep = data->scale_3d;
	if (!data->rays.is_down)
		data->rays.ystep *= -1;
	data->rays.xstep = data->scale_3d / tan(data->rays.ray_angle);
	if (!data->rays.is_right && data->rays.xstep > 0)
		data->rays.xstep *= -1;
	else if (data->rays.is_right && data->rays.xstep < 0)
		data->rays.xstep *= -1;
	next_x = data->rays.xintercept;
	next_y = data->rays.yintercept;
	horizontal_check(data, next_x, next_y);
}
