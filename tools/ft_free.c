/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:02:35 by sismaili          #+#    #+#             */
/*   Updated: 2023/01/05 22:47:07 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
		free(spl[i++]);
	free(spl);
}

void	free_all(t_data *data)
{
	if (data->elements)
		ft_free(data->elements);
	if (data->map)
		ft_free(data->map);
	if (data->f_rgb)
		ft_free(data->f_rgb);
	if (data->c_rgb)
		ft_free(data->c_rgb);
	if (data->path)
		ft_free(data->path);
}
