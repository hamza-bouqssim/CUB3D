/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:47:54 by sismaili          #+#    #+#             */
/*   Updated: 2023/01/05 00:50:31 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	w_move(t_data *data)
{
	double	move;
	double	x_wall;
	double	y_wall;
	double	x1_wall;
	double	y1_wall;

	data->player.direction = 1;
	move = data->player.direction * data->player.move_speed;
	x_wall = data->player.x + cos(data->player.rot_angle) * move;
	y_wall = data->player.y + sin(data->player.rot_angle) * move;
	x1_wall = ((data->columns * data->scale) * x_wall) / data->width;
	y1_wall = ((data->rows * data->scale) * y_wall) / data->height;
	if (wall_check(data, y_wall, x_wall) || collision_check(data, move))
		return ;
	data->player.x = x_wall;
	data->player.y = y_wall;
	data->player.x1 = x1_wall;
	data->player.y1 = y1_wall;
}

void	s_move(t_data *data)
{
	double	move;
	double	x_wall;
	double	y_wall;
	double	x1_wall;
	double	y1_wall;

	data->player.direction = -1;
	move = data->player.direction * data->player.move_speed;
	x_wall = data->player.x + cos(data->player.rot_angle) * move;
	y_wall = data->player.y + sin(data->player.rot_angle) * move;
	x1_wall = ((data->columns * data->scale) * x_wall) / data->width;
	y1_wall = ((data->rows * data->scale) * y_wall) / data->height;
	if (wall_check(data, y_wall, x_wall))
		return ;
	data->player.x = x_wall;
	data->player.y = y_wall;
	data->player.x1 = x1_wall;
	data->player.y1 = y1_wall;
}

void	d_move(t_data *data)
{
	double	move;
	double	x_wall;
	double	y_wall;
	double	x1_wall;
	double	y1_wall;

	data->player.direction = 1;
	move = data->player.direction * data->player.move_speed;
	x_wall = data->player.x + cos(data->player.rot_angle + (M_PI / 2)) * move;
	y_wall = data->player.y + sin(data->player.rot_angle + (M_PI / 2)) * move;
	x1_wall = ((data->columns * data->scale) * x_wall) / data->width;
	y1_wall = ((data->rows * data->scale) * y_wall) / data->height;
	if (wall_check(data, y_wall, x_wall))
		return ;
	data->player.x = x_wall;
	data->player.y = y_wall;
	data->player.x1 = x1_wall;
	data->player.y1 = y1_wall;
}

void	a_move(t_data *data)
{
	double	move;
	double	x_wall;
	double	y_wall;
	double	x1_wall;
	double	y1_wall;

	data->player.direction = -1;
	move = data->player.direction * data->player.move_speed;
	x_wall = data->player.x + cos(data->player.rot_angle + (M_PI / 2)) * move;
	y_wall = data->player.y + sin(data->player.rot_angle + (M_PI / 2)) * move;
	x1_wall = ((data->columns * data->scale) * x_wall) / data->width;
	y1_wall = ((data->rows * data->scale) * y_wall) / data->height;
	if (wall_check(data, y_wall, x_wall))
		return ;
	data->player.x = x_wall;
	data->player.y = y_wall;
	data->player.x1 = x1_wall;
	data->player.y1 = y1_wall;
}
