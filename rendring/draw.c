/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:48:01 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/26 18:37:14 by zyahansa         ###   ########.fr       */
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




void draw_wall(double wall_height, int wall_side, t_pixel *pixel, int x)
{
    double top;
    double bottom;
    int tex_side;
    int i;

    top = get_top(wall_height);
    bottom = get_bottom(wall_height);
    init_tex_side(&tex_side, wall_side, pixel);
    i = (int)top;
    while (i < (int)bottom)
    {
        my_mlx_pixel_put(pixel, x, i, tex_side);   
        i++;
    }
    i = 0;
    while (i < (int)top)
    {
        my_mlx_pixel_put(pixel, x, i, 0x87CEEB);
        i++;
    }
    i = (int)bottom;
    while (i < HIGTH)
    {
        my_mlx_pixel_put(pixel, x, i, G_COLOR);
        i++;
    }
}

int draw_line(t_pixel *pixel, t_player *player, double ray_angle, int i)
{



	
    double ppd = (WIDTH / 2) / fabs(tan(degree_to_radiant(VIEW / 2)));
    double real_distance;
    double WALL_HIEGTH;
    double ray_x = player->x;
    double ray_y = player->y;
    double ray_cos = cos(ray_angle) * 0.005;
    double ray_sin = sin(ray_angle) * 0.005;
    double distance = 0;
    
    // NEW - Variables for wall side detection
    int wall_side = 0;        // 0=North, 1=South, 2=West, 3=East
    double hit_point = 0.0;   // Where exactly ray hit wall (0.0-1.0)
    
    while (1)
    {
        // Store previous position before moving ray
        // double old_ray_x = ray_x;
        double old_ray_y = ray_y;
        
        // Move ray
        ray_x += ray_cos;
        ray_y += ray_sin;
        distance += 0.005;
        
        // Check if ray hit wall
        if (player->data->maps[(int)ray_y][(int)ray_x] == '1')
        {
            // WALL SIDE DETECTION LOGIC:
            
            if ((int)ray_y != (int)old_ray_y) 
            {
                // Y coordinate changed = Hit horizontal wall (North or South)
                
                if (ray_sin > 0) {
                    // Ray moving down = Hit North side of wall
                    wall_side = 0;  // North wall
                    hit_point = ray_x - (int)ray_x;  // X position on wall
                } else {
                    // Ray moving up = Hit South side of wall  
                    wall_side = 1;  // South wall
                    hit_point = ray_x - (int)ray_x;  // X position on wall
                }
            }
            else 
            {
                // X coordinate changed = Hit vertical wall (East or West)
                
                if (ray_cos > 0) {
                    // Ray moving right = Hit West side of wall
                    wall_side = 2;  // West wall
                    hit_point = ray_y - (int)ray_y;  // Y position on wall
                } else {
                    // Ray moving left = Hit East side of wall
                    wall_side = 3;  // East wall  
                    hit_point = ray_y - (int)ray_y;  // Y position on wall
                }
            }
            
            // Calculate wall height
            real_distance = distance * cos(player->radiant - ray_angle);
            WALL_HIEGTH = ppd / real_distance;
            
            // Draw wall with side information
            draw_wall(WALL_HIEGTH, wall_side, pixel, i);



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
	draw_player(pixel, player, OBJECT / 2);
	player_view(pixel, player);
	mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, pixel->img, 0, 0);
	return (0);
}
