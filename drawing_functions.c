#include "cub3d.h"

void	draw(t_data *data, int color, int scale, double x, double y)
{
	int holdx;
	int	holdy;
	int	first;
	int last;

	holdx = x * scale;
	first = holdx;
	last = (x + 1) * scale;
	while (holdx < (x + 1) * scale)
	{
		holdy = y * scale;
		while(holdy < (y + 1) * scale)
		{
			if (holdx == first || holdx == last - 1 || holdy == y * scale
					|| holdy == (y + 1) * last - 1)
				my_mlx_pixel_put(data, holdx, holdy, 0x000000);
			else
				my_mlx_pixel_put(data, holdx, holdy, color);
			holdy++;
		}
		holdx++;
	}
}

void	ray_line(t_data *data, double x1, double y1, double angle)
{
	double	x;
	double	y;
	double	x_inc;
	double	y_inc;
	int		steps;
	int		i;

	x = data->player.x;
	y = data->player.y;
	// x1 = x1 * 30;
	// y1 = y1 * 30;
	// x1 = x1 + cos(angle);
	// y1 = y1 + sin(angle);
	steps = fmax(fabs(x1 - x), fabs(y1 - y));
	x_inc = (x1 - x) / (double)steps;
	y_inc = (y1 - y) / (double)steps;
	i = 0;
	while (i < steps)
	{
		my_mlx_pixel_put(data, x, y, 0xFFA500);
		x += x_inc;
		y += y_inc;
		i++;
	}
}
void	line(t_data *data, double x1, double y1, double angle)
{
	double	x;
	double	y;
	double	x_inc;
	double	y_inc;
	int		steps;
	int		i;

	x = data->player.x;
	y = data->player.y;
	// x1 = x1 * 30;
	// y1 = y1 * 30;
	x1 = x1 + cos(angle) * 30;
	y1 = y1 + sin(angle) * 30;
	steps = fmax(fabs(x1 - x), fabs(y1 - y));
	x_inc = (x1 - x) / (double)steps;
	y_inc = (y1 - y) / (double)steps;
	i = 0;
	while (i < steps)
	{
		my_mlx_pixel_put(data, roundf(x), roundf(y), 0xff0000);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

void	circle(t_data *data, double x, double y, int r, int color)
{
	double    angle;
	double    x1;
	double    y1;

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

void	player_data(t_data *data, int x, int y)
{
	data->player.x = x * 30 + 15;
	data->player.y = y * 30 + 15;
	data->player.rot_speed = (M_PI / 180);
	data->player.move_speed = 2.0;
	if (data->map[y][x] == 'N')
		data->player.rot_angle = 3 * M_PI / 2;
	else if (data->map[y][x] == 'S')
		data->player.rot_angle = M_PI / 2;
	else if (data->map[y][x] == 'E')
		data->player.rot_angle = 0;
	else if (data->map[y][x] == 'W')
		data->player.rot_angle = M_PI;
	data->map[y][x] = '0';
	draw(data, 0xfffffff, 30, x, y);
}

void	init_rays(t_data *data)
{
	data->rays.view_angle = 60 * (M_PI / 180);
	data->rays.num_rays = data->Columns * 30;
	data->rays.ray_angle = data->player.rot_angle - (data->rays.view_angle / 2);
	data->rays.ray_angle = fmod(data->rays.ray_angle, 2 * M_PI);
	if (data->rays.ray_angle < 0)
		data->rays.ray_angle = (2 * M_PI) + data->rays.ray_angle;
	data->rays.wall_x = 0;
	data->rays.wall_y = 0;
	data->rays.distance = 0;
	data->rays.is_down = 0;
	data->rays.is_right = 0;
	if (data->rays.ray_angle > 0 && data->rays.ray_angle < M_PI)
		data->rays.is_down = 1;
	if (data->rays.ray_angle < M_PI / 2 || data->rays.ray_angle > 3 * M_PI / 2)
		data->rays.is_right = 1;
}

void	horizontal_check(t_data *data, int column)
{
	double	xstep;
	double	ystep;
	double	xintercept;
	double	yintercept;
	double	next_x;
	double	next_y;
	int		foundWall;

	foundWall = 0;
	yintercept = floor(data->player.y / 30) * 30;
	if (data->rays.is_down)
		yintercept += 30;
	xintercept = data->player.x + (yintercept - data->player.y / tan(data->rays.ray_angle));
	ystep = 30;
	if (!data->rays.is_down)
		ystep *= -1;
	xstep = 30 / tan(data->rays.ray_angle);
	if (!data->rays.is_right && xstep > 0)
		xstep *= -1;
	else if (data->rays.is_right && xstep < 0)
		xstep *= -1;
	next_x = xintercept;
	next_y = yintercept;
	if (!data->rays.is_down)
		next_y--;
	// printf("%d     %d\n", (int)next_y, (int)next_x);
	while (next_x >= 0 && next_x <= data->Columns * 30 && next_y >= 0 && next_y <= data->Rows * 30)
	{
		if (wall_check(data, next_y , next_x))
		{
			foundWall = 1;
			ray_line(data, next_x, next_y, data->rays.ray_angle);
			break ;
		}
		else
		{
			next_x += xstep;
			next_y += ystep;
		}
	}
}

void	draw_rays(t_data *data)
{
	int		i;
	int		column;

	i = 0;
	column = 0;
	init_rays(data);
	while (i < data->rays.num_rays)
	{
		data->rays.is_down = 0;
		data->rays.is_right = 0;
		if (data->rays.ray_angle > 0 && data->rays.ray_angle < M_PI)
			data->rays.is_down = 1;
		if (data->rays.ray_angle < M_PI / 2 || data->rays.ray_angle > 3 * M_PI / 2)
			data->rays.is_right = 1;
		data->rays.ray_angle = fmod(data->rays.ray_angle, 2 * M_PI);
		if (data->rays.ray_angle < 0)
			data->rays.ray_angle = (2 * M_PI) + data->rays.ray_angle;
		horizontal_check(data, column);
		// line(data, data->player.x, data->player.y, data->rays.ray_angle);
		data->rays.ray_angle += data->rays.view_angle / data->rays.num_rays;
		i++;
		column++;
	}
}

void	draw_map(t_data *data)
{
	int x;
	int y;

	y = 0;
	image(data);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw(data, 0x0000fff, 30, x, y);
			else if (data->map[y][x] == '0')
				draw(data, 0xfffffff, 30, x, y);
			else if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
					|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
				player_data(data, x, y);
			x++;
		}
		y++;
	}
	circle(data, data->player.x, data->player.y, 4, 0xff0000);
	line(data, data->player.x, data->player.y, data->player.rot_angle);
	draw_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
