/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 01:10:58 by sismaili          #+#    #+#             */
/*   Updated: 2023/01/05 01:10:59 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw(t_data *data, int color, double x, double y)
{
	double	holdx;
	double	holdy;
	double	first;
	double	last;

	holdx = x * data->scale;
	first = holdx;
	last = (x + 1) * data->scale;
	while (holdx < (x + 1) * data->scale)
	{
		holdy = y * data->scale;
		while (holdy < (y + 1) * data->scale)
		{
			if (holdx == first || holdx == last - 1 || holdy == y * data->scale
				|| holdy == (y + 1) * last - 1)
				my_mlx_pixel_put(data, holdx, holdy, 0x000000);
			else
				my_mlx_pixel_put(data, holdx, holdy, color);
			holdy++;
		}
		holdx++;
	}
}

void	line(t_data *data, double x1, double y1, double angle)
{
	double	x;
	double	y;
	double	x_inc;
	double	y_inc;
	int		steps;

	x = x1;
	y = y1;
	x1 = x1 + cos(angle) * data->scale;
	y1 = y1 + sin(angle) * data->scale;
	steps = fmax(fabs(x1 - x), fabs(y1 - y));
	x_inc = (x1 - x) / (double)steps;
	y_inc = (y1 - y) / (double)steps;
	while (steps > 0)
	{
		my_mlx_pixel_put(data, x, y, 0xff0000);
		x += x_inc;
		y += y_inc;
		steps--;
	}
}

void	circle(t_data *data, double x, double y, int r)
{
	double	angle;
	double	x1;
	double	y1;

	while (r)
	{
		angle = 0;
		while (angle < 360)
		{
			x1 = r * cos(angle * M_PI / 180);
			y1 = r * sin(angle * M_PI / 180);
			my_mlx_pixel_put(data, x + x1, y + y1, 0xff0000);
			angle += 0.1;
		}
		r--;
	}
}

void	m_draw(t_data *data)
{
	while (data->map[data->mm.y] && data->mm.y < data->mm.start_y + 20)
	{
		data->mm.x = data->mm.start_x;
		while (data->map[data->mm.y][data->mm.x]
			&& data->mm.x < data->mm.start_x + 20
			&& data->mm.x < ft_strlen(data->map[data->mm.y]))
		{
			data->mm.draw_x = (data->mm.x - data->mm.start_x);
			data->mm.draw_y = (data->mm.y - data->mm.start_y);
			if (data->map[data->mm.y][data->mm.x] == '1')
				draw(data, 0x0000ff, data->mm.draw_x, data->mm.draw_y);
			else if (data->map[data->mm.y][data->mm.x] == 'N'
				|| data->map[data->mm.y][data->mm.x] == 'S'
					|| data->map[data->mm.y][data->mm.x] == 'E'
					|| data->map[data->mm.y][data->mm.x] == 'W')
				data->map[data->mm.y][data->mm.x] = '0';
			data->mm.x++;
		}
		data->mm.y++;
	}
}

void	minimap_draw(t_data *data)
{
	data->mm.start_x = data->player.x1 / data->scale;
	data->mm.start_y = data->player.y1 / data->scale;
	data->mm.start_x -= 10;
	data->mm.start_y -= 10;
	if (data->mm.start_x < 0)
		data->mm.start_x = 0;
	if (data->mm.start_y < 0)
		data->mm.start_y = 0;
	data->mm.y = data->mm.start_y;
	m_draw(data);
	data->mm.start_x = (data->player.x1 / data->scale - data->mm.start_x)
		* data->scale;
	data->mm.start_y = (data->player.y1 / data->scale - data->mm.start_y)
		* data->scale;
	circle(data, data->mm.start_x, data->mm.start_y, data->scale / 5);
	line(data, data->mm.start_x, data->mm.start_y, data->player.rot_angle);
}
