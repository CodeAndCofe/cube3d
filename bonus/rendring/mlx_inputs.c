/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:44:42 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/18 10:43:40 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

int	event_listener(int keycode, t_player *player)
{
	if (keycode == 13)
		player->w = 1;
	else if (keycode == 1)
		player->s = 1;
	else if (keycode == 0)
		player->a = 1;
	else if (keycode == 2)
		player->d = 1;
	else if (keycode == 123)
		player->left = 1;
	else if (keycode == 124)
		player->right = 1;
	return (0);
}

int	event_realise(int keycode, t_player *player)
{
	if (keycode == 13)
		player->w = 0;
	else if (keycode == 1)
		player->s = 0;
	else if (keycode == 0)
		player->a = 0;
	else if (keycode == 2)
		player->d = 0;
	else if (keycode == 123)
		player->left = 0;
	else if (keycode == 124)
		player->right = 0;
	else if (keycode == 49)
		open_door(keycode, player);
	return (0);
}

int    render(t_player *player)
{
	static int frame_counter;
	if (player->pixel->img)
		mlx_destroy_image(player->mlx->mlx, player->pixel->img);
	mlx_clear_window(player->mlx->mlx, player->mlx->win_mlx);
	draw_map(player->pixel, player->mlx, player);
	frame_counter++;
	// display_animation(player, &frame_counter);
    action(player);
    return (0);
}