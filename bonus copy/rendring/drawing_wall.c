/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:05:59 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/18 17:37:12 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

static void draw_wall(double wall_height, int wall_side, t_pixel *pixel, int x, t_player *player)
{
	t_wall	data;
	int i;
	
	if (!pixel || !player || !player->data || x < 0 || x >= WIDTH)
		return ;
	data.top = get_top(wall_height);
	data.bottom = get_bottom(wall_height);
	init_tex_side(&data.text_side, wall_side, player);
	data.text_x = get_text_x(player, player->hit_point);
	data.tex_step = (double)player->data->tex_height / wall_height;
	data.tex_pos = (data.top - HEIGHT / 2 + wall_height / 2) * data.tex_step;
	data.x = x;
	i = data.top;
	while (i < data.bottom)
	{
		data.text_y = get_text_y(player->data->tex_height, data.tex_pos, player);
		data.color =get_texture_pixel(data.text_side, data.text_x, data.text_y, player);
		pixel_putter(pixel, data.x, i,data.color);
		data.tex_pos += data.tex_step;
		i++;
	}
	draw_ceilling(data.top, pixel, data.x, player);
	draw_floor(data.bottom, pixel, data.x, player);
}

void	drawing_wall(t_player *player, t_pixel *pixel, int i, double ray_angle)
{
	double  correct_distance;
	double	projectplane_distnace;
	double	wall_hieght;

	correct_distance = player->distance * cos(ray_angle - player->radiant);
	projectplane_distnace = (WIDTH / 2) / tan(degree_to_radiant(VIEW / 2));// prjoect plane
	wall_hieght = ((double) OBJECT / correct_distance) * projectplane_distnace;
	draw_wall(wall_hieght, player->wall_side, pixel, i, player);
}
