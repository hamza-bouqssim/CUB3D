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

void draw_player(t_data *data, int color, double x, double y)
{
	int holdx = x * 30,holdy;
	while(holdx < (x + 1) * 28)
	{
		holdy = y * 30;
		while(holdy < (y + 1) * 22)
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
				printf("x = %d, y = %d\n", x, y);
				draw(data, 0xfffffff, 30, x, y);
				draw(data, 0xff0000, 30, data->player_x, data->player_y);
				// data->player_x = x;
				// data->player_y = y;
			}
			j++;
			x++;
		}
		i++;
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}