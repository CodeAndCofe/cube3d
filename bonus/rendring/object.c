/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:06:27 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/18 13:55:30 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

int the_limit(int x, int y)
{
    if (x < 0 || x > WIDTH - 1 || y < 0 || y > HEIGHT - 1) 
        return (1);
    return (0);
}

int cordinate_limit(int x, int y, t_data *data)
{
	if (y < 0 || y >= data->map_lines || 
	    x < 0 || x >= (int)ft_strlen(data->maps[y]))
	{
		return (1);
	}
    return (0);
}

void	pixel_putter(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	if (the_limit(x, y) == 1) 
        return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void   draw_square(t_pixel *pixel, int i, int j, int color, int size)
{
    int x;
    int y;
    
    x = 1;
    y = 1;
    while (y < size)
    {
        x = 1;
        while (x < size)
        {
            pixel_putter(pixel , (j * OBJECT) + x, (i * OBJECT) + y, color);
            x++;
        }
        y++;
    }
}
