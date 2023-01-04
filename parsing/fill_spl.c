/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:12:39 by sismaili          #+#    #+#             */
/*   Updated: 2023/01/04 22:06:07 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	store_map(t_data *data, char *str)
{
	data->i = 0;
	data->j = 0;
	data->len = 0;
	while (str[data->i])
	{
		if (str[data->i] == '\n')
		{
			data->map[data->j] = malloc(sizeof(char) * data->len + 1);
			data->i -= data->len;
			data->len = 0;
			while (str[data->i] != '\n')
			{
				data->map[data->j][data->len] = str[data->i];
				data->i++;
				data->len++;
			}
			data->map[data->j][data->len] = '\0';
			data->j++;
			data->len = -1;
		}
		data->i++;
		data->len++;
	}
	data->map[data->j] = 0;
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

void	fill_spl(t_data *data, int fd)
{
	int			len;
	static char	*str;

	data->elements = malloc(sizeof(char *) * 7);
	if (!data->elements)
		return ;
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
	data->map = malloc(sizeof(char *) * len + 1);
	if (!data->map)
		return ;
	store_map(data, str);
	free(str);
}
