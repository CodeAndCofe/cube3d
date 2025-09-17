/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:48:01 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/17 13:54:55 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

int	draw_player(t_pixel *pixel, t_player *player, int size)
{
	int x = 0;
	int y = 0;
	
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			my_mlx_pixel_put(pixel , (player->x * OBJECT) + x, (player->y * OBJECT) + y, P_COLOR);
			x++;
		}
		y++;
	}
	return (0);
}


void	draw_wall(t_pixel *pixel, double WALL_HIEGTH, int x)
{
	double top =  (HIGTH / 2) - (WALL_HIEGTH / 2);
	double bottom =  (HIGTH / 2) + (WALL_HIEGTH / 2);
	if (top < 0) top = 0;
	if (bottom >= HIGTH) bottom = HIGTH - 1;	
	while (top < bottom)
	{		
		// int wall_y = top / WALL_HIEGTH * tex_height;
		// int wall_x = point_of_intersection * tex_width;
		my_mlx_pixel_put(pixel, x, top, P_COLOR);
		top ++;
	}	
	while (bottom < HIGTH)
	{		
		// int wall_y = top / WALL_HIEGTH * tex_height;
		// int wall_x = point_of_intersection * tex_width;
		my_mlx_pixel_put(pixel, x, bottom, G_COLOR);
		bottom ++;
	}	
}


int draw_line(t_pixel *pixel, t_player *player, double ray_angle, int i)
{
	double ppd = (WIDTH / 2) / fabs(tan(degree_to_radiant(VIEW / 2)));
	double	real_distance;
	double	WALL_HIEGTH;
	double ray_x = player->x;
	double ray_y  = player->y;
	double ray_cos = cos(ray_angle) * 0.005;
	double ray_sin = sin(ray_angle) * 0.005;
	double distance = 0;
	
	while (1)
	{
		ray_x += ray_cos;
		ray_y += ray_sin;
		distance += 0.005;
		if (player->data->maps[(int)ray_y][(int)ray_x] == '1')
		{
			real_distance = distance * cos(player->radiant - ray_angle);
			WALL_HIEGTH = ppd / real_distance;
			draw_wall(pixel, WALL_HIEGTH, i);
			break;
		}
	}
	
	return (0);
}

void    player_view(t_pixel *pixel, t_player *player)
{
	int i;
	double  ray_angle;

	i = 0;
	ray_angle = player->radiant - degree_to_radiant(VIEW / 2);
	while (i < WIDTH)
	{
		draw_line(pixel, player, ray_angle, i);
		ray_angle += degree_to_radiant(VIEW / WIDTH);
		i++;
	}
}


int	draw_map(t_pixel *pixel, t_mlx *new_mlx, t_player *player)
{
	// int	i = 0;
	// int	j = 0;
	pixel->img = mlx_new_image(new_mlx->mlx, WIDTH, HIGTH);
	pixel->addr = mlx_get_data_addr(pixel->img, &pixel->bits_per_pixel, &pixel->line_length, &pixel->endian);
	// while (player->data->maps[i])
	// {
	// 	j = 0;
	// 	while (player->data->maps[i][j])
	// 	{
	// 		draw_square(pixel, i, j, G_COLOR, OBJECT);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// draw_player(pixel, player, OBJECT / 2);
	player_view(pixel, player);
	mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, pixel->img, 0, 0);
	return (0);
}