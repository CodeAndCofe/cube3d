/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_inputs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:44:42 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/24 16:53:18 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

int	free_text(t_player *player)
{
	int	i;

	i = 0;
	if (player->data->no_texture)
		mlx_delete_texture(player->data->no_texture);
	if (player->data->so_texture)
		mlx_delete_texture(player->data->so_texture);
	if (player->data->ea_texture)
		mlx_delete_texture(player->data->ea_texture);
	if (player->data->we_texture)
		mlx_delete_texture(player->data->we_texture);
	if (player->data->door_texture)
		mlx_delete_texture(player->data->door_texture);
	if (player->data->sky_texture)
		mlx_delete_texture(player->data->sky_texture);
	if (player->data->ground_texture)
		mlx_delete_texture(player->data->ground_texture);
	if (player->data->wall_texture)
		mlx_delete_texture(player->data->wall_texture);
	if (player->data->goblin_texture)
		mlx_delete_texture(player->data->goblin_texture);
	if (player->data->mage_texture)
		mlx_delete_texture(player->data->mage_texture);
	if (player->data->coin_texture)
		mlx_delete_texture(player->data->coin_texture);
	if (player->data->fireball_texture)
		mlx_delete_texture(player->data->fireball_texture);
	player->data->door_texture = NULL;
	player->data->we_texture = NULL;
	player->data->ea_texture = NULL;
	player->data->so_texture = NULL;
	player->data->no_texture = NULL;
	player->data->sky_texture = NULL;
	player->data->ground_texture = NULL;
	player->data->wall_texture = NULL;
	player->data->goblin_texture = NULL;
	player->data->mage_texture = NULL;
	player->data->coin_texture = NULL;
	player->data->fireball_texture = NULL;
	while (player->data->frames[i])
	{
		mlx_delete_image(player->mlx->mlx, player->data->frames[i]);
		player->data->frames[i] = NULL;
		i++;
	}
	return (0);
}

void	exit_all(t_player *player, int f)
{
	if (f == 1)
		print_error();
	player->data->close_requested = 1;
	mlx_close_window(player->mlx->mlx);
}

static void	key_pressed(keys_t keycode, t_player *player)
{
	if (keycode == MLX_KEY_W)
		player->w = 1;
	else if (keycode == MLX_KEY_S)
		player->s = 1;
	else if (keycode == MLX_KEY_A)
		player->a = 1;
	else if (keycode == MLX_KEY_D)
		player->d = 1;
	else if (keycode == MLX_KEY_LEFT)
		player->left = 1;
	else if (keycode == MLX_KEY_RIGHT)
		player->right = 1;
	else if (keycode == MLX_KEY_ESCAPE)
		exit_all(player, 0);
	else if (keycode == MLX_KEY_SPACE)
		gameplay_fire(player);
}

static void	key_released(keys_t keycode, t_player *player)
{
	if (keycode == MLX_KEY_W)
		player->w = 0;
	else if (keycode == MLX_KEY_S)
		player->s = 0;
	else if (keycode == MLX_KEY_A)
		player->a = 0;
	else if (keycode == MLX_KEY_D)
		player->d = 0;
	else if (keycode == MLX_KEY_LEFT)
		player->left = 0;
	else if (keycode == MLX_KEY_RIGHT)
		player->right = 0;
	else if (keycode == MLX_KEY_SPACE)
		open_door(keycode, player);
}

void	event(mlx_key_data_t keydata, void *param)
{
	t_player	*player;

	player = (t_player *)param;
	player->needs_render = 1;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		key_pressed(keydata.key, player);
	else if (keydata.action == MLX_RELEASE)
		key_released(keydata.key, player);
}

void	render(t_player *player)
{
	static int	frame_counter;
	int		moving;

	if (mlx_is_key_down(player->mlx->mlx, MLX_KEY_ESCAPE))
		exit_all(player, 0);
	moving = action(player);
	gameplay_update(player);
	if (player->data->goblin_alive || player->data->projectile_active
		|| player->data->enemy_projectile_active)
		player->needs_render = 1;
	if (!moving && !player->needs_render && !player->data->start_animation)
		return ;
	draw_map_bonus(player->pixel, player->mlx, player, player->new_pixel);
	frame_counter++;
	display_animation(player, &frame_counter);
	player->needs_render = 0;
}
