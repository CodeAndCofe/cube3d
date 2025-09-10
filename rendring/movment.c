/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:42:04 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/09 22:38:10 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void	go_forward(t_player *player)
{
	player->x += cos(player->degre) * 10;
	player->y += sin(player->degre) * 10;
}


void	go_backward(t_player *player)
{
	player->x -= cos(player->degre) * 10;
	player->y -= sin(player->degre) * 10;
}

void	turn(t_player	*player, int rl)
{
	if (rl == 1)
		player->degre -= degree_to_radiant(1);
	else
		player->degre += degree_to_radiant(1);
}

int	action(t_player *player)
{
	if (player->w == 1)// forward
		go_forward(player);
	else if (player->s == 1)
		go_backward(player);
	else if (player->a == 1)
		turn(player, 1);
	else if (player->d == 1)
		turn(player, 2);
	return (0);
}