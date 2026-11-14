/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:38:14 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/24 16:55:25 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

void	destroy(void *param)
{
	exit_all((t_player *)param, 0);
}

void	mlx_action(t_player *player)
{
	mlx_key_hook(player->mlx->mlx, event, player);
	mlx_cursor_hook(player->mlx->mlx, mouse_move, player);
	mlx_close_hook(player->mlx->mlx, destroy, player);
	mlx_mouse_hook(player->mlx->mlx, animation_click, player);
	mlx_loop_hook(player->mlx->mlx, (void (*)(void *))render, player);
}

int	start(t_data *data)
{
	t_pixel		pixel;
	t_player	player;
	t_mlx		new_mlx;
	t_pixel		new_pixel;

	player.data = data;
	new_pixel.img = NULL;
	pixel.img = NULL;
	player.pixel = &pixel;
	player.new_pixel = &new_pixel;
	set_zero(&player);
	find_player_position(&player);
	gameplay_init(&player);
	new_mlx.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!new_mlx.mlx)
		return (free_data(data), print_error());
	player.mlx = &new_mlx;
	draw_map_bonus(&pixel, &new_mlx, &player, &new_pixel);
	mlx_action(&player);
	mlx_loop(new_mlx.mlx);
	if (player.pixel->img)
		mlx_delete_image(new_mlx.mlx, player.pixel->img);
	if (player.new_pixel->img)
		mlx_delete_image(new_mlx.mlx, player.new_pixel->img);
	free_text(&player);
	mlx_terminate(new_mlx.mlx);
	if (data->restart_requested)
		return (2);
	return (data->level_complete);
}
