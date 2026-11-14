/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:02:01 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:01 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

static double	move_step(t_player *player)
{
	return (SPEED * player->mlx->mlx->delta_time * 60.0);
}

void	go_forward(t_player *player)
{
	double	new_x;
	double	new_y;
	double	step;

	step = move_step(player);
	new_x = player->x + cos(player->radiant) * step;
	new_y = player->y + sin(player->radiant) * step;
	if (!is_wall(player->data, new_x + COLLISION_RADIUS, player->y)
		&& !is_wall(player->data, new_x - COLLISION_RADIUS, player->y)
		&& !is_wall(player->data, new_x, player->y + COLLISION_RADIUS)
		&& !is_wall(player->data, new_x, player->y - COLLISION_RADIUS))
		player->x = new_x;
	if (!is_wall(player->data, player->x, new_y + COLLISION_RADIUS)
		&& !is_wall(player->data, player->x, new_y - COLLISION_RADIUS)
		&& !is_wall(player->data, player->x + COLLISION_RADIUS, new_y)
		&& !is_wall(player->data, player->x - COLLISION_RADIUS, new_y))
		player->y = new_y;
}

void	go_backward(t_player *player)
{
	double	x;
	double	y;
	double	step;

	step = move_step(player);
	y = player->y;
	x = player->x - cos(player->radiant) * step;
	if (!is_wall(player->data, x + COLLISION_RADIUS, player->y)
		&& !is_wall(player->data, x - COLLISION_RADIUS, player->y)
		&& !is_wall(player->data, x, player->y + COLLISION_RADIUS)
		&& !is_wall(player->data, x, player->y - COLLISION_RADIUS))
		player->x = x;
	y = player->y - sin(player->radiant) * step;
	if (!is_wall(player->data, player->x, y + COLLISION_RADIUS)
		&& !is_wall(player->data, player->x, y - COLLISION_RADIUS)
		&& !is_wall(player->data, player->x + COLLISION_RADIUS, y)
		&& !is_wall(player->data, player->x - COLLISION_RADIUS, y))
		player->y = y;
}

void	turn(t_player	*player, int rl)
{
	double	angle;

	angle = degree_to_radiant(4) * player->mlx->mlx->delta_time * 60.0;
	if (rl == 1)
		player->radiant -= angle;
	else
		player->radiant += angle;
}

void	left_right(t_player	*player, int rl)
{
	double	x;
	double	y;
	double	step;

	step = move_step(player);
	if (rl == 1)
	{
		x = player->x - cos(player->radiant + M_PI / 2) * step;
		y = player->y - sin(player->radiant + M_PI / 2) * step;
	}
	else
	{
		x = player->x + cos(player->radiant + M_PI / 2) * step;
		y = player->y + sin(player->radiant + M_PI / 2) * step;
	}
	if (!is_wall(player->data, x + COLLISION_RADIUS, player->y)
		&& !is_wall(player->data, x - COLLISION_RADIUS, player->y)
		&& !is_wall(player->data, x, player->y + COLLISION_RADIUS)
		&& !is_wall(player->data, x, player->y - COLLISION_RADIUS))
		player->x = x;
	if (!is_wall(player->data, player->x, y + COLLISION_RADIUS)
		&& !is_wall(player->data, player->x, y - COLLISION_RADIUS)
		&& !is_wall(player->data, player->x + COLLISION_RADIUS, y)
		&& !is_wall(player->data, player->x - COLLISION_RADIUS, y))
		player->y = y;
}

int	action(t_player *player)
{
	int	moving;

	moving = 0;
	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_W))
	{
		go_forward(player);
		moving = 1;
	}
	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_S))
	{
		go_backward(player);
		moving = 1;
	}
	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_LEFT))
	{
		turn(player, 1);
		moving = 1;
	}
	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_RIGHT))
	{
		turn(player, 2);
		moving = 1;
	}
	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_A))
	{
		left_right(player, 1);
		moving = 1;
	}
	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_D))
	{
		left_right(player, 0);
		moving = 1;
	}
	return (moving);
}
