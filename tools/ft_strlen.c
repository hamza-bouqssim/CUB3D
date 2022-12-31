/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:21:02 by sismaili          #+#    #+#             */
/*   Updated: 2022/12/31 14:47:50 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_count_columns(char **str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		if (j > len)
			len = j;
		i++;
	}
	return (len);
}

int	ft_count_rows(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
