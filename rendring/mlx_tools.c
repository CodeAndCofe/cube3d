/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:39:12 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/11 01:50:52 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

int	event_listener(int keycode, t_player *player)
{
	if (keycode == 13)// forward
		player->w = 1;
	else if (keycode == 1)
		player->s = 1;
	else if (keycode == 0)
		player->a = 1;
	else if (keycode == 2)
		player->d = 1;
	return (0);
}

int	event_realise(int keycode, t_player *player)
{
	if (keycode == 13)// forward
		player->w = 0;
	else if (keycode == 1)
		player->s = 0;
	else if (keycode == 0)
		player->a = 0;
	else if (keycode == 2)
		player->d = 0;
	return (0);
}

int    render(t_player *player)
{
	if (player->pixel->img)
		mlx_destroy_image(player->mlx->mlx, player->pixel->img);
	mlx_clear_window(player->mlx->mlx, player->mlx->win_mlx);
	draw_map(player->pixel, player->mlx, player);
    action(player);
    return (0);
}