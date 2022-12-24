#include "cub3d.h"

int	ft_pressed(int key, t_data *data)
{
	if (key == W)
		data->w_pressed = 1;
	if (key == A)
		data->a_pressed = 1;
	if (key == S)
		data->s_pressed = 1;
	if (key == D)
		data->d_pressed = 1;
	if (key == RIGHT)
		data->ri_pressed = 1;
	if (key == LEFT)
		data->le_pressed = 1;
	if (key == ESC || key == Q)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (1);
	}
	return (0);
}

int	ft_released(int key, t_data *data)
{
	if (key == W)
		data->w_pressed = 0;
	if (key == A)
		data->a_pressed = 0;
	if (key == S)
		data->s_pressed = 0;
	if (key == D)
		data->d_pressed = 0;
	if (key == RIGHT)
		data->ri_pressed = 0;
	if (key == LEFT)
		data->le_pressed = 0;
	return (0);
}

int ft_moves(t_data *data)
{
	double	move;
	if (data->w_pressed)
	{
		data->player.direction = 0.1;
		move = data->player.direction * data->player.move_speed;
		// if (data->map[(int)round(data->player.y + 0.2)][(int)round(data->player.x)] == '1')
		// 	return (0);
		data->player.x += cos(data->player.rot_angle) * move;
		data->player.y += sin(data->player.rot_angle) * move;
	}
	if(data->s_pressed)
	{
		data->player.direction = -0.1;
		move = data->player.direction * data->player.move_speed;
		// if (data->map[(int)round(data->player.y - 0.2)][(int)round(data->player.x)] == '1')
		// 	return (0);
		data->player.x += cos(data->player.rot_angle) * move;
		data->player.y += sin(data->player.rot_angle) * move;
	}
	if(data->d_pressed)
	{
		data->player.direction = 0.1;
		move = data->player.direction * data->player.move_speed;
		// if (data->map[(int)round(data->player.y)][(int)round(data->player.x - 0.2)] == '1')
		// 	return (0);
		data->player.x += cos(data->player.rot_angle + (M_PI / 2)) * move;
		data->player.y += sin(data->player.rot_angle + (M_PI / 2)) * move;
	}
	if(data->a_pressed)
	{
		data->player.direction = -0.1;
		move = data->player.direction * data->player.move_speed;
		// if (data->map[(int)round(data->player.y)][(int)round(data->player.x + 0.2)] == '1')
		// 	return (0);
		data->player.x += cos(data->player.rot_angle + (M_PI / 2)) * move;
		data->player.y += sin(data->player.rot_angle + (M_PI / 2)) * move;
	}
	if (data->ri_pressed)
	{
		data->player.turn = 0.5;
		data->player.rot_angle += data->player.turn * data->player.rot_speed;
	}
	if (data->le_pressed)
	{
		data->player.turn = -0.5;
		data->player.rot_angle += data->player.turn * data->player.rot_speed;
	}
	mlx_destroy_image(data->mlx, data->img.img);
	draw_map(data);
	return (0);
}

int ft_keys(t_data *data)
{
	if(data->w_pressed || data->s_pressed || data->d_pressed || data->a_pressed
		|| data->ri_pressed || data->le_pressed)
		ft_moves(data);
	return (0);
}