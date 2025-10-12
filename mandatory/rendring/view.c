/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:26:12 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/11 11:18:08 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

// i need to check that:
double	calculate_distance(double px, double py, double dx, double dy)
{
	return (sqrt((dx - px) * (dx - px) + (dy - py) * (dy - py)));
}

void check_the_small_distance(t_player *player)
{
    double h_distance = M_INT_MAX;
    double v_distance = M_INT_MAX;

    if (player->h_wall == 1)
        h_distance = calculate_distance(player->x * OBJECT, player->y * OBJECT, player->h_wall_hit_x, player->h_wall_hit_y);
    if (player->v_wall == 1)
        v_distance = calculate_distance(player->x * OBJECT, player->y * OBJECT, player->v_wall_hit_x, player->v_wall_hit_y);
    if (h_distance < v_distance)
    {
        player->distance = h_distance;
        player->hitx = player->h_wall_hit_x;
        player->hity = player->h_wall_hit_y;
        if (player->facing_up == 1)
            player->wall_side = 0;//no
        else
            player->wall_side = 1;//daha so
		player->hit_point = fmod(player->hitx, OBJECT) / OBJECT;
    }
    else
    {
        player->distance = v_distance;
        player->hitx = player->v_wall_hit_x;
        player->hity = player->v_wall_hit_y;
        if (player->facing_right == 1)
            player->wall_side = 2;//ea
        else
            player->wall_side = 3;//we
		player->hit_point = fmod(player->hity, OBJECT) / OBJECT;
    }
}

void	draw_ray(t_pixel *pixel, int ray_x, int ray_y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			my_mlx_pixel_put(pixel, ray_x + j, ray_y + i, color);
			j++;
		}
		i++;
	}
} 


void	draw_line(t_pixel *pixel, t_player *player, double ray_angle, int i)
{
	
	ray_angle = reset_radiant(ray_angle);
	where_is_facing(ray_angle, player);
	the_intersects_horizontal(ray_angle, player);
	horizontal_ray(player, pixel);// add door
	the_intersects_vertical(ray_angle, player);
	vertical_ray(player, pixel);// add door
	// check_the_small_distance(player, ray_angle);
	check_the_small_distance(player);

	drawing_wall(player, pixel, i, ray_angle);
	return ;
}

void	player_view(t_pixel *pixel, t_player *player)
{
	int	i;
	double	ray_angle;

	i = 0;
	ray_angle = player->radiant - degree_to_radiant(VIEW / 2);
	while (i < WIDTH)
	{

		draw_line(pixel, player, ray_angle, i);
		ray_angle += degree_to_radiant(VIEW) / WIDTH;
		i++;
	}
}
