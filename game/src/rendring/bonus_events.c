/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_events_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:17:33 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/25 20:50:59 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

void	mouse_move(double x, double y, void *param)
{
	t_player	*player;
	double		degree;

	if (x <= 0 || x >= WIDTH - 1 || y <= 0 || y >= HEIGHT - 1)
		return ;
	player = (t_player *) param;
	player->mouse_x = x;
	player->mouse_y = y;
	degree = ((x * 360) / (WIDTH));
	player->radiant = degree_to_radiant((degree));
	player->radiant = reset_radiant(player->radiant);
	player->needs_render = 1;
}

static void	open_door_helper(double x_pos, double y_pos, t_player *player)
{
	if ((int)y_pos >= 0 && (int)y_pos < player->data->map_lines
		&& (int)x_pos >= 0
		&& (int)x_pos < (int)ft_strlen(player->data->maps[(int)y_pos]))
	{
		if (player->data->maps[(int)y_pos][(int)x_pos] == 'D')
			player->data->maps[(int)y_pos][(int)x_pos] = 'd';
		else if (player->data->maps[(int)y_pos][(int)x_pos] == 'd')
			player->data->maps[(int)y_pos][(int)x_pos] = 'D';
	}
}

void	animation_click(mouse_key_t button, action_t action,
		modifier_key_t mods, void *param)
{
	t_player	*player;

	(void)mods;
	player = (t_player *)param;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		player->data->start_animation = 1;
		player->needs_render = 1;
	}
}

int	open_door(int keycode, void *param)
{
	double		x_pos;
	double		y_pos;
	double		check_dis;
	double		angle;
	t_player	*player;

	player = (t_player *)param;
	check_dis = 1.5;
	angle = -0.5;
	if (keycode == MLX_KEY_SPACE)
	{
		while (angle <= 0.5)
		{
			x_pos = player->x + cos(player->radiant + angle) * check_dis;
			y_pos = player->y + sin(player->radiant + angle) * check_dis;
			open_door_helper(x_pos, y_pos, player);
			angle += 0.5;
		}
	}
	return (0);
}
