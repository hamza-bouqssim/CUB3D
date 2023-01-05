/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:49:03 by sismaili          #+#    #+#             */
/*   Updated: 2023/01/05 01:28:05 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_check(t_data *data, double y, double x)
{
	if (x < 0 || x > data->width || y < 0 || y > data->height)
		return (1);
	x = floor(x / data->scale_3d);
	y = floor(y / data->scale_3d);
	if (((int)x < data->columns && (int)y < data->rows)
		&& data->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

int	collision_check(t_data *data, double move)
{
	double	col_x;
	double	col_y;
	double	col_x1;
	double	col_y1;

	col_x = data->player.x + cos(data->player.rot_angle - (data->rays.view_angle
				/ 2)) * move;
	col_y = data->player.y + sin(data->player.rot_angle - (data->rays.view_angle
				/ 2)) * move;
	col_x1 = data->player.x + cos(data->player.rot_angle
			+ (data->rays.view_angle / 2)) * move;
	col_y1 = data->player.y + sin(data->player.rot_angle
			+ (data->rays.view_angle / 2)) * move;
	if (wall_check(data, col_y, col_x) || wall_check(data, col_y1, col_x1))
		return (1);
	return (0);
}
