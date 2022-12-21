/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:22:32 by sismaili          #+#    #+#             */
/*   Updated: 2022/12/20 15:18:40 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valide_path(char *path, char *str)
{
	int		len;
	int		index;
	int		i;
	char	*ext;

	i = 0;
	ext = str;
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
