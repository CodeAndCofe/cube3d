/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:17:49 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/07 15:28:39 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void	go_forward(t_player *player)
{
	player->x += cos(player->degre) * 15;
	player->y += sin(player->degre) * 15;
	mlx_clear_window(player->mlx->mlx, player->mlx->win_mlx);
	draw_map(player->pixel, player->mlx, player);
}


void	go_backward(t_player *player)
{
	player->x -= cos(M_PI/player->degre) * 15;
	player->y -= sin(M_PI/player->degre) * 15;
	mlx_clear_window(player->mlx->mlx, player->mlx->win_mlx);
	draw_map(player->pixel, player->mlx, player);
}

void	turn(t_player	*player, int rl)
{
	if (rl == 1)
		player->degre -= degree_to_radiant(30);
	else
		player->degre += degree_to_radiant(30);
}

int	event_listener(int keycode, t_player *player)
{
	// printf("%d\n", keycode);
	if (keycode == 13)// forward
		go_forward(player);
	else if (keycode == 1)
		go_backward(player);
	else if (keycode == 0)
		turn(player, 1);
	else if (keycode == 2)
		turn(player, 2);
	return (0);
}