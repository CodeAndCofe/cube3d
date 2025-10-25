/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_events_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:17:33 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/25 22:19:36 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

int	event(int keycode, t_player *player)
{
	event_listener(keycode, player);
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_player	*player;
	double		degree;

	player = (t_player *) param;
	degree = ((x * 360) / (WIDTH));
	player->radiant = degree_to_radiant((degree));
	player->radiant = reset_radiant(player->radiant);
	return (0);
}

static void	open_door_helper(double x_pos, double y_pos, t_player *player)
{
	if (((int)x_pos >= 0
			&& x_pos < (int)ft_strlen(player->data->maps[(int)y_pos]))
		&& ((int)y_pos >= 0 && y_pos < player->data->map_lines))
	{
		if (player->data->maps[(int)y_pos][(int)x_pos] == 'D')
			player->data->maps[(int)y_pos][(int)x_pos] = 'd';
		else if (player->data->maps[(int)y_pos][(int)x_pos] == 'd')
			player->data->maps[(int)y_pos][(int)x_pos] = 'D';
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
	if (keycode == 49)
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
