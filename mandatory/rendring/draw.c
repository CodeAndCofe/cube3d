/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:55:07 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/18 13:55:30 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void	draw_player(t_pixel *pixel, t_player *player, int size)
{
	int	x;
	int y;

	y = -size / 2;
	while (y < size / 2)
	{
		x = -size / 2;
		while (x < size / 2)
		{
			player->p_pos_x = ((player->x) * OBJECT) + x;
			player->p_pos_y = ((player->y) * OBJECT) + y;
			pixel_putter(pixel ,  player->p_pos_x,  player->p_pos_y, G_COLOR);
			x++;
		}
		y++;
	}
}

void draw_map_in_two_dimension(t_pixel *pixel, t_player *player)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (player->data->maps[i])
	{
		j = 0;
		while (player->data->maps[i][j])
		{
			if (player->data->maps[i][j] == '1')
				draw_square(pixel, i, j, P_COLOR, OBJECT);
			else
				draw_square(pixel, i, j, L_COLOR, OBJECT);
			j++;
		}
		i++;
	}
}

int draw_map(t_pixel *pixel, t_mlx *new_mlx, t_player *player)
{
	pixel->img = mlx_new_image(new_mlx->mlx, WIDTH, HEIGHT);
	pixel->addr = mlx_get_data_addr(pixel->img, &pixel->bits_per_pixel, &pixel->line_length, &pixel->endian);// add pixel to image

	// draw_map_in_two_dimension(pixel, player);
	// draw_player(pixel, player, OBJECT / 2);
    load_texture(player);
	player_view(pixel, player);
	mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, pixel->img, 0, 0);// put image into window
	return (1);
}