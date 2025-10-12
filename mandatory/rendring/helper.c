/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:46:35 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/11 10:24:34 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

double	reset_radiant(double	angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	where_is_facing(double angle, t_player *player)
{
	if (angle > 0 && angle < M_PI)
	{
		player->facing_down = 1;
		player->facing_up = -1;
	}
	else
	{
		player->facing_down = -1;
		player->facing_up = 1;
	}
	if (angle < 0.5 * M_PI || angle > 1.5 * M_PI)
	{
		player->facing_right = 1;
		player->facing_left = -1;
	}
	else
	{
		player->facing_right = -1;
		player->facing_left = 1;
	}
}

void	the_intersects_horizontal(double ray_angle, t_player *player)// find intersactx and intersacty in cordinate
{
	player->h_intery = floor(player->y) * OBJECT;
	if (player->facing_down == 1)
		player->h_intery += OBJECT;
	player->h_interx = (player->x * OBJECT) + (player->h_intery - player->y * OBJECT) / tan(ray_angle);
	player->h_ysteps = OBJECT * player->facing_down;
	player->h_xsteps = OBJECT / tan(ray_angle);
	if ((player->facing_left == 1 && player->h_xsteps > 0) ||
		(player->facing_right == 1 && player->h_xsteps < 0))
		player->h_xsteps *= -1;
}

void	the_intersects_vertical(double ray_angle, t_player *player)
{
	player->v_interx = floor(player->x) * OBJECT;
	if (player->facing_right == 1)
		player->v_interx += OBJECT;
	player->v_intery = (player->y * OBJECT) + (player->v_interx - player->x * OBJECT) * tan(ray_angle);
	player->v_xsteps = OBJECT;
	player->v_xsteps *= player->facing_right;
	player->v_ysteps = player->v_xsteps * tan(ray_angle);
	if (player->facing_up == 1 && player->v_ysteps > 0)
		player->v_ysteps *= -1;
	else if (player->facing_down == 1 && player->v_ysteps < 0)
		player->v_ysteps *= -1;
}

void	horizontal_ray(t_player *player, t_pixel *pixel)
{
	(void) pixel;
	double		horizontal_x;
	double		horizontal_y;

	horizontal_x = player->h_interx;
	horizontal_y = player->h_intery;
	player->h_wall = 0;
	if (player->facing_up == 1)
		horizontal_y -= 1;
	while (1)
	{
		if (the_limit(horizontal_x, horizontal_y) == 1
			|| cordinate_limit(horizontal_x / OBJECT, horizontal_y / OBJECT, player->data))
			return ;
		if (player->data->maps[(int)(horizontal_y / OBJECT)][(int)(horizontal_x / OBJECT)] == '1')
		{
			player->h_wall_hit_x = horizontal_x;
			player->h_wall_hit_y = horizontal_y;
			player->h_wall = 1;
			break;
		}
		horizontal_x += player->h_xsteps;
		horizontal_y += player->h_ysteps;
	}
}

void	vertical_ray(t_player *player, t_pixel *pixel)
{
	(void) pixel;
	double		vertical_x;
	double		vertical_y;

	vertical_x = player->v_interx;
	vertical_y = player->v_intery;
	player->v_wall = 0;
	if (player->facing_left == 1)
		vertical_x -= 1;
	while (1)
	{
		if (the_limit(vertical_x, vertical_y) == 1
			|| cordinate_limit((vertical_x / OBJECT), (vertical_y / OBJECT), player->data))
			return ;
		if (player->data->maps[(int)(vertical_y / OBJECT)][(int)((vertical_x) / OBJECT)] == '1')
		{
			player->v_wall_hit_x = vertical_x;
			player->v_wall_hit_y = vertical_y;
			player->v_wall = 1;
			break;
		}
		vertical_x += player->v_xsteps;
		vertical_y += player->v_ysteps;
	} 
}





// void check_the_small_distance(t_player *player)
// {
//     double h_distance = M_INT_MAX;
//     double v_distance = M_INT_MAX;

//     // Calculate distance to horizontal wall (if found)
//     if (player->h_wall == 1)
//         h_distance = calculate_distance(player->x * OBJECT, player->y * OBJECT, 
//                                        player->h_wall_hit_x, player->h_wall_hit_y);
    
//     // Calculate distance to vertical wall (if found)
//     if (player->v_wall == 1)
//         v_distance = calculate_distance(player->x * OBJECT, player->y * OBJECT, 
//                                        player->v_wall_hit_x, player->v_wall_hit_y);
    
//     // Choose the CLOSEST wall
//     if (h_distance < v_distance)
//     {
//         // Horizontal wall is closer
//         player->distance = h_distance;
//         player->hitx = player->h_wall_hit_x;
//         player->hity = player->h_wall_hit_y;
        
//         // Determine North or South
//         if (player->facing_up == 1)
//             player->wall_side = 0;  // North wall
//         else
//             player->wall_side = 1;  // South wall
        
//         // Hit point using X coordinate (horizontal wall uses X)
//         player->hit_point = fmod(player->hitx, OBJECT) / OBJECT;
//         if (player->hit_point < 0)
//             player->hit_point += 1.0;
//     }
//     else
//     {
//         // Vertical wall is closer
//         player->distance = v_distance;
//         player->hitx = player->v_wall_hit_x;
//         player->hity = player->v_wall_hit_y;
        
//         // Determine East or West
//         if (player->facing_right == 1)
//             player->wall_side = 2;  // East wall
//         else
//             player->wall_side = 3;  // West wall
        
//         // Hit point using Y coordinate (vertical wall uses Y)
//         player->hit_point = fmod(player->hity, OBJECT) / OBJECT;
//         if (player->hit_point < 0)
//             player->hit_point += 1.0;
//     }
// }