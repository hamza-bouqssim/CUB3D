/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:34:33 by sismaili          #+#    #+#             */
/*   Updated: 2023/01/05 01:21:36 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->columns = ft_count_columns(data->map);
	data->rows = ft_count_rows(data->map);
	data->scale = 12;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	data->w_pressed = 0;
	data->a_pressed = 0;
	data->s_pressed = 0;
	data->d_pressed = 0;
	data->ri_pressed = 0;
	data->le_pressed = 0;
}

void	init_player_data(t_data *data, int x, int y)
{
	data->scale_3d = data->text.no_hei;
	data->width = data->columns * data->scale_3d;
	data->height = data->rows * data->scale_3d;
	data->player.x = x * data->scale_3d + (data->scale_3d / 2);
	data->player.y = y * data->scale_3d + (data->scale_3d / 2);
	data->player.x1 = x * data->scale + (data->scale / 2);
	data->player.y1 = y * data->scale + (data->scale / 2);
	data->player.rot_speed = 1.5 * (M_PI / 180);
	data->player.move_speed = 50;
	if (data->map[y][x] == 'N')
		data->player.rot_angle = 3 * M_PI / 2;
	else if (data->map[y][x] == 'S')
		data->player.rot_angle = M_PI / 2;
	else if (data->map[y][x] == 'E')
		data->player.rot_angle = 0;
	else if (data->map[y][x] == 'W')
		data->player.rot_angle = M_PI;
}

void	ft_init(t_data *data)
{
	data->f_rgb = NULL;
	data->c_rgb = NULL;
	data->path = NULL;
	data->elements = NULL;
	data->map = NULL;
}
