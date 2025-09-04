/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:15:02 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/02 16:57:39 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    my_square(t_mlx *new_mlx, t_pixel *data, int size, int color)
{
    int i = 0;
    int j = 0;

    data->img = mlx_new_image(new_mlx->mlx, size, size);// create new img 
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);// set color for image
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            my_mlx_pixel_put(data, j, i, color);
            j++;
        }
        i++;
    }
}