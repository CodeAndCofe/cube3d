/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:55:07 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/20 14:11:18 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

void	draw_square_m(t_pixel *pixel, double x_pos,
		double y_pos, t_mini_data data)
{
	int	i;
	int	x;

	i = 0;
	while (i < data.size)
	{
		x = 0;
		while (x < data.size)
		{
			if (((int) x_pos * data.size + x) < M_SIZE
				&& ((int)y_pos * data.size + i) < M_SIZE)
				pixel_putter(pixel, (x_pos * data.size) + x,
					(y_pos * data.size) + i, data.color);
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
			pixel_putter(pixel, px + x, py + y, 0xFFFF00);
			x++;
		}
		y++;
	}
}

void	draw_in_mini_map(t_player *player, t_pixel *pixel, t_mini data)
{
	t_mini_data	info;

	info.size = TILE_SIZE;
	if (player->data->maps[data.map_y][data.map_x] == '1')
	{
		info.color = 0x444444;
		draw_square_m(pixel, data.map_x - data.start_x,
			data.map_y - data.start_y, info);
	}
	else if (player->data->maps[data.map_y][data.map_x] == 'D'
		|| player->data->maps[data.map_y][data.map_x] == 'd')
	{
		info.color = 0x00BFFF;
		draw_square_m(pixel, data.map_x - data.start_x,
			data.map_y - data.start_y, info);
	}
	else
	{
		info.color = 0xAAAAAA;
		draw_square_m(pixel, data.map_x - data.start_x,
			data.map_y - data.start_y, info);
	}
}

void	draw_map_in_two_dimension(t_pixel *pixel, t_player *player)
{
	t_mini	data;

	data.start_y = (int)player->y - MINI_RADIUS;
	data.start_x = (int)player->x - MINI_RADIUS;
	data.end_x = (int)player->x + MINI_RADIUS;
	data.end_y = (int)player->y + MINI_RADIUS;
	data.map_y = data.start_y;
	while (data.map_y <= data.end_y)
	{
		data.map_x = data.start_x;
		while (data.map_x <= data.end_x)
		{
			if (cordinate_limit(data.map_x, data.map_y, player->data))
			{
				data.map_x++;
				continue ;
			}
			draw_in_mini_map(player, pixel, data);
			data.map_x ++;
		}
		data.map_y++;
	}
}

int	draw_map_bonus(t_pixel *pixel, t_mlx *new_mlx,
	t_player *player, t_pixel *new_pixel)
{
	free_text(player);
	new_pixel->img = mlx_new_image(new_mlx->mlx, M_SIZE, M_SIZE);
	new_pixel->addr = mlx_get_data_addr(new_pixel->img,
			&new_pixel->bits_per_pixel,
			&new_pixel->line_length, &new_pixel->endian);
	pixel->img = mlx_new_image(new_mlx->mlx, WIDTH, HEIGHT);
	pixel->addr = mlx_get_data_addr(pixel->img, &pixel->bits_per_pixel,
			&pixel->line_length, &pixel->endian);
	load_texture(player);
	player_view(pixel, player);
	draw_map_in_two_dimension(new_pixel, player);
	draw_player_on_minimap(new_pixel);
	mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, pixel->img, 0, 0);
	mlx_put_image_to_window(new_mlx->mlx,
		new_mlx->win_mlx, new_pixel->img, 0, 0);
	return (1);
}
