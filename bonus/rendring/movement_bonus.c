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

void	go_forward(t_player *player)
{
	double	new_x;
	double	new_y;

	new_x = player->x + cos(player->radiant) * SPEED;
	new_y = player->y + sin(player->radiant) * SPEED;
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

	y = player->y;
	x = player->x - cos(player->radiant) * SPEED;
	if (!is_wall(player->data, x + COLLISION_RADIUS, player->y)
		&& !is_wall(player->data, x - COLLISION_RADIUS, player->y)
		&& !is_wall(player->data, x, player->y + COLLISION_RADIUS)
		&& !is_wall(player->data, x, player->y - COLLISION_RADIUS))
		player->x = x;
	y = player->y - sin(player->radiant) * SPEED;
	if (!is_wall(player->data, player->x, y + COLLISION_RADIUS)
		&& !is_wall(player->data, player->x, y - COLLISION_RADIUS)
		&& !is_wall(player->data, player->x + COLLISION_RADIUS, y)
		&& !is_wall(player->data, player->x - COLLISION_RADIUS, y))
		player->y = y;
}

void	turn(t_player	*player, int rl)
{
	if (rl == 1)
		player->radiant -= degree_to_radiant(10);
	else
		player->radiant += degree_to_radiant(10);
}

void	left_right(t_player	*player, int rl)
{
	double	x;
	double	y;

	if (rl == 1)
	{
		x = player->x - cos(player->radiant + M_PI / 2) * SPEED;
		y = player->y - sin(player->radiant + M_PI / 2) * SPEED;
	}
	else
	{
		x = player->x + cos(player->radiant + M_PI / 2) * SPEED;
		y = player->y + sin(player->radiant + M_PI / 2) * SPEED;
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
	if (player->w == 1)
		go_forward(player);
	if (player->s == 1)
		go_backward(player);
	if (player->left == 1)
		turn(player, 1);
	if (player->right == 1)
		turn(player, 2);
	if (player->a == 1)
		left_right(player, 1);
	if (player->d == 1)
		left_right(player, 0);
	return (0);
}
