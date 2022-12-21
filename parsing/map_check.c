/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:32:22 by sismaili          #+#    #+#             */
/*   Updated: 2022/12/21 18:36:33 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	checker(t_data *data, int i, int j, int last)
{
	if ((i == 0 || i == last)
		&& data->map[i][j] != '1' && data->map[i][j] != ' ')
		return (0);
	else if ((j == 0 || data->map[i][j - 1] == ' ')
		&& data->map[i][j] != '1' && data->map[i][j] != ' ')
		return (0);
	else if ((data->map[i][j + 1] == ' ' || !data->map[i][j + 1])
		&& data->map[i][j] != '1' && data->map[i][j] != ' ')
		return (0);
	else if (((i < last && data->map[i + 1][j] == ' ')
		|| (i > 0 && data->map[i - 1][j] == ' '))
			&& data->map[i][j] != '1' && data->map[i][j] != ' ')
		return (0);
	return (1);
}

static int	wall_check(t_data *data)
{
	int	i;
	int	j;
	int	last;

	i = 0;
	last = 0;
	while (data->map[i])
		i++;
	last = i - 1;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!checker(data, i, j, last))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!wall_check(data))
		return (0);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != ' ' && data->map[i][j] != '0'
				&& data->map[i][j] != '1' && data->map[i][j] != 'N'
				&& data->map[i][j] != 'S' && data->map[i][j] != 'E'
				&& data->map[i][j] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
