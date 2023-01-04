/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_spl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:12:39 by sismaili          #+#    #+#             */
/*   Updated: 2023/01/04 16:48:25 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


// int find_empty_line(char *str)
// {
//   int i = 0;

//   while (str[i] != '\0')
//   {
//     if (str[i] == '\n' && str[i + 1] == '\n')
// 	{
//       printf("Error: Empty line found\n");
//       return (1);
//     }
//     i++;
//   }
//   return 0;
// }

void store_string_in_2d_array(char *str, int fd)
{
  int i = 0;
//   int j = 0;
  char **array;
  while (str)
  {
	i++;
	str = get_next_line(fd);
  }
  array = malloc(sizeof(char *) * i + 1);
  if (!array)
	return ;
// 	i = 0;
// 	array[i] = ft_strdup(str);
	// while(array[i])
	// {
	// 	puts("printi");
	// 	i++;
	// 	array[i] = gnl(fd);
	// }
}

void	fill_spl(t_data *data, int fd)
{
	int	i;
	i = 0;
	data->line = get_next_line(fd);
	store_string_in_2d_array(data->line, fd);
	puts("OK");
	
	// data->spl = ft_split(data->line, '\n');
	// if (data->spl)
	// {
	// 	while (data->spl[i])
	// 		i++;
	// 	data->elements = malloc(sizeof(char *) * 7);
	// 	data->map = malloc(sizeof(char *) * (i - 5));
	// 	if (!data->elements || !data->map)
	// 		return ;
	// 	i = 0;
	// 	while (data->spl[i])
	// 	{
	// 		if (i < 6)
	// 			data->elements[i] = ft_strdup(data->spl[i]);
	// 		else
	// 		{
	// 			data->map[i - 6] = ft_strdup(data->spl[i]);
	// 		}
	// 		i++;
	// 	}
	// 	data->elements[6] = NULL;
	// 	data->map[i - 6] = NULL;
	// }
}
