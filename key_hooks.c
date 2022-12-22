#include "cub3d.h"

int ft_moves(int key, t_data *data)
{
	if (key == W)
	{
		if (data->map[(int)round(data->player_y - 1)][(int)round(data->player_x)] == '1')
			return (0);
		data->map[(int)data->player_y][(int)data->player_x] = '0';
			data->player_y -= 1;
		data->map[(int)data->player_y][(int)data->player_x] = 'N';
		printf("player_x -- %d,  player_y -- %d\n", (int)round(data->player_x), (int)round(data->player_y));
	}
	if(key == S)
	{
		if (data->map[(int)round(data->player_y + 1)][(int)round(data->player_x)] == '1')
			return (0);
		data->map[(int)data->player_y][(int)data->player_x] = '0';
		data->player_y += 1;
		data->map[(int)data->player_y][(int)data->player_x] = 'N';
			printf("player_x -- %f,  player_y -- %f\n", data->player_x, data->player_y);
	}
	if(key == D)
	{
		if (data->map[(int)round(data->player_y)][(int)round(data->player_x + 1)] == '1')
			return (0);
		data->map[(int)data->player_y][(int)data->player_x] = '0';
		data->player_x += 1;
		data->map[(int)data->player_y][(int)data->player_x] = 'N';
	}
	if(key == A)
	{
		if (data->map[(int)round(data->player_y)][(int)round(data->player_x - 1)] == '1')
			return (0);
		data->map[(int)data->player_y][(int)data->player_x] = '0';
		data->player_x -= 1;
		data->map[(int)data->player_y][(int)data->player_x] = 'N';
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