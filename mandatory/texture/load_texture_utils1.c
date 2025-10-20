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
		pixel_putter(pixel, x, i, player->data->c_color);
		i++;
	}
}

void	draw_floor(double bottom, t_pixel *pixel, int x, t_player *player)
{
	int	i;

	i = (int)bottom;
	while (i < HEIGHT)
	{
		pixel_putter(pixel, x, i, player->data->f_color);
		i++;
	}
}
