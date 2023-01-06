/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:22 by hbouqssi          #+#    #+#             */
/*   Updated: 2023/01/06 01:07:33 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			{
				init_player_data(data, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = param;
	(void)y;
	if (x < WIDTH / 2)
		data->player.rot_angle = fmod(data->player.rot_angle - 0.05 + 2 * M_PI,
				2 * M_PI);
	else if (x >= WIDTH / 2)
		data->player.rot_angle = fmod(data->player.rot_angle + 0.05, 2 * M_PI);
	all_draw(data);
	mlx_mouse_move(data->win, WIDTH / 2, HEIGHT);
	mlx_mouse_hide();
	return (0);
}

int	ft_parsing(t_data *data, char *av)
{
	int	fd;

	ft_init(data);
	fd = open(av, O_RDONLY);
	if (fd < 0 || valide_path(av, ".cub") == 0)
	{
		write(2, "Wrong path\n", 11);
		return (0);
	}
	if (!fill_spl(data, fd) || !check_elements(data) || !map_check(data))
	{
		free_all(data);
		write(2, "Error\nNot valid", 15);
		return (0);
	}
	return (1);
}

void	mlx_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_hook(data->win, 2, 0, ft_pressed, data);
	mlx_hook(data->win, 3, 0, ft_released, data);
	mlx_hook(data->win, 6, 0, mouse_move, data);
	mlx_loop_hook(data->mlx, ft_keys, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (!ft_parsing(&data, av[1]))
			return (0);
		init_data(&data);
		if (!get_add_image(&data))
			return (0);
		search_player(&data);
		all_draw(&data);
		mlx_hooks(&data);
	}
	else
	{
		write(2, "Check your arguments !\n", 23);
		return (0);
	}
	free_all(&data);
	return (1);
}
