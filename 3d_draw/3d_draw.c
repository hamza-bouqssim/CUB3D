#include "../cub3d.h"

static void	get_distance(t_data *data, int i)
{
	if (data->rays.h_distance < data->rays.v_distance)
	{
		data->rays.wall_x = data->rays.h_wall_x;
		data->rays.wall_y = data->rays.h_wall_y;
		data->rays.distance = data->rays.h_distance
			* cos(data->player.rot_angle - data->rays.ray_angle);
		data->text.of_x = (int)data->rays.wall_x % 64;
		if (data->rays.is_down)
			projection(data, i, data->text.no_addr);
		else
			projection(data, i, data->text.so_addr);
	}
	else
	{
		data->rays.wall_x = data->rays.v_wall_x;
		data->rays.wall_y = data->rays.v_wall_y;
		data->rays.distance = data->rays.v_distance
			* cos(data->player.rot_angle - data->rays.ray_angle);
		data->text.of_x = (int)data->rays.wall_y % 64;
		if (data->rays.is_right)
			projection(data, i, data->text.we_addr);
		else
			projection(data, i, data->text.ea_addr);
	}
}

void	wall_project(t_data *data)
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
		get_distance(data, i);
		data->rays.ray_angle += data->rays.view_angle / data->rays.num_rays;
		i++;
	}
}
