/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:22 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/12/21 21:20:41 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void draw_player(t_data *data, int h, int w) // witdh = 180 : height = 510
{
	data->ap = h / 2; // data-> a = 90
	data->bp = w / 2; // data-> b = 255
	int v1 = data->ap / 18;
	int v2 = data->bp / 18;
	int radius = v1 * v2;
	printf("%d\n", radius);
	data->xp = 0;
	while(data->xp < h * 30)
	{
		data->yp = 0;
		while(data->yp < w * 30)
		{
			if (((data->xp - data->ap) * (data->xp - data->ap)) + ((data->yp - data->bp) * (data->yp - data->bp)) <=  radius)
				my_mlx_pixel_put(data, data->xp, data->yp, 0xff0000);
			data->yp++;
		}
		data->xp++;
	}
}

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

void draw_map(t_data *data)
{
	int i;
	int j;
	int y;
	int x = 0;
	
	i = 0;
	image(data);
	while (data->splitted_array[i])
	{
		y = 0;
		j = 0;
		while (data->splitted_array[i][j])
		{
			if (data->splitted_array[i][j] == '1')
				draw(data, 0x0000fff, 30, y, x);
			else if (data->splitted_array[i][j] == '0' || data->splitted_array[i][j] == 'E')
			{
				draw(data, 0xfffffff, 30, y, x);
				draw(data, 0xff0000, 1, data->player_x *30 + 15, data->player_y * 30 + 15);
			}
			j++;
			y++;
		}
		i++;
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
int ft_moves(int key, t_data *data)
{
	if (key == W)
	{
		if (data->splitted_array[(int)round(data->player_y - 0.1)][(int)round(data->player_x)] != '1')
			data->player_y -= 0.1;
		printf("player_x -- %d,  player_y -- %d\n", (int)round(data->player_x), (int)round(data->player_y));
	}
	if(key == S)
	{
		if (data->splitted_array[(int)round(data->player_y + 0.1)][(int)round(data->player_x)] != '1')
			data->player_y += 0.1;
			printf("player_x -- %f,  player_y -- %f\n", data->player_x, data->player_y);
	}
	if(key == D)
	{
		if (data->splitted_array[(int)round(data->player_y)][(int)round(data->player_x + 0.1)] != '1')
		data->player_x += 0.1;
	}
	if(key == A)
	{
		if (data->splitted_array[(int)round(data->player_y)][(int)round(data->player_x - 0.1)] != '1')
		data->player_x -= 0.1;
	}
	mlx_destroy_image(data->mlx, data->img.img);
	draw_map(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data data;
	int	fd;
	char *ret;
	char **splitted_array;
	
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0 || valide_path(av[1], ".cub") == 0)
		{
			write(2, "Wrong path\n", 11);
			return (1);
		}
		fill_spl(&data, fd);
		if (!check_elements(&data) || !map_check(&data))
		{
			write(2, "Error\nNot valid", 15);
			return (0);
		}
		ret = get_next_line(fd);
		data.splitted_array = ft_split(ret, '\n');
		data.Columns = ft_strlen(data.splitted_array[0]);
		data.Rows = ft_countRows(data.splitted_array);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "CUB3D");
		data.player_x = 1;
		data.player_y = 6;
		data.playerX = 1;
		data.playerY = 1;
		draw_map(&data);
		mlx_hook(data.win, 17, 0, close_win, &data);
		mlx_hook(data.win, 2, 0, ft_moves, &data);
		mlx_loop(data.mlx);
	}
	else
		write(2, "Check your arguments !\n", 23);
	return 0;
}
