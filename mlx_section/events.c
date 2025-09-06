/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:17:49 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/06 15:53:43 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void	go_forward(t_player *player)
{
	if (player->y - 1 == '1' || player->y - 1 == 0)
		return ;
	player->y -= 1;
	player->data->maps[player->y][player->x] = 'N';
	mlx_clear_window(player->mlx->mlx, player->mlx->win_mlx);
	draw_map(player->pixel, player->mlx, player);
}


void	go_backward(t_player *player)
{
	if (player->y - 1 == '1')
		return ;
	player->y += 1;
	player->data->maps[player->y][player->x] = 'N';
	mlx_clear_window(player->mlx->mlx, player->mlx->win_mlx);
	draw_map(player->pixel, player->mlx, player);
}

int	event_listener(int keycode, t_player *player)
{
	printf("%d\n", keycode);
	if (keycode == 13)// forward
		go_forward(player);
	else if (keycode == 1)
		go_backward(player);
	return (0);
}