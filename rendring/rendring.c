/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:34:50 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/10 12:21:18 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"


int mlx_actions(t_player *player)
{
	mlx_hook(player->mlx->win_mlx, 2, 1L<<0, event_listener, player);
	mlx_hook(player->mlx->win_mlx, 3, 1L<<1, event_realise, player);
	mlx_loop_hook(player->mlx->mlx, render, player);
	return (0);
}

int    start(t_data *data)
{
	t_player    player;
	t_mlx       new_mlx;

	player.data = data;
	set_zero (&player);
	find_player_position(&player);
	new_mlx.mlx = mlx_init();
	new_mlx.win_mlx = mlx_new_window(new_mlx.mlx, 1920, 1080, "CUB3d");
	player.mlx = &new_mlx;
	draw_map(&new_mlx, &player);
	mlx_actions(&player);
	mlx_loop(new_mlx.mlx);
	return (0);
}
