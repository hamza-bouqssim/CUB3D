#include "cub3d.h"

void	draw3D(t_data *data, int color, double x, double y, double wallheight)
{
	double j = y;
	while (j < y + wallheight)
	{
		my_mlx_pixel_put(data, x, j, color);
		j++;
	}
}

void projection(t_data *data, int i , int color)
{
	double raydistance = data->rays.distance;
	double distanceProjectionPlane = (WIDTH / 2) / tan(data->rays.view_angle / 2);
	double wall_strip = (data->scale / raydistance) * distanceProjectionPlane;
	draw3D(data, color,i, (HEIGHT / 2) - (wall_strip / 2), wall_strip); 
}