/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:47:40 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/21 17:45:44 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

double	calculate_distance(double px, double py, double dx, double dy)
{
	return (sqrt((dx - px) * (dx - px) + (dy - py) * (dy - py)));
}

void	the_intersects_horizontal(double ray_angle, t_player *player)
{
	player->h_intery = floor(player->y) * OBJECT;
	if (player->facing_down == 1)
		player->h_intery += OBJECT;
	player->h_interx = (player->x * OBJECT)
		+ (player->h_intery - player->y * OBJECT) / tan(ray_angle);
	player->h_ysteps = OBJECT * player->facing_down;
	player->h_xsteps = OBJECT / tan(ray_angle);
	if ((player->facing_left == 1 && player->h_xsteps > 0)
		|| (player->facing_right == 1 && player->h_xsteps < 0))
		player->h_xsteps *= -1;
}

void	the_intersects_vertical(double ray_angle, t_player *player)
{
	player->v_interx = floor(player->x) * OBJECT;
	if (player->facing_right == 1)
		player->v_interx += OBJECT;
	player->v_intery = (player->y * OBJECT)
		+ (player->v_interx - player->x * OBJECT) * tan(ray_angle);
	player->v_xsteps = OBJECT;
	player->v_xsteps *= player->facing_right;
	player->v_ysteps = player->v_xsteps * tan(ray_angle);
	if (player->facing_up == 1 && player->v_ysteps > 0)
		player->v_ysteps *= -1;
	else if (player->facing_down == 1 && player->v_ysteps < 0)
		player->v_ysteps *= -1;
}
