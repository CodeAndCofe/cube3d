/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:38:14 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/19 11:17:40 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

int	destroy(t_player *player)
{
	exit_all(player);
	return (0);
}

void	mlx_action(t_player *player)
{
	mlx_hook(player->mlx->win_mlx, 2, 1L<<0, event_listener, player);
	mlx_hook(player->mlx->win_mlx, 3, 1L<<1, event_realise, player);
	mlx_hook(player->mlx->win_mlx, 6, 1L<<6 , mouse_move, player);
	mlx_hook(player->mlx->win_mlx, 17, 0L, destroy, player);
	mlx_loop_hook(player->mlx->mlx, render, player);
}

int start(t_data *data)
{
    t_pixel		pixel;
    t_player	player;
	t_mlx		new_mlx;

	player.data = data;
	player.pixel = &pixel;
	set_zero(&player);
	find_player_position(&player);
	new_mlx.mlx = mlx_init();
	new_mlx.win_mlx = mlx_new_window(new_mlx.mlx, WIDTH, HEIGHT, "cub3d");
	player.mlx = &new_mlx;
	player.new_pixel.img = NULL;
	draw_map(&pixel, &new_mlx, &player, &player.new_pixel);
	mlx_action(&player);
	mlx_loop(new_mlx.mlx);
	exit_all(&player);
    return (0);
}
