/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:39:56 by sismaili          #+#    #+#             */
/*   Updated: 2022/12/25 18:55:26 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_double(char **spl, char **str)
{
	static int	i;
	int			j;

	str[i] = ft_strdup(spl[0]);
	i++;
	if (i == 6)
	{
		str[i] = NULL;
		i = 0;
		while (str[i])
		{
			j = i + 1;
			while (str[j])
			{
				if (!ft_strcmp(str[i], str[j]))
					return (0);
				j++;
			}
			i++;
		}
	}
	return (1);
}

static int	rgb_check(char **str)
{
	char	**rgb;
	int		i;
	int		n;

	i = 0;
	if ((!ft_strcmp(str[0], "F") || !ft_strcmp(str[0], "C")))
	{
		rgb = ft_split(str[1], ',');
		while (rgb[i])
			i++;
		if (i != 3)
			return (0);
		i = 0;
		while (rgb[i])
		{
			n = ft_atoi(rgb[i]);
			if (n < 0 || n > 255 || !is_digit(rgb[i]))
				return (0);
			i++;
		}
		ft_free(rgb);
	}
	return (1);
}

static int	checker(char **spl)
{
	int	fd;

	if (!spl[1] || spl[2])
		return (0);
	if (ft_strcmp(spl[0], "NO") && ft_strcmp(spl[0], "SO")
		&& ft_strcmp(spl[0], "WE") && ft_strcmp(spl[0], "EA")
		&& ft_strcmp(spl[0], "F") && ft_strcmp(spl[0], "C"))
		return (0);
	fd = open(spl[1], O_RDONLY);
	if ((fd < 0 || valide_path(spl[1], ".xpm") == 0) && ft_strcmp(spl[0], "F")
		&& ft_strcmp(spl[0], "C"))
		return (0);
	if (!rgb_check(spl))
		return (0);
	return (1);
}

int	check_elements(t_data *data)
{
	int		i;
	char	**spl;
	char	**str;

	i = 0;
	str = malloc(sizeof(char *) * 7);
	if (!data->elements || !str)
		return (0);
	while (data->elements[i])
	{
		spl = ft_split(data->elements[i], ' ');
		if (!checker(spl))
		{
			ft_free (spl);
			return (0);
		}
		else if (!check_double(spl, str))
		{
			ft_free (str);
			return (0);
		}
		ft_free(spl);
		i++;
	}
	ft_free (str);
	return (1);
}
