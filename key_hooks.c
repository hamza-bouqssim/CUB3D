#include "cub3d.h"

int ft_moves(int key, t_data *data)
{
	double	move;
	if (key == W)
	{
		data->player.direction = 0.1;
		move = data->player.direction * data->player.move_speed;
		if (data->map[(int)round(data->player.y - 0.2)][(int)round(data->player.x)] == '1')
			return (0);
		data->player.x += cos(data->player.rot_angle) * move;
		data->player.y += sin(data->player.rot_angle) * move;
	}
	if(key == S)
	{
		data->player.direction = -0.1;
		move = data->player.direction * data->player.move_speed;
		if (data->map[(int)round(data->player.y + 0.2)][(int)round(data->player.x)] == '1')
			return (0);
		// data->player.y += 0.2;
		data->player.x += cos(data->player.rot_angle) * move;
		data->player.y += sin(data->player.rot_angle) * move;
	}
	if(key == D)
	{
		if (data->map[(int)round(data->player.y)][(int)round(data->player.x + 0.2)] == '1')
			return (0);
		data->player.x += 0.2;
	}
	if(key == A)
	{
		if (data->map[(int)round(data->player.y)][(int)round(data->player.x - 0.2)] == '1')
			return (0);
		data->player.x -= 0.2;
	}
	if (key == RIGHT)
	{
		data->player.turn = 1;
		data->player.rot_angle += data->player.turn * data->player.rot_speed;
	}
	if (key == LEFT)
	{
		data->player.turn = -1;
		data->player.rot_angle += data->player.turn * data->player.rot_speed;
	}
	mlx_destroy_image(data->mlx, data->img.img);
	draw_map(data);
	return (0);
}

int ft_keys(int keycode, t_data *data)
{
	if(keycode == W || keycode == S || keycode == D || keycode == A
		|| keycode == RIGHT || keycode == LEFT)
		ft_moves(keycode, data);
	if (keycode == ESC || keycode == Q)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (1);
	}
	return (0);
}