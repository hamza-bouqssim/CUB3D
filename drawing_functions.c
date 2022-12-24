#include "cub3d.h"

void draw(t_data *data, int color, int scale, double x, double y)
{
	int holdx = x * scale,holdy;
	int	color2 = 0x000000;
	int	first = holdx;
	int last = (x + 1) * scale;
	while(holdx < (x + 1) * scale)
	{
		holdy = y * scale;
		while(holdy < (y + 1) * scale)
		{
			if (holdx == first || holdx == last - 1 || holdy == y * scale
				|| holdy == (y + 1) * last - 1)
				my_mlx_pixel_put(data, holdx, holdy, color2);
			else
				my_mlx_pixel_put(data, holdx, holdy, color);
			holdy++;
		}
		holdx++;
	}
}

void	line(t_data *data, double x1, double y1)
{
	double	x;
	double	y;
	double	x_distance;
	double	y_distance;
	double	x_inc;
	double	y_inc;
	int		steps;
	int		i;

	x = data->player.x * 30 + 15;
	y = data->player.y * 30 + 15;
	x1 = x1 * 30 + 15 + cos(data->player.rot_angle) * 20;
	y1 = y1 * 30 + 15 + sin(data->player.rot_angle) * 20;
	x_distance = x1 - x;
	y_distance = y1 - y;
	steps = fmax(fabs(x_distance), fabs(y_distance));
	x_inc = x_distance / (double)steps;
	y_inc = y_distance / (double)steps;
	i = 0;
	while (i < steps)
	{
		my_mlx_pixel_put(data, x, y, 0xff0000);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

void    circle(t_data *data, double x, double y, int r, int color)
{
    double    angle;
    double    x1;
    double    y1;

	x = x * 30 + 15;
	y = y * 30 + 15;
    while (r)
    {
        angle = 0;
        while (angle < 360)
        {
            x1 = r * cos(angle * M_PI / 180);
            y1 = r * sin(angle * M_PI / 180);
            my_mlx_pixel_put(data, x + x1, y + y1, color);
            angle += 0.1;
        }
        r--;
    }
}

void draw_player(t_data *data, int color, int scale, double x, double y)
{
	int holdx = (x * scale) + 10,holdy;
	while(holdx < (x + 1) * scale - 10)
	{
		holdy = (y * scale) + 10;
		while(holdy < (y + 1) * scale - 10)
		{
			my_mlx_pixel_put(data, holdx, holdy, color);
			holdy++;
		}
		holdx++;
	}
}

void draw_map(t_data *data)
{
	int i;
	int j;
	int y = 0;
	int x;
	
	i = 0;
	image(data);
	while (data->map[i])
	{
		x = 0;
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				draw(data, 0x0000fff, 30, x, y);
			else if (data->map[i][j] == '0')
			{
				draw(data, 0xfffffff, 30, x, y);
			}
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->player.x = x;
				data->player.y = y;
				data->player.rot_speed = 8 * (M_PI / 180);
				data->player.move_speed = 1;
				if (data->map[i][j] == 'N')
					data->player.rot_angle = 3 * M_PI / 2;
				else if (data->map[i][j] == 'S')
					data->player.rot_angle = M_PI / 2;
				else if (data->map[i][j] == 'E')
					data->player.rot_angle = 0;
				else if (data->map[i][j] == 'W')
					data->player.rot_angle = M_PI;
				data->map[i][j] = '0';
				draw(data, 0xfffffff, 30, x, y);
			}
			j++;
			x++;
		}
		i++;
		y++;
	}
	circle(data, data->player.x, data->player.y, 4, 0xff0000);
	line(data, data->player.x, data->player.y);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}