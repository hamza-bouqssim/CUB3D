/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:22 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/12/20 16:31:37 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;
	int		i;

	i = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0 || valide_path(av[1], ".cub") == 0)
		{
			printf("Wrong path\n");
			return (1);
		}
		fill_spl(&data, fd);
		// printf("%s", data.elements[0]);
		if (!check_elements(&data))
			return (0);
		// while (data.spl[i])
		// 	printf("%s\n", data.spl[i++]);
		// data.mlx = mlx_init();
		// data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "CUB3D");
		// mlx_loop(data.mlx);
	}
	else
		printf("Check your arguments !\n");
	return (0);
}
