/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:46:35 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/16 21:06:55 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

double	reset_radiant(double	angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

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

void	the_intersects_horizontal(double ray_angle, t_player *player)
{
	player->h_intery = floor(player->y) * OBJECT;
	if (player->facing_down == 1)
		player->h_intery += OBJECT;
	player->h_interx = (player->x * OBJECT) + (player->h_intery - player->y * OBJECT) / tan(ray_angle);
	player->h_ysteps = OBJECT * player->facing_down;
	player->h_xsteps = OBJECT / tan(ray_angle);
	if ((player->facing_left == 1 && player->h_xsteps > 0) ||
		(player->facing_right == 1 && player->h_xsteps < 0))
		player->h_xsteps *= -1;
}

void	the_intersects_vertical(double ray_angle, t_player *player)
{
	player->v_interx = floor(player->x) * OBJECT;
	if (player->facing_right == 1)
		player->v_interx += OBJECT;
	player->v_intery = (player->y * OBJECT) + (player->v_interx - player->x * OBJECT) * tan(ray_angle);
	player->v_xsteps = OBJECT;
	player->v_xsteps *= player->facing_right;
	player->v_ysteps = player->v_xsteps * tan(ray_angle);
	if (player->facing_up == 1 && player->v_ysteps > 0)
		player->v_ysteps *= -1;
	else if (player->facing_down == 1 && player->v_ysteps < 0)
		player->v_ysteps *= -1;
}

void	horizontal_ray(t_player *player, t_pixel *pixel)
{
	(void) pixel;
	double		horizontal_x;
	double		horizontal_y;
	char cell;

	horizontal_x = player->h_interx;
	horizontal_y = player->h_intery;
	player->h_wall = 0;
	if (player->facing_up == 1)
		horizontal_y -= 0.01;
	while (1)
	{
		if (the_limit(horizontal_x, horizontal_y) == 1
			|| cordinate_limit(horizontal_x / OBJECT, horizontal_y / OBJECT, player->data))
			return ;
		cell = player->data->maps[(int)(horizontal_y / OBJECT)][(int)(horizontal_x / OBJECT)];
		if (cell == '1' || cell == 'D')
		{
			if (cell == 'D')
				player->data->h_door = 1;
			else
				player->data->h_door = 0;
			player->h_wall_hit_x = horizontal_x;
			player->h_wall_hit_y = horizontal_y;
			player->h_wall = 1;
			break;
		}
		else if (cell == 'd')
		{
			horizontal_x += player->h_xsteps;
			horizontal_y += player->h_ysteps;			
			continue;
		}
		horizontal_x += player->h_xsteps;
		horizontal_y += player->h_ysteps;
	}
}

void	vertical_ray(t_player *player, t_pixel *pixel)
{
	(void) pixel;
	double		vertical_x;
	double		vertical_y;
	char cell;

	vertical_x = player->v_interx;
	vertical_y = player->v_intery;
	player->v_wall = 0;
	if (player->facing_left == 1)
		vertical_x -= 0.01;
	while (1)
	{
		if (the_limit(vertical_x, vertical_y) == 1
			|| cordinate_limit((vertical_x / OBJECT), (vertical_y / OBJECT), player->data))
			return ;
		cell = player->data->maps[(int)(vertical_y / OBJECT)][(int)((vertical_x) / OBJECT)];
		if (cell == '1' || cell == 'D')
		{
			if (cell == 'D')
				player->data->v_door = 1;
			else
				player->data->v_door = 0;
			player->v_wall_hit_x = vertical_x;
			player->v_wall_hit_y = vertical_y;
			player->v_wall = 1;
			break;
		}
		else if (cell == 'd')
		{
			vertical_x += player->v_xsteps;
			vertical_y += player->v_ysteps;		
			continue;
		}
		vertical_x += player->v_xsteps;
		vertical_y += player->v_ysteps;
	} 
}

