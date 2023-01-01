#include "cub3d.h"

void	texture_init(t_data *data)
{
	data->texture.no_img = mlx_xpm_file_to_image(data->mlx, data->path[0], &data->texture.no_width, &data->texture.no_height);
	data->texture.no_addr = (unsigned int *)mlx_get_data_addr(data->texture.no_img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	data->texture.so_img = mlx_xpm_file_to_image(data->mlx, data->path[1], &data->texture.so_width, &data->texture.so_height);
	data->texture.so_addr = (unsigned int *)mlx_get_data_addr(data->texture.so_img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	data->texture.we_img = mlx_xpm_file_to_image(data->mlx, data->path[2], &data->texture.we_width, &data->texture.we_height);
	data->texture.we_addr = (unsigned int *)mlx_get_data_addr(data->texture.we_img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	data->texture.ea_img = mlx_xpm_file_to_image(data->mlx, data->path[3], &data->texture.ea_width, &data->texture.ea_height);
	data->texture.ea_addr = (unsigned int *)mlx_get_data_addr(data->texture.ea_img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);

}

void	get_add_image(t_data *data)
{
	texture_init(data);
}
