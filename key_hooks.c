#include "cub3d.h"

int ft_moves(int key, t_data *data)
{
	if (key == W)
	{
		if (data->map[(int)round(data->player_y - 0.2)][(int)round(data->player_x)] == '1')
			return (0);
			data->player_y -= 0.2;
	}
	if(key == S)
	{
		if (data->map[(int)round(data->player_y + 0.2)][(int)round(data->player_x)] == '1')
			return (0);
		data->player_y += 0.2;
	}
	if(key == D)
	{
		if (data->map[(int)round(data->player_y)][(int)round(data->player_x + 0.2)] == '1')
			return (0);
		data->player_x += 0.2;
	}
	if(key == A)
	{
		if (data->map[(int)round(data->player_y)][(int)round(data->player_x - 0.2)] == '1')
			return (0);
		data->player_x -= 0.2;
	}
	mlx_destroy_image(data->mlx, data->img.img);
	draw_map(data);
	return (0);
}

int ft_keys(int keycode, t_data *data)
{
	if(keycode == W || keycode == S || keycode == D || keycode == A)
		ft_moves(keycode, data);
	if (keycode == ESC || keycode == Q)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (1);
	}
	return (0);
}