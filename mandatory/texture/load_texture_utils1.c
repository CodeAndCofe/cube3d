/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:32:50 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/12 15:56:54 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"


int get_text_y(int text_y, double text_pos, t_player *player)
{
    text_y = (int)text_pos;
    if (text_y >= player->data->tex_height)
        text_y = player->data->tex_height - 1;
    if (text_y < 0)
        text_y = 0;
    return text_y;
}

int get_text_x(t_player *player, double hit_point)
{
    int text_x; 
    text_x = (int)(hit_point *player->data->tex_with);
    if(text_x >= player->data->tex_with)
        text_x = player->data->tex_with - 1;
    if(text_x <= 0)
        text_x = 0;
    return (text_x);
}

void draw_ceilling(double top, t_pixel* pixel, int x, t_player *player)
{
    int i;

    i = 0;
    while (i < (int)top)
    {
        my_mlx_pixel_put(pixel, x, i, player->data->c_color);
        i++;
    }
}

void  draw_floor(double bottom, t_pixel *pixel, int x, t_player *player)
{
    int i;

    i = (int)bottom;
    while (i < HEIGHT)
    {
        my_mlx_pixel_put(pixel, x, i, player->data->c_color);
        i++;
    }
}

int get_pixel_color(char *text_side, int text_x, int text_y, t_player *player)
{
    int color;

    color = get_texture_pixel(text_side, text_x, text_y,
            player->data->tex_line_len,
            player->data->tex_bpp);

    return (color);
}
