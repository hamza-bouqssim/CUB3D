/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:12:39 by sismaili          #+#    #+#             */
/*   Updated: 2023/01/06 15:40:49 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	count_lines(t_data *data, char *str, int i)
{
	int	l;

	l = 0;
	while (str[l] && l < i)
	{
		if (str[l] == '\n')
			data->j++;
		l++;
	}
	data->j++;
}

int	is_last_line(t_data *data, char *str, int len)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	data->j = 0;
	if (len > 0)
	{
		while (str[i])
			i++;
		while (i > 0)
		{
			if (str[i] >= 33 && str[i] <= 126)
				break ;
			i--;
		}
		count_lines(data, str, i);
		if (len >= data->j)
			return (free(str), 0);
		data->map = malloc(sizeof(char *) * data->j + 1);
		if (!data->map)
			return (0);
	}
	return (i);
}

void	store_map(t_data *data, char *str, int check)
{
	data->len = 0;
	data->j = 0;
	while (data->i <= check)
	{
		if (str[data->i] == '\n' || data->i == check)
		{
			data->map[data->j] = ft_calloc(data->len + 2, sizeof(char));
			if (!data->map)
				return ;
			data->i -= data->len;
			data->len = 0;
			while (str[data->i] != '\n' && data->i <= check)
			{
				data->map[data->j][data->len] = str[data->i];
				data->i++;
				data->len++;
			}
			data->j++;
			data->len = -1;
		}
		data->i++;
		data->len++;
	}
	data->map[data->j] = NULL;
}

int	store_elements(t_data *data)
{
	int			i;
	static int	len;
	static int	j;

	i = 0;
	while (data->line[i])
	{
		if (data->line[i] >= 33 && data->line[i] <= 126 && j < 6)
		{
			data->elements[j] = ft_strdup(data->line);
			data->elements[j][ft_strlen(data->elements[j]) - 1] = '\0';
			j++;
			return (len);
		}
		if (j == 6 && data->line[i] == '\n' && (i > 0 || len > 0))
			len++;
		i++;
	}
	return (len);
}

int	fill_spl(t_data *data, int fd)
{
	int			len;
	int			check;
	static char	*str;

	data->elements = malloc(sizeof(char *) * 7);
	if (!data->elements)
		return (0);
	data->line = get_next_line(fd);
	while (data->line)
	{
		len = store_elements(data);
		if (len)
			str = ft_strjoin(str, data->line);
		free(data->line);
		data->line = get_next_line(fd);
	}
	free(data->line);
	check = is_last_line(data, str, len);
	if (check == 0)
		return (0);
	data->i = 0;
	store_map(data, str, check);
	free(str);
	return (1);
}
