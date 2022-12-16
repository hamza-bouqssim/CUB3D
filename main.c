/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:22 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/12/16 18:13:16 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	valide_path(char *path)
{
	int		len;
	int		index;
	int		i;
	char	*ext;

	i = 0;
	ext = ".cub";
	len = ft_strlen(path);
	index = len - 4;
	if (index <= 0)
		return (0);
	while (path[index + i])
	{
		if (path[index + i] != ext[i])
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	int	fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0 || valide_path(av[1]) == 0)
		{
			printf("Wrong path\n");
			return (1);
		}
		t_data data;
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "CUB3D");
		mlx_loop(data.mlx);
	}
	else
		printf("Check your arguments !\n");
	return 0;
}