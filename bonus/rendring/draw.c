/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:55:07 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/16 21:00:51 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void	draw_square_m(t_pixel *pixel, double x_pos, double y_pos, int color, int size)
{
	int	i;
	int	x;
	
	i = 0;
	while (i < size)
	{
		x = 0;
		while (x < size)
		{
			if (((int) x_pos * size + x) < M_SIZE && ((int)y_pos * size + i) < M_SIZE)
				my_mlx_pixel_put(pixel, (x_pos * size) + x, (y_pos * size) + i, color);
			x++;
		}
		i++;
	}
}

void	draw_player_on_minimap(t_pixel *pixel)
{
	int	px;
	int	py;
	int	size;
	int	y;
	int	x;

	px = MINI_RADIUS * TILE_SIZE + TILE_SIZE / 2;
	py = MINI_RADIUS * TILE_SIZE + TILE_SIZE / 2;
	size = 3;
	y = -size;
	while (y <= size)
	{
		x = -size;
		while (x <= size)
		{
			my_mlx_pixel_put(pixel, px + x, py + y, 0xFFFF00);
			x++;
		}
		y++;
	}
}

void draw_map_in_two_dimension(t_pixel *pixel, t_player *player)
{
	int		map_y;
	int		map_x;
	t_mini	data;

	data.start_y = (int)player->y - MINI_RADIUS;
	data.start_x = (int)player->x - MINI_RADIUS;
	data.end_x = (int)player->x + MINI_RADIUS;
	data.end_y = (int)player->y + MINI_RADIUS;
	map_y = data.start_y;
	while (map_y <= data.end_y)
	{
		map_x = data.start_x;
		while (map_x <= data.end_x)
		{
			if (cordinate_limit(map_x, map_y, player->data))
			{
				map_x++;
				continue;
			}
			if (player->data->maps[map_y][map_x] == '1')
				draw_square_m(pixel, map_x - data.start_x, map_y - data.start_y, 0x444444, TILE_SIZE);
			else
				draw_square_m(pixel, map_x - data.start_x, map_y - data.start_y, 0xAAAAAA, TILE_SIZE);
			map_x ++;
		}
		map_y++;
	}
}


int draw_map(t_pixel *pixel, t_mlx *new_mlx, t_player *player)
{
	t_pixel	new_pixel;

	new_pixel.img= mlx_new_image(new_mlx->mlx, M_SIZE, M_SIZE);
	new_pixel.addr = mlx_get_data_addr(new_pixel.img, &new_pixel.bits_per_pixel, &new_pixel.line_length, &new_pixel.endian);
	pixel->img = mlx_new_image(new_mlx->mlx, WIDTH, HEIGHT);
	pixel->addr = mlx_get_data_addr(pixel->img, &pixel->bits_per_pixel, &pixel->line_length, &pixel->endian);


    load_texture(player);
	player_view(pixel, player);
	draw_map_in_two_dimension(&new_pixel, player);
	draw_player_on_minimap(&new_pixel);
	mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, pixel->img, 0, 0);
	mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, new_pixel.img, 0, 0);
	return (1);
}