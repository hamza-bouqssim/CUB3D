/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:22 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/12/20 17:31:09 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int close_win(void *param)
{
	t_data *data;
	data = param;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void draw_player(t_data *data, t_player *player, int h, int w)
{
	player->a = h / 2;
	player->b = w / 2;
	int v1 = player->a / 18;
	int v2 = player->b / 18;
	int radius = v1 * v2;
	player->x = 0;
	while(player->x < h * 30)
	{
		player->y = 0;
		while(player->y < w * 30)
		{
			if (((player->x - player->a) * (player->x - player->a)) + ((player->y - player->b) * (player->y - player->b)) <=  radius)
				mlx_pixel_put(data->mlx, data->win, player->x, player->y, 0xff0000);
			player->y++;
		}
		player->x++;
	}
}

void draw(t_data *data, int color, int scale, int x, int y)
{
	int holdx = x;
	int holdy = y;
	while(x < holdx + scale)
	{
		y = holdy;	
		while(y < holdy + scale)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, color);
			y++;
		}
		x++;
	}
}

void draw_map(t_data *data, char **arr)
{
	int i;
	int j;
	int y;
	int x = 0;
	
	i = 0;
	while (arr[i])
	{
		y = 0;
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '1')
				draw(data, 0x0000fff, 30, y, x);
			else if (arr[i][j] == '0')
				draw(data, 0xfffffff, 30, y, x);
			j++;
			y += 30;
		}
		i++;
		x += 30;
	}
}

int main(int ac, char **av)
{
	t_data data;
	t_player player;
	int	fd;
	char *ret;
	char **splitted_array;
	int Columns;
	int Rows;
	
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0 || valide_path(av[1]) == 0)
		{
			printf("Wrong path\n");
			return (1);
		}
		ret = get_next_line(fd);
		splitted_array = ft_split(ret, '\n');
		Columns = ft_strlen(splitted_array[0]);
		Rows = ft_countRows(splitted_array);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, Columns * 30, Rows * 30, "CUB3D");
		draw_map(&data, splitted_array);
		draw_player(&data, &player, Columns * 30, Rows * 30);
		mlx_hook(data.win, 17, 0, close_win, &data);
		mlx_loop(data.mlx);
	}
	else
		printf("Check your arguments !\n");
	return 0;
}