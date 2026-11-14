/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:32:50 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:01 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

int	get_text_y(double tex_height, double text_pos, t_player *player)
{
	int	text_y;

	(void)player;
	text_y = (int)text_pos;
	if (text_y >= tex_height)
		text_y = tex_height - 1;
	if (text_y < 0)
		text_y = 0;
	return (text_y);
}

int	get_text_x(t_player *player, double hit_point)
{
	int	text_x;

	text_x = (int)(hit_point * player->data->tex_with);
	if (text_x >= player->data->tex_with)
		text_x = player->data->tex_with - 1;
	if (text_x <= 0)
		text_x = 0;
	return (text_x);
}

void	draw_ceilling(double top, t_pixel *pixel, int x, t_player *player)
{
	int	i;

	i = 0;
	while (i < (int)top)
	{
		if (player->data->sky_texture)
			pixel_putter(pixel, x, i, ((uint32_t *)player->data->sky_texture->pixels)
				[((i * player->data->sky_texture->height) / (HEIGHT / 2))
				* player->data->sky_texture->width
				+ (x * player->data->sky_texture->width) / WIDTH]);
		else
			pixel_putter(pixel, x, i, player->data->c_color);
		i++;
	}
}

void	draw_floor(double bottom, t_pixel *pixel, int x, t_player *player)
{
	int	i;
	int	floor_color;
	int	text_x;
	int	text_y;
	double	floor_distance;
	double	ray_angle;
	double	floor_x;
	double	floor_y;

	i = (int)bottom;
	while (i < HEIGHT)
	{
		if (i <= HEIGHT / 2)
		{
			i++;
			continue ;
		}
		floor_distance = (HEIGHT * 0.5) / (i - HEIGHT * 0.5);
		ray_angle = player->radiant + atan((((double)x + 0.5) / WIDTH * 2.0
				- 1.0) * tan(degree_to_radiant(VIEW / 2)));
		floor_x = player->x + cos(ray_angle) * floor_distance;
		floor_y = player->y + sin(ray_angle) * floor_distance;
		if (player->data->ground_texture)
		{
			text_x = (int)((floor_x - floor(floor_x))
				* player->data->ground_texture->width);
			text_y = (int)((floor_y - floor(floor_y))
				* player->data->ground_texture->height);
			floor_color = ((uint32_t *)player->data->ground_texture->pixels)
				[text_y * player->data->ground_texture->width + text_x];
		}
		else
			floor_color = 0x493A3D;
		pixel_putter(pixel, x, i, floor_color);
		i++;
	}
}

int	get_pixel_color(uint8_t *text_side, int text_x, int text_y, t_player *player)
{
	int	color;
	int	width;
	int	height;

	if (player->wall_side == 4)
	{
		width = player->data->door_tex_width;
		height = player->data->door_tex_height;
	}
	else
	{
		width = player->data->tex_with;
		height = player->data->tex_height;
	}
	if (text_x < 0 || text_x >= width || text_y < 0 || text_y >= height)
		return (0);
	color = get_texture_pixel(text_side, text_x, text_y, player);
	return (color);
}
