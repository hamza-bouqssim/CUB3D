/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:22 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/12/18 21:01:02 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	int	fd;
	char *ret;
	char **splitted_array;
	int i, j, Rows, Columns;
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
		i = 0;
		while(i < Rows)
		{
			j = 0;
			while(j < Columns)
			{
				if (splitted_array[i][j] == '1')
					printf("1: Finded\n");
				else if (splitted_array[i][j])
					printf("0: finded\n");
				j++;
			}
			i++;
		}
		// t_data data;
		// data.mlx = mlx_init();
		// data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "CUB3D")
		// mlx_loop(data.mlx);
	}
	else
		printf("Check your arguments !\n");
	return 0;
}