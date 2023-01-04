/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:02:35 by sismaili          #+#    #+#             */
/*   Updated: 2023/01/04 23:26:07 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    add_node(t_node *garbage, void *pointer)
{
    t_node    *node;

    node = malloc(sizeof(t_node));
    node->pointer = pointer;
    node->next =garbage;
    garbage = node;
}

void    free_node(t_node *garbage)
{
    void    *tmp;

    tmp = NULL;
    while (garbage)
    {
        free(garbage->pointer);
        tmp = garbage;
        garbage = garbage->next;
        free(tmp);
    }
}

void	ft_free(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
		free (spl[i++]);
	free (spl);
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
