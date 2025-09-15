/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:48:01 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/14 14:35:42 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

int	draw_player(t_pixel *pixel, t_player *player, int size, int color)
{
	int x = 0;
    int y = 0;
    
    while (y < size)
    {
        x = 0;
        while (x < size)
        {
            my_mlx_pixel_put(pixel , (player->x * OBJECT) + x, (player->y * OBJECT) + y, color);
            x++;
        }
        y++;
    }
	return (0);
}

int draw_line(t_pixel *pixel, t_player *player, double max_distance, int color)
{
    double ray_angle = player->radiant;
    double ray_x     = player->x;
    double ray_y     = player->y;
    double ray_cos = cos(ray_angle) * 0.02;
    double ray_sin = sin(ray_angle) * 0.02;
    double distance = 0;
    
    while (distance < max_distance)
    {
        ray_x += ray_cos;
        ray_y += ray_sin;
        distance += 0.02;
        int pixel_x = ray_x * OBJECT;
        int pixel_y = ray_y * OBJECT;
        if (player->data->maps[(int)ray_y][(int)ray_x] == '1')
            break;
        my_mlx_pixel_put(pixel, pixel_x, pixel_y, color);
    }
    
    return (distance);
}
int	draw_map(t_pixel *pixel, t_mlx *new_mlx, t_player *player)
{
	int	i = 0;
	int	j = 0;
	pixel->img = mlx_new_image(new_mlx->mlx, HIGTH, WIDTH);
    pixel->addr = mlx_get_data_addr(pixel->img, &pixel->bits_per_pixel, &pixel->line_length, &pixel->endian);
	while (player->data->maps[i])
	{
	    j = 0;
	    while (player->data->maps[i][j])
		{
			if (player->data->maps[i][j] == '1')
				draw_square(pixel, i, j, 0x222222, OBJECT);
			else
				draw_square(pixel, i, j, 0x808000, OBJECT);
            j++;
		}
		i++;
	}
	draw_player(pixel, player, OBJECT / 2, 0x00FF00);
	draw_line(pixel, player, 60, 0x0000FF);
	mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, pixel->img, 0, 0);
	return (0);
}