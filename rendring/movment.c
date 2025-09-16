/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:42:04 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/15 13:39:55 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void	go_forward(t_player *player)
{
	double x =  player->x + cos(player->radiant) * SPEED;
	double y = player->y + sin(player->radiant) * SPEED;
	if (player->data->maps[(int)y][(int)x] == '1')
		return ;
	player->x = x;
	player->y = y;
}


void	go_backward(t_player *player)
{
	double x = player->x - cos(player->radiant) * SPEED;
	double y = player->y - sin(player->radiant) * SPEED;
	if (player->data->maps[(int)y][(int)x] == '1')
		return ;
	player->x = x;
	player->y = y;
}

void	turn(t_player	*player, int rl)
{
	if (rl == 1)
		player->radiant -= degree_to_radiant(3);
	else
		player->radiant += degree_to_radiant(3);
}

int	action(t_player *player)
{
	if (player->w == 1)
		go_forward(player);
	else if (player->s == 1)
		go_backward(player);
	else if (player->a == 1)
		turn(player, 1);
	else if (player->d == 1)
		turn(player, 2);
	return (0);
}