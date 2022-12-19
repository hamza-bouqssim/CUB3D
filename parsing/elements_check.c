/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:39:56 by sismaili          #+#    #+#             */
/*   Updated: 2022/12/19 20:56:38 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_elements(t_data *data)
{
	int		i;
	char	**spl;

	i = 0;
	while (data->elements[i])
	{
		spl = ft_split(data->elements[i], ' ');
		printf("%s", spl[0]);
		printf("%s\n", spl[1]);
		free (spl[0]);
		free (spl[1]);
		free (spl);
		i++;
	}
	return (1);
}
