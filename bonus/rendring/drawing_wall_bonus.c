/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:05:59 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:01 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

static void	draw_wall_on_screen(t_wall *data, t_pixel *pixel, t_player *player)
{
	int	i;

	i = data->top;
	while (i < data->bottom)
	{
		data->text_y = get_text_y(data->tex_height, data->tex_pos, player);
		data->color = get_pixel_color(data->text_side,
				data->text_x, data->text_y, player);
		pixel_putter(pixel, data->x, i, data->color);
		data->tex_pos += data->tex_step;
		i++;
	}
	draw_ceilling(data->top, pixel, data->x, player);
	draw_floor(data->bottom, pixel, data->x, player);
}

static void	draw_wall(int wall_side, t_pixel *pixel,
		t_player *player, t_wall_info info)
{
	t_wall	data;

	data.top = get_top(info.height);
	data.bottom = get_bottom(info.height);
	init_tex_side(&data.text_side, wall_side, player);
	if (player->wall_side == 4)
	{
		data.text_x = (int)(player->hit_point * player->data->door_tex_width);
		if (data.text_x >= player->data->door_tex_width)
			data.text_x = player->data->door_tex_width - 1;
		if (data.text_x < 0)
			data.text_x = 0;
		data.tex_height = player->data->door_tex_height;
	}
	else
	{
		data.text_x = get_text_x(player, player->hit_point);
		data.tex_height = player->data->tex_height;
	}
	data.tex_step = (double)data.tex_height / info.height;
	data.tex_pos = (data.top - HEIGHT / 2 + info.height / 2) * data.tex_step;
	data.x = info.id;
	draw_wall_on_screen(&data, pixel, player);
}

void	drawing_wall(t_player *player, t_pixel *pixel, int i, double ray_angle)
{
	t_wall_info	wall_info;
	double		correct_distance;
	double		projectplane_distnace;
	double		wall_hieght;

	correct_distance = player->distance * cos(ray_angle - player->radiant);
	projectplane_distnace = (WIDTH / 2) / tan(degree_to_radiant(VIEW / 2));
	wall_hieght = ((double) OBJECT / correct_distance) * projectplane_distnace;
	wall_info.height = wall_hieght;
	wall_info.id = i;
	draw_wall(player->wall_side, pixel, player, wall_info);
}
