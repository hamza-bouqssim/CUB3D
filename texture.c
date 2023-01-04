#include "cub3d.h"

int	image_error(t_data *data)
{
	if (!data->text.no.img || !data->text.so.img || !data->text.we.img
		|| !data->text.ea.img)
		return (0);
	return (1);
}

void	addr_init(t_data *data)
{
	data->text.no_addr = (unsigned int *)mlx_get_data_addr(data->text.no.img,
			&data->text.no.bpp, &data->text.no.line_len, &data->text.no.end);
	data->text.so_addr = (unsigned int *)mlx_get_data_addr(data->text.so.img,
			&data->text.so.bpp, &data->text.so.line_len, &data->text.so.end);
	data->text.we_addr = (unsigned int *)mlx_get_data_addr(data->text.we.img,
			&data->text.we.bpp, &data->text.we.line_len, &data->text.we.end);
	data->text.ea_addr = (unsigned int *)mlx_get_data_addr(data->text.ea.img,
			&data->text.ea.bpp, &data->text.ea.line_len, &data->text.ea.end);
}

void	texture_init(t_data *data)
{
	data->text.no.img = mlx_xpm_file_to_image(data->mlx, data->path[0],
			&data->text.no_wid, &data->text.no_hei);
	data->text.so.img = mlx_xpm_file_to_image(data->mlx, data->path[1],
			&data->text.so_wid, &data->text.so_hei);
	data->text.we.img = mlx_xpm_file_to_image(data->mlx, data->path[2],
			&data->text.we_wid, &data->text.we_hei);
	data->text.ea.img = mlx_xpm_file_to_image(data->mlx, data->path[3],
			&data->text.ea_wid, &data->text.ea_hei);
}

int	get_add_image(t_data *data)
{
	texture_init(data);
	if (!image_error(data))
		return (0);
	addr_init(data);
	return (1);
}
