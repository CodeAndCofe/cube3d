/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:58:45 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/02 17:10:48 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EX_CUB_H
#define EX_CUB_H
#include "../include/cub.h"
#include "mlx.h"
#include <stdio.h>

typedef struct  s_pixel
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    struct  s_pixel *next;
}t_pixel;

typedef struct s_mlx
{
    void    *mlx;
    void    *win_mlx;  
}t_mlx;

t_pixel *new_pixel(t_pixel *pixel);
int    add_temporary_map(t_data    *data);
void    my_square(t_mlx *new_mlx, t_pixel *data, int size, int color);
void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color);
#endif