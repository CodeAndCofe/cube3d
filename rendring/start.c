/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:38:14 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/10 19:18:06 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void	mlx_action(t_player *player)
{
	mlx_hook(player->mlx->win_mlx, 2, 1L<<0, event_listener, player);
	mlx_hook(player->mlx->win_mlx, 3, 1L<<1, event_realise, player);
	mlx_loop_hook(player->mlx->mlx, render, player);
	mlx_hook(player->mlx->win_mlx, 6, 1L<<6 , mouse_move, player);
}

int start(t_data *data)
{
    t_pixel		pixel;
    t_player	player;
	t_mlx		new_mlx;

	player.data = data;
	player.pixel = &pixel;
	set_zero(&player);// seting player to zero
	find_player_position(&player);
	new_mlx.mlx = mlx_init();
	new_mlx.win_mlx = mlx_new_window(new_mlx.mlx, WIDTH, HEIGHT, "cub3d");
	player.mlx = &new_mlx;
	draw_map(&pixel, &new_mlx, &player);// draw map and player
	mlx_action(&player);
	mlx_loop(new_mlx.mlx);
    return (0);
}
