#include "../cub3d.h"

static void	distance_init(t_data *data, int found_wall)
{
	if (found_wall)
	data->rays.v_distance = distance_points(data->player.x, data->player.y,
				data->rays.v_wall_x, data->rays.v_wall_y);
	else
		data->rays.v_distance = INT_MAX;
}

static void	vertical_check(t_data *data, double next_x, double next_y)
{
	int	found_wall;

	found_wall = 0;
	next_x = data->rays.xintercept;
	next_y = data->rays.yintercept;
	while (next_x >= 0 && next_x <= 49 * data->scale
		&& next_y >= 0 && next_y <= 45 * data->scale)
	{
		if (wall_check(data, next_y, next_x - (!data->rays.is_right)))
		{
			found_wall = 1;
			data->rays.v_wall_x = next_x;
			data->rays.v_wall_y = next_y;
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

void	vertical_init(t_data *data, int column)
{
	double	next_x;
	double	next_y;

	(void)column;
	data->rays.v_wall_x = 0;
	data->rays.v_wall_y = 0;
	next_x = 0;
	next_y = 0;
	data->rays.xintercept = floor(data->player.x / data->scale) * data->scale;
	if (data->rays.is_right)
		data->rays.xintercept += data->scale;
	data->rays.yintercept = data->player.y
		+ (data->rays.xintercept - data->player.x) * tan(data->rays.ray_angle);
	data->rays.xstep = data->scale;
	if (!data->rays.is_right)
		data->rays.xstep *= -1;
	data->rays.ystep = data->scale * tan(data->rays.ray_angle);
	if (!data->rays.is_down && data->rays.ystep > 0)
		data->rays.ystep *= -1;
	else if (data->rays.is_down && data->rays.ystep < 0)
		data->rays.ystep *= -1;
	vertical_check(data, next_x, next_y);
}
