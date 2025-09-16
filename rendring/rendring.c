/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:34:50 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/16 14:48:55 by aferryat         ###   ########.fr       */
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
	t_pixel		*pixel;
	t_player    player;
	t_mlx       new_mlx;

	pixel = malloc (sizeof (t_pixel));
	if (pixel == NULL)
		return (-1);
	player.data = data;
	set_zero (&player);
	find_player_position(&player);
	new_mlx.mlx = mlx_init();
	new_mlx.win_mlx = mlx_new_window(new_mlx.mlx, WIDTH, HIGTH, "CUB3d");
	player.mlx = &new_mlx;
	draw_map(pixel, &new_mlx, &player);
	player.pixel = pixel;
	mlx_actions(&player);
	mlx_loop(new_mlx.mlx);
	pixels_free(pixel, &new_mlx);
	return (0);
}
