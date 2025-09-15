/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:07:02 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/14 13:36:18 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void   draw_square(t_pixel *pixel, int i, int j, int color, int size)
{
    int x = 0;
    int y = 0;
    
    while (y < size)
    {
        x = 0;
        while (x < size)
        {
            my_mlx_pixel_put(pixel , (j * OBJECT) + x, (i * OBJECT) + y, color);
            x++;
        }
        y++;
    }
}

