/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:46:35 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/22 18:03:55 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

void	where_is_facing(double angle, t_player *player)
{
	if (angle > 0 && angle < M_PI)
	{
		player->facing_down = 1;
		player->facing_up = -1;
	}
	else
	{
		player->facing_down = -1;
		player->facing_up = 1;
	}
	if (angle < 0.5 * M_PI || angle > 1.5 * M_PI)
	{
		player->facing_right = 1;
		player->facing_left = -1;
	}
	else
	{
		player->facing_right = -1;
		player->facing_left = 1;
	}
}

void	check_cell(t_player *player, char cell, int f)
{
	if (f == 1)
	{
		if (cell == 'D')
			player->data->h_door = 1;
		else
			player->data->h_door = 0;
		return ;
	}
	if (cell == 'D')
		player->data->v_door = 1;
	else
		player->data->v_door = 0;
}

int	checker(double x, double y, t_player *player)
{
	if (cordinate_limit(x / OBJECT, y / OBJECT, player->data))
		return (1);
	return (0);
}

void	horizontal_ray(t_player *player)
{
	double		horizontal_x;
	double		horizontal_y;
	char		cell;

	horizontal_x = player->h_interx;
	horizontal_y = player->h_intery;
	player->h_wall = 0;
	if (player->facing_up == 1)
		horizontal_y -= 0.01;
	while (1)
	{
		if (checker(horizontal_x, horizontal_y, player) == 1)
			return ;
		cell = player->data->maps[(int)(horizontal_y / OBJECT)]
		[(int)(horizontal_x / OBJECT)];
		if (cell == '1' || cell == 'D')
		{
			check_cell(player, cell, 1);
			player->h_wall_hit_x = horizontal_x;
			player->h_wall_hit_y = horizontal_y;
			return (player->h_wall = 1, (void)0);
		}
		horizontal_x += player->h_xsteps;
		horizontal_y += player->h_ysteps;
	}
}

void	vertical_ray(t_player *player)
{
	double		vertical_x;
	double		vertical_y;
	char		cell;

	vertical_x = player->v_interx;
	vertical_y = player->v_intery;
	player->v_wall = 0;
	if (player->facing_left == 1)
		vertical_x -= 0.01;
	while (1)
	{
		if (checker(vertical_x, vertical_y, player) == 1)
			return ;
		cell = player->data->maps[(int)(vertical_y / OBJECT)]
		[(int)((vertical_x) / OBJECT)];
		if (cell == '1' || cell == 'D')
		{
			check_cell(player, cell, 0);
			player->v_wall_hit_x = vertical_x;
			player->v_wall_hit_y = vertical_y;
			return (player->v_wall = 1, (void)0);
		}
		vertical_x += player->v_xsteps;
		vertical_y += player->v_ysteps;
	}
}
