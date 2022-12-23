#include "cub3d.h"

void draw(t_data *data, int color, int scale, double x, double y)
{
	int holdx = x * scale,holdy;
	while(holdx < (x + 1) * scale)
	{
		holdy = y * scale;
		while(holdy < (y + 1) * scale)
		{
			my_mlx_pixel_put(data, holdx, holdy, color);
			holdy++;
		}
		holdx++;
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
				data->player_x = x;
				data->player_y = y;
				data->map[i][j] = '0';
				draw(data, 0xfffffff, 30, x, y);
			}
			j++;
			x++;
		}
		i++;
		y++;
	}
	circle(data, data->player_x, data->player_y, 4, 0xff0000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}