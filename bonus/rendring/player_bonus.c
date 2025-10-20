/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:43:27 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:01 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

double	degree_to_radiant(double n)
{
	return (n * ((M_PI) / 180));
}

double	reset_radiant(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	set_zero(t_player *player)
{
	player->facing_down = 0;
	player->facing_up = 0;
	player->facing_right = 0;
	player->facing_left = 0;
	player->w = 0;
	player->d = 0;
	player->a = 0;
	player->s = 0;
	player->left = 0;
	player->right = 0;
	player->x = 0;
	player->y = 0;
	player->radiant = 0;
	player->h_wall_hit_x = 0;
	player->h_wall_hit_y = 0;
	player->pixel->img = NULL;
	player->new_pixel->img = NULL;
}

void	set_player_position_and_degree(t_player *player, char c, int j, int i)
{
	player->x = j + 0.5;
	player->y = i + 0.5;
	if (c == 'N')
		player->radiant = degree_to_radiant(270);
	else if (c == 'S')
		player->radiant = degree_to_radiant(180);
	else if (c == 'W')
		player->radiant = degree_to_radiant(90);
	else if (c == 'E')
		player->radiant = degree_to_radiant(0);
}

void	find_player_position(t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (player->data->maps[i])
	{
		j = 0;
		while (player->data->maps[i][j])
		{
			if (player->data->maps[i][j] == 'N'
			|| player->data->maps[i][j] == 'S'
			|| player->data->maps[i][j] == 'E'
			|| player->data->maps[i][j] == 'W')
			{
				set_player_position_and_degree(player,
					player->data->maps[i][j], j, i);
				return ;
			}
			j++;
		}
		i++;
	}
}
