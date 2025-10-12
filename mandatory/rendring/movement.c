/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:02:01 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/11 12:03:18 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void	go_forward(t_player *player)
{
	double x;
	double y;

	y = player->y;
	x = (player->x + cos(player->radiant) * SPEED);
	if (!(player->data->maps[(int)(y)][(int)x] == '1'))
		player->x = x;
	y = (player->y + sin(player->radiant) * SPEED);
	if (!(player->data->maps[(int)(y)][(int)x] == '1'))
		player->y = y;
}


void	go_backward(t_player *player)
{
	double x;
	double y;

	y = player->y;
	x = player->x - cos(player->radiant) * SPEED;
	if (!(player->data->maps[(int)(y)][(int)x] == '1'))
		player->x = x;
	y = player->y - sin(player->radiant) * SPEED;
	if (!(player->data->maps[(int)(y)][(int)x] == '1'))
		player->y = y;
	
	
}

void	turn(t_player	*player, int rl)
{
	if (rl == 1)
		player->radiant -= degree_to_radiant(3);
	else
		player->radiant += degree_to_radiant(3);
}

void	left_right(t_player	*player, int rl)
{
	double x;
	double y;

	if (rl == 1)
	{
		x = player->x - cos(player->radiant + M_PI / 2)  * SPEED;
		y = player->y - sin(player->radiant + M_PI / 2 )  * SPEED;
	}
	else
	{
		x = player->x + cos(player->radiant + M_PI / 2) * SPEED;
		y = player->y + sin(player->radiant + M_PI / 2) * SPEED;
	}
	if (player->data->maps[(int)y][(int)x] == '1')
		return ;
	player->x = x;
	player->y = y;
}

int	action(t_player *player)
{
	if (player->w == 1)
		go_forward(player);
	else if (player->s == 1)
		go_backward(player);
	else if (player->left == 1)
		turn(player, 1);
	else if (player->right == 1)
		turn(player, 2);
	else if (player->a == 1)
		left_right(player, 1);
	else if (player->d == 1)
		left_right(player, 0);
	return (0);
}