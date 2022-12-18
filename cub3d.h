/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouqssi <hbouqssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:19 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/12/18 20:10:04 by hbouqssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# define BUFFER_SIZE 1
# define HEIGHT 600
# define WIDTH 600
//___________ Lists
typedef struct s_data
{
    void *mlx;
    void *win;
}   t_data;
//________________________
//___________ f_prototypes
char	*get_next_line(int fd);
int     ft_strlen(char *str);
int	    valide_path(char *path);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup( char *s1);
char	**ft_split(char const *s, char c);
int ft_countRows(char **str);
//________________________
#endif