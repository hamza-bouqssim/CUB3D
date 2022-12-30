/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:22 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/12/30 19:15:33 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->Columns = ft_strlen(data->map[0]);
	data->Rows = ft_count_rows(data->map);
	data->scale = 12;
	data->width = data->Columns * data->scale;
	data->height = data->Rows * data->scale;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	data->w_pressed = 0;
	data->a_pressed = 0;
	data->s_pressed = 0;
	data->d_pressed = 0;
	data->ri_pressed = 0;
	data->le_pressed = 0;
}

void	init_player_data(t_data *data, int x, int y)
{
	data->player.x = x * data->scale + (data->scale / 2);
	data->player.y = y * data->scale + (data->scale / 2);
	data->player.rot_speed = 0.8 * (M_PI / 180);
	data->player.move_speed = 0.4;
	if (data->map[y][x] == 'N')
		data->player.rot_angle = 3 * M_PI / 2;
	else if (data->map[y][x] == 'S')
		data->player.rot_angle = M_PI / 2;
	else if (data->map[y][x] == 'E')
		data->player.rot_angle = 0;
	else if (data->map[y][x] == 'W')
		data->player.rot_angle = M_PI;
}

void	search_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
					|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
				init_player_data(data, x, y);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

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
		init_data(&data);
		search_player(&data);
		all_draw(&data);
		mlx_hook(data.win, 17, 0, close_win, &data);
		mlx_hook(data.win, 2, 0, ft_pressed, &data);
		mlx_hook(data.win, 3, 0, ft_released, &data);
		mlx_loop_hook(data.mlx, ft_keys, &data);
		mlx_loop(data.mlx);
	}
	else
		write(2, "Check your arguments !\n", 23);
	return (0);
}
