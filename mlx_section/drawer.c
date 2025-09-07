/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:15:02 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/06 21:08:33 by aferryat         ###   ########.fr       */
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

void    player_pixel(t_mlx *new_mlx, t_pixel *data, int size, int color)
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

t_pixel    *draw_object(t_player  *player, int i , int j, t_mlx *new_mlx)// function not protected!
{
    t_pixel     *wlk;

    wlk = malloc(sizeof (t_pixel));
    if (wlk == NULL)
        return (NULL);
    if (player->data->maps[i][j] == '1')
        my_square(new_mlx, wlk, 50, 0x00FF0000);
    else
        my_square(new_mlx, wlk, 50, 0x0000FF00);
    return (wlk);
}