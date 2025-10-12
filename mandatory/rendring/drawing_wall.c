/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:05:59 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/11 11:23:03 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"



static void draw_wall(double wall_height, int wall_side, t_pixel *pixel, int x, t_player *player)
{
    if (!pixel || !player || !player->data || x < 0 || x >= WIDTH)
        return ;

    double top;
    double bottom;
    int i;
    char *text_side;
    int text_x;
    int text_y;
    int color;
    double tex_step;
    double tex_pos;

    top = get_top(wall_height);
    bottom = get_bottom(wall_height);
    text_x = get_text_x(player, player->hit_point);//possition x dyal text
    init_tex_side(&text_side, wall_side, player);// kan init wxmn side wall img khasni njib 
    tex_step = (double)player->data->tex_height / wall_height;//xhal mn pixel f wall l kola pixel f text 
    tex_pos = (top - HEIGHT / 2 + wall_height / 2) * tex_step;//possiton y dyal text
    i = top;
    while (i < bottom)
    {
        text_y = get_text_y(text_y, tex_pos, player);
        color = get_pixel_color(text_side, text_x, text_y, player);
        my_mlx_pixel_put(pixel, x, i,color);
        tex_pos += tex_step;
        i++;
    }
    draw_ceilling(top, pixel, x, player);//
    draw_floor(bottom, pixel, x, player);
}



void	drawing_wall(t_player *player, t_pixel *pixel, int i, double ray_angle)
{
    double  correct_distance = player->distance * cos(ray_angle - player->radiant);
	double	projectplane_distnace  = (WIDTH / 2) / tan(degree_to_radiant(VIEW / 2));// project plane distance its (opssite / tan (a) == adjacent)
	double	wall_hieght = ((double)OBJECT / correct_distance) * projectplane_distnace;// wall hight in project plane view
	draw_wall(wall_hieght, player->wall_side, pixel, i, player);

}
