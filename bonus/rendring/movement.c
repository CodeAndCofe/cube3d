/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:02:01 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/12 15:53:54 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"


int	event(int keycode, t_player *player)
{
	event_listener(keycode, player);
	// open_door(keycode, player);
	return (0);
}

int open_door(int keycode, void *param)
{
	double x_pos;
	double y_pos;
	double check_dis = 1.5;
	t_player *player = (t_player *)param;
	double angle;
	
	angle = -0.5;
	if (keycode == 49)
	{
		while (angle <= 0.5)
		{	
			x_pos = player->x + cos(player->radiant + angle) * check_dis;
			y_pos = player->y + sin(player->radiant + angle) * check_dis;
			if ((int)player->x == (int)x_pos && (int)player->y == (int)y_pos)
			{
				angle += 0.1;
				continue;
			} 
			if (((int)x_pos >= 0 && x_pos < (int)ft_strlen(player->data->maps[(int)y_pos])) && 
				((int)y_pos >= 0 && y_pos < player->data->map_lines))
			{
				if (player->data->maps[(int)y_pos][(int)x_pos] == 'D')//
					player->data->maps[(int)y_pos][(int)x_pos] = 'd';//	
				else if (player->data->maps[(int)y_pos][(int)x_pos] == 'd')//
					player->data->maps[(int)y_pos][(int)x_pos] = 'D';//
			}
			angle += 0.1;
		}
	}
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_player *player = (t_player *)param;
	(void)y;
	double degree;

	degree = ((x * 360) / (WIDTH));
	// player->radiant = degree_to_radiant(stay_inside(degree));
	player->radiant = degree_to_radiant((degree));
	player->radiant = reset_radiant(player->radiant);

	return (0);
}

void	go_forward(t_player *player)
{
	double x;
	double y;

	x =  player->x + cos(player->radiant) * SPEED;
	y = player->y + sin(player->radiant) * SPEED;
	if (player->data->maps[(int)y][(int)x] == '1' ||
		player->data->maps[(int)y][(int)x] == 'D' )
		return ;
	player->x = x;
	player->y = y;
	
}
void	go_backward(t_player *player)
{
	double x;
	double y;

	x =  player->x - cos(player->radiant) * SPEED;
	y = player->y - sin(player->radiant) * SPEED;
	if (player->data->maps[(int)y][(int)x] == '1' ||
		player->data->maps[(int)y][(int)x] == 'D' )
		return ;
	player->x = x;
	player->y = y;
}

void	turn(t_player	*player, int rl)
{
	if (rl == 1)
		player->radiant -= degree_to_radiant(10);
	else
		player->radiant += degree_to_radiant(10);
}

void	left_right(t_player	*player, int rl)
{
	double x;
	double y;

	if (rl == 1)
	{
		x = player->x - cos(player->radiant + M_PI / 2)  * SPEED;
		y = player->y - sin(player->radiant + M_PI / 2 )  * SPEED;
	}
	else
	{
		x = player->x + cos(player->radiant + M_PI / 2) * SPEED;
		y = player->y + sin(player->radiant + M_PI / 2) * SPEED;
	}
	if (player->data->maps[(int)y][(int)x] == '1' || 
		player->data->maps[(int)y][(int)x] == 'D')
		return ;
	player->x = x;
	player->y = y;
}

int	action(t_player *player)
{
	if (player->w == 1)
		go_forward(player);
	else if (player->s == 1)
		go_backward(player);
	else if (player->left == 1)
		turn(player, 1);
	else if (player->right == 1)
		turn(player, 2);
	else if (player->a == 1)
		left_right(player, 1);
	else if (player->d == 1)
		left_right(player, 0);
	return (0);
}
