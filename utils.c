#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		dst = data->img.addr + (y * data->img.line_len + x
				* (data->img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	image(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_len, &data->img.end);
}

int	close_win(void *param)
{
	t_data	*data;

	data = param;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
