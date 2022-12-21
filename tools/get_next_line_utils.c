/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 10:11:32 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/12/17 18:37:07 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0' && c != '\0' )
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		i;
	char	*tab;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	tab = (char *)malloc((len_s1 + ft_strlen(s2) + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		tab[i] = s1[i];
	i = 0;
	while (s2[i] != '\0')
		tab[len_s1++] = s2[i++];
	tab[len_s1] = '\0';
	free(s1);
	return (tab);
}
