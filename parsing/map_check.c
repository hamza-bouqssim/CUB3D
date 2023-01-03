/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:32:22 by sismaili          #+#    #+#             */
/*   Updated: 2023/01/03 17:33:14 by sismaili         ###   ########.fr       */
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
	else if ((((i < last && (data->map[i + 1][j] == ' ' || !data->map[i + 1][j]))
		|| (i > 0 && (data->map[i - 1][j] == ' ' || !data->map[i - 1][j]))))
			&& data->map[i][j] != '1' && data->map[i][j] != ' ')
		return (0);
	return (1);
}

static int	check_wall(t_data *data)
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

int	map_char_check(char c)
{
	if (c != ' ' && c != '0'
		&& c != '1' && c != 'N'
		&& c != 'S' && c != 'E'
		&& c != 'W')
		return (0);
	return (1);
}

int	map_check(t_data *data)
{
	int	i;
	int	j;
	int	player_check;

	i = 0;
	player_check = 0;
	if (!data->map[0] || !check_wall(data))
		return (0);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!map_char_check(data->map[i][j]))
				return (0);
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
				player_check++;
			j++;
		}
		i++;
	}
	if (player_check != 1)
		return (0);
	return (1);
}
