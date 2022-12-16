/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:23:19 by hbouqssi          #+#    #+#             */
/*   Updated: 2022/12/16 18:02:17 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <fcntl.h>
#define HEIGHT 600
#define WIDTH 600
//___________ Lists
typedef struct s_data
{
    void *mlx;
    void *win;
}   t_data;
//________________________
//___________ f_prototypes

//________________________
#endif