/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:19 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/12/21 17:34:37 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# define HEIGHT 600
# define WIDTH 600

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*line;
	char	**spl;
	char	**elements;
	char	**map;
}	t_data;

size_t	ft_strlen(char *str);
int		valide_path(char *path, char *str);
void	fill_spl(t_data *data, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s1);
int		ft_isspace(int c);
int		ft_strcmp(const char *s1, const char *s2);
void    ft_free(char **spl);
int		ft_atoi(const char *str);
int		is_digit(char *str);
int		check_elements(t_data *data);
int		map_check(t_data *data);

#endif