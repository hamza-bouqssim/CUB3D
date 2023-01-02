#include "../cub3d.h"

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
	if( key == MINES)
		mlx_mouse_hide();
	if(key == PLUS)
		mlx_mouse_show();
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

int	ft_moves(t_data *data)
{
	if (data->w_pressed)
		w_move(data);
	if (data->s_pressed)
		s_move(data);
	if (data->d_pressed)
		d_move(data);
	if (data->a_pressed)
		a_move(data);
	if (data->ri_pressed)
	{
		data->player.turn = 1;
		data->player.rot_angle += data->player.turn * data->player.rot_speed;
	}
	if (data->le_pressed)
	{
		data->player.turn = -1;
		data->player.rot_angle += data->player.turn * data->player.rot_speed;
	}
	mlx_destroy_image(data->mlx, data->img.img);
	all_draw(data);
	return (0);
}

int	ft_keys(t_data *data)
{
	if (data->w_pressed || data->s_pressed || data->d_pressed || data->a_pressed
		|| data->ri_pressed || data->le_pressed)
		ft_moves(data);
	return (0);
}
