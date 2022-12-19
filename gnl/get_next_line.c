/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:23:32 by sismaili          #+#    #+#             */
/*   Updated: 2022/12/19 20:51:50 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fd(int fd, char *str)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buffer);
			return (0);
		}
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*ft_first_line(char *str)
{
	char	*first;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
		i++;
	first = (char *)malloc(sizeof(char) * (i + 1));
	if (!first)
		return (0);
	i = 0;
	while (str[i])
	{
		first[i] = str[i];
		i++;
	}
	first[i] = '\0';
	return (first);
}

char	*ft_next(char *str)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	next = (char *)malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!next)
		return (0);
	i++;
	while (str[i])
		next[j++] = str[i++];
	next[j] = '\0';
	free (str);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read_fd(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_first_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
