#include "../cub3d.h"

int	wall_check(t_data *data, double y, double x)
{
	if (x < 0 || x > data->width || y < 0 || y > data->height)
		return (1);
	x = floor(x / data->scale_3d);
	y = floor(y / data->scale_3d);
	if (((int)x < data->Columns && (int)y < data->Rows)
		&& data->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

void	w_move(t_data *data)
{
	double	move;
	double	x_wall;
	double	y_wall;
	double	x1_wall;
	double	y1_wall;

	data->player.direction = 1;	
	move = data->player.direction * data->player.move_speed;
	x_wall = data->player.x + cos(data->player.rot_angle) * move;
	y_wall = data->player.y + sin(data->player.rot_angle) * move;
	x1_wall = ((data->Columns * data->scale) * x_wall) / data->width;
	y1_wall = ((data->Rows * data->scale) * y_wall) / data->height;
	if (wall_check(data, y_wall, x_wall))
		return ;
	data->player.x = x_wall;
	data->player.y = y_wall;
	data->player.x1 = x1_wall;
	data->player.y1 = y1_wall;
}

void	s_move(t_data *data)
{
	double	move;
	double	x_wall;
	double	y_wall;
	double	x1_wall;
	double	y1_wall;

	data->player.direction = -1;
	move = data->player.direction * data->player.move_speed;
	x_wall = data->player.x + cos(data->player.rot_angle) * move;
	y_wall = data->player.y + sin(data->player.rot_angle) * move;
	x1_wall = ((data->Columns * data->scale) * x_wall) / data->width;
	y1_wall = ((data->Rows * data->scale) * y_wall) / data->height;
	if (wall_check(data, y_wall, x_wall))
		return ;
	data->player.x = x_wall;
	data->player.y = y_wall;
	data->player.x1 = x1_wall;
	data->player.y1 = y1_wall;
}

void	d_move(t_data *data)
{
	double	move;
	double	x_wall;
	double	y_wall;
	double	x1_wall;
	double	y1_wall;

	data->player.direction = 1;
	move = data->player.direction * data->player.move_speed;
	x_wall = data->player.x + cos(data->player.rot_angle + (M_PI / 2)) * move;
	y_wall = data->player.y + sin(data->player.rot_angle + (M_PI / 2)) * move;
	x1_wall = ((data->Columns * data->scale) * x_wall) / data->width;
	y1_wall = ((data->Rows * data->scale) * y_wall) / data->height;
	if (wall_check(data, y_wall, x_wall))
		return ;
	data->player.x = x_wall;
	data->player.y = y_wall;
	data->player.x1 = x1_wall;
	data->player.y1 = y1_wall;
}

void	a_move(t_data *data)
{
	double	move;
	double	x_wall;
	double	y_wall;
	double	x1_wall;
	double	y1_wall;

	data->player.direction = -1;
	move = data->player.direction * data->player.move_speed;
	x_wall = data->player.x + cos(data->player.rot_angle + (M_PI / 2)) * move;
	y_wall = data->player.y + sin(data->player.rot_angle + (M_PI / 2)) * move;
	x1_wall = ((data->Columns * data->scale) * x_wall) / data->width;
	y1_wall = ((data->Rows * data->scale) * y_wall) / data->height;
	if (wall_check(data, y_wall, x_wall))
		return ;
	data->player.x = x_wall;
	data->player.y = y_wall;
	data->player.x1 = x1_wall;
	data->player.y1 = y1_wall;
}
