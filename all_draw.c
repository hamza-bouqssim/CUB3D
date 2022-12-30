#include "cub3d.h"

void	init_rays(t_data *data)
{
	data->rays.view_angle = 60 * (M_PI / 180);
	data->rays.num_rays = WIDTH;
	data->rays.ray_angle = data->player.rot_angle - (data->rays.view_angle / 2);
	data->rays.ray_angle = fmod(data->rays.ray_angle, 2 * M_PI);
	if (data->rays.ray_angle < 0)
		data->rays.ray_angle = (2 * M_PI) + data->rays.ray_angle;
	data->rays.wall_x = 0;
	data->rays.wall_y = 0;
	data->rays.distance = 0;
}

void	all_draw(t_data *data)
{
	image(data);
	wall_project(data);
	minimap_draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
