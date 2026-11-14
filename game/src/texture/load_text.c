/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:01:48 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:01 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

int	load_door(t_player *player)
{
	player->data->door_texture = load_xpm("textures/door.xpm");
	if (!player->data->door_texture)
		return (0);
	player->data->door_address = player->data->door_texture->pixels;
	player->data->door_tex_width = player->data->door_texture->width;
	player->data->door_tex_height = player->data->door_texture->height;
	return (1);
}

void	init_tex_side(uint8_t **tex_side, int wall_side, t_player *player)
{
	if (wall_side == 0)
		*tex_side = player->data->no_address;
	else if (wall_side == 1)
		*tex_side = player->data->so_address;
	else if (wall_side == 2)
		*tex_side = player->data->we_address;
	else if (wall_side == 3)
		*tex_side = player->data->ea_address;
	else if (wall_side == 4)
		*tex_side = player->data->door_address;
}

double	get_top(double wall_height)
{
	double	top;

	top = (HEIGHT / 2) - (wall_height / 2);
	if (top < 0)
		top = 0;
	return (top);
}

double	get_bottom(double wall_height)
{
	double	bottom;

	bottom = (HEIGHT / 2) + (wall_height / 2);
	if (bottom >= HEIGHT)
		bottom = HEIGHT;
	return (bottom);
}

int	get_texture_pixel(uint8_t *addr, int x, int y, t_player *player)
{
	int	width;

	if (player->wall_side == 4)
		width = player->data->door_tex_width;
	else
		width = player->data->tex_with;
	return (((uint32_t *)addr)[y * width + x]);
}
