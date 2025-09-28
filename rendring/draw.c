/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:48:01 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/28 16:34:56 by aferryat         ###   ########.fr       */
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
			my_mlx_pixel_put(pixel , (player->x * OBJECT) + x , (player->y * OBJECT) + y , P_COLOR);
			x++;
		}
		y++;
	}
	return (0);
}


void draw_wall(double wall_height, int wall_side, t_pixel *pixel, int x, t_player *player, double hit_point)
{
    if (!pixel || !player || !player->data || x < 0 || x >= WIDTH)
        return ;

    double top;
    double bottom;
    char* tex_side;
    int i;
    int text_x;
    int color;
    double tex_step;
    double tex_pos;

    top = get_top(wall_height);
    bottom = get_bottom(wall_height);

    
    text_x = (int)(hit_point * player->data->tex_with);
    if (text_x >= player->data->tex_with)
        text_x = player->data->tex_with - 1;
    if (text_x < 0)
        text_x = 0;
    init_tex_side(&tex_side, wall_side, player);
    i = 0;
    while (i < (int)top)
    {
        my_mlx_pixel_put(pixel, x, i, 0x87CEEB);
        i++;
    }
    i = (int)top;
    tex_step = (double)player->data->tex_height / wall_height;
    tex_pos = (top - HIGTH / 2 + wall_height / 2) * tex_step;
        
    for (int i = top; i < bottom; i++)
    {
        int text_y = (int)tex_pos;
        if (text_y >= player->data->tex_height) text_y = player->data->tex_height - 1;
        if (text_y < 0) text_y = 0;
        
        color = get_texture_pixel(tex_side, text_x, text_y, 
                     player->data->tex_line_len,
                     player->data->tex_bpp,
                     player->data->tex_with,
                     player->data->tex_height);
        
        my_mlx_pixel_put(pixel, x, i, color);
        tex_pos += tex_step;
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
    double ray_x = player->x + 0.5;
    double ray_y = player->y + 0.5;
    double ray_cos = cos(ray_angle) * 0.005;
    double ray_sin = sin(ray_angle) * 0.005;
    double distance = 0;
    int wall_side = 0;
    double hit_point = 0.0; 
    
    while (1)
    {

        double old_ray_y = ray_y;

        ray_x += ray_cos;
        ray_y += ray_sin;
        distance += 0.005;

        if (player->data->maps[(int)ray_y][(int)ray_x] == '1')
        {
            if ((int)ray_y != (int)old_ray_y) 
            {
                if (ray_sin > 0) {
                    wall_side = 0;
                    hit_point = ray_x - (int)ray_x;
                } else {
                    wall_side = 1;
                    hit_point = ray_x - (int)ray_x;
                }
            }
            else 
            {
                if (ray_cos > 0) {
                    wall_side = 2;
                    hit_point = ray_y - (int)ray_y;
                } else {
                    wall_side = 3;
                    hit_point = ray_y - (int)ray_y;
                }
            }
            real_distance = distance * cos(player->radiant - ray_angle);
            WALL_HIEGTH = ppd / real_distance;
            draw_wall(WALL_HIEGTH, wall_side, pixel, i, player, hit_point);

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
    load_texture(player);
	// draw_player(pixel, player, OBJECT / 2);
	player_view(pixel, player);
	mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, pixel->img, 0, 0);
	return (0);
}
