#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x \
			* (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	image(t_data *data)
{
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
}

int close_win(void *param)
{
	t_data *data;
	data = param;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}