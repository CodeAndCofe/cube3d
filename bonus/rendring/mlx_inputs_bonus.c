/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:44:42 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/20 13:43:28 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

int	free_text(t_player *player)
{
	int	i;

	i = 0;
	if (player->data->no_texture)
		mlx_destroy_image(player->mlx->mlx, player->data->no_texture);
	if (player->data->so_texture)
		mlx_destroy_image(player->mlx->mlx, player->data->so_texture);
	if (player->data->ea_texture)
		mlx_destroy_image(player->mlx->mlx, player->data->ea_texture);
	if (player->data->we_texture)
		mlx_destroy_image(player->mlx->mlx, player->data->we_texture);
	if (player->data->door_texture)
		mlx_destroy_image(player->mlx->mlx, player->data->door_texture);
	player->data->door_texture = NULL;
	player->data->we_texture = NULL;
	player->data->ea_texture = NULL;
	player->data->so_texture = NULL;
	player->data->no_texture = NULL;
	while (player->data->frames[i])
	{
		mlx_destroy_image(player->mlx->mlx, player->data->frames[i]);
		player->data->frames[i] = NULL;
		i++;
	}
	return (0);
}

void	exit_all(t_player *player, int f)
{
	if (f == 1)
		print_error();
	if (player->new_pixel->img)
		mlx_destroy_image(player->mlx->mlx, player->new_pixel->img);
	if (player->pixel->img)
		mlx_destroy_image(player->mlx->mlx, player->pixel->img);
	free_text(player);
	mlx_destroy_window(player->mlx->mlx, player->mlx->win_mlx);
	free_data(player->data);
	exit(f);
}

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
	else if (keycode == 53)
		exit_all(player, 0);
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

int	render(t_player *player)
{
	static int	frame_counter;

	mlx_clear_window(player->mlx->mlx, player->mlx->win_mlx);
	draw_map_bonus(player->pixel, player->mlx, player, player->new_pixel);
	frame_counter++;
	if (player->pixel->img)
	{
		mlx_destroy_image(player->mlx->mlx, player->pixel->img);
		player->pixel->img = NULL;
	}
	if (player->new_pixel->img)
	{
		mlx_destroy_image(player->mlx->mlx, player->new_pixel->img);
		player->new_pixel->img = NULL;
	}
	display_animation(player, &frame_counter);
	action(player);
	return (0);
}
