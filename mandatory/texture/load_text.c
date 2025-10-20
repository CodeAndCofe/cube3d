/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:01:48 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 14:15:45 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

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

int	get_texture_pixel(char *addr, int x, int y, t_player *player)
{
	int	offset;

	offset = (y * player->data->tex_line_len)
		+ (x * (player->data->tex_bpp / 8));
	return (*(int *)(addr + offset));
}
