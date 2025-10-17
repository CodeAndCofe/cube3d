/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:01:48 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/17 11:08:26 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

int	load_door(t_player *player)
{
	player->data->door_texture = mlx_xpm_file_to_image(player->mlx->mlx, "texture/door.xpm",
			&player->data->door_tex_width, &player->data->door_tex_height);
	player->data->door_address = mlx_get_data_addr(player->data->door_texture,
			&player->data->door_tex_bpp, &player->data->door_tex_line_len,
			&player->data->door_tex_endian);
	if (player->data->door_address || player->data->door_texture)
		return (1);
	return (0);
}

void	init_tex_side(char **tex_side, int wall_side, t_player *player)
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
		bottom = HEIGHT - 1;
	return (bottom);
}

int	get_texture_pixel(char *addr, int x, int y, t_player *player)
{
	int	offset;

	offset = (y * player->line_len) + (x * (player->bpp / 8));
	return (*(int *)(addr + offset));
}
