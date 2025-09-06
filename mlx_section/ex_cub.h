/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:38:24 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/06 13:09:46 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EX_CUB_H
#define EX_CUB_H
#include "cub.h"
#include <mlx.h>
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

typedef struct  s_player
{
    double  x;
    double  y;
    double  degre;
    
}t_player;

t_pixel *new_pixel(t_pixel *pixel);
void    my_square(t_mlx *new_mlx, t_pixel *data, int size, int color);
void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color);
#endif