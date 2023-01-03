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

void	minimap_draw(t_data *data)
{
	int	x;
	int	y;
	double	start_x;
	double	start_y;
	double	draw_x;
	double	draw_y;

	start_x = data->player.x1 / data->scale;
	start_y = data->player.y1 / data->scale;
	start_x -= 10;
	start_y -= 10;
	if (start_x < 0)
		start_x = 0;
	if (start_y < 0)
		start_y = 0;
	y = start_y;
	while (data->map[y] && y < start_y + 20)
	{
		x = start_x;
		while (data->map[y][x] && x < start_x + 20 && x < ft_strlen(data->map[y]))
		{
			draw_x = (x - start_x);
			draw_y = (y - start_y);
			if (data->map[y][x] == '1')
				draw(data, 0x0000ff, draw_x, draw_y);
			else if (data->map[y][x] == '0')
				draw(data, 0xffffff, draw_x, draw_y);
			else if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
					|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				draw(data, 0xffffff, draw_x, draw_y);
				data->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	start_x = (data->player.x1 / data->scale - start_x) * data->scale;
	start_y = (data->player.y1 / data->scale - start_y) * data->scale;
	circle(data, start_x, start_y, data->scale / 5);
	line(data, start_x, start_y, data->player.rot_angle);
}
