/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:47:41 by hbouqssi          #+#    #+#             */
/*   Updated: 2023/01/04 17:13:06 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
char	*ft_read_buff(int fd, char *buffer)
{
	char	*buf;
	int		ret;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	ret = 1;
	while (!ft_strchr(buffer, '\n') && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		printf("%d\n", ret);
		if (ret == -1)
		{
			free(buf);
			return (0);
		}
		buf[ret] = '\0';
		buffer = ft_strjoin(buffer, buf);
	}
	free(buf);
	return (buffer);
}

char	*ft_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		line[j++] = buffer[i++];
	if (buffer[i] == '\n')
		line[j++] = buffer[i];
	line[j] = '\0';
	return (line);
}

char	*ft_res(char *buffer)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	len = ft_strlen(buffer) - i;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	i++;
	j = 0;
	while (buffer[i])
		res[j++] = buffer[i++];
	res[j] = '\0';
	free(buffer);
	return (res);
}

char	*gnl(int fd)
{
	char		*line;
	static char	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = ft_read_buff(fd, buff);
	if (!buff)
		return (0);
	line = ft_line(buff);
	buff = ft_res(buff);
	return (line);
}