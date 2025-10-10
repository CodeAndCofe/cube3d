/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:32:50 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/10 17:24:54 by zyahansa         ###   ########.fr       */
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

void draw_ceilling(double top, t_pixel* pixel, int x)
{
    int i;

    i = 0;
    while (i < (int)top)
    {
        my_mlx_pixel_put(pixel, x, i, 0x87CEEB);
        i++;
    }
}

void  draw_floor(double bottom, t_pixel *pixel, int x)
{
    int i;

    i = (int)bottom;
    while (i < HEIGHT)
    {
        my_mlx_pixel_put(pixel, x, i, G_COLOR);
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

// int get_pixel_color(char *addr, int x, int y, t_player *player)
// {
//     // DEBUG
//     static int count = 0;
//     if (count < 5)  // Print first 5 calls only
//     {
//         printf("addr=%p, x=%d, y=%d, tex_w=%d, tex_h=%d\n", 
//                addr, x, y, player->data->tex_with, player->data->tex_height);
//         count++;
//     }
    
//     if (x < 0 || x >= player->data->tex_with)
//     {
//         printf("ERROR: x=%d out of bounds (0-%d)\n", x, player->data->tex_with);
//         return (0x00FF00);  // GREEN for X error
//     }
//     if (!addr)
//     {
//         printf("ERROR: addr is NULL!\n");
//         return (0xFF0000);  // RED for NULL
//     }
//     if (y < 0 || y >= player->data->tex_height)
//     {
//         printf("ERROR: y=%d out of bounds (0-%d)\n", y, player->data->tex_height);
//         return (0x0000FF);  // BLUE for Y error
//     }
    
//     return get_texture_pixel(addr, x, y, player->data->tex_line_len, 
//                             player->data->tex_bpp, player->data->tex_with, 
//                             player->data->tex_height);
// }
// int get_pixel_color(char *addr, int x, int y, t_player *player)
// {
//     (void)addr;
//     (void)x;
//     (void)y;
    
//     // Return color based on wall_side
//     if (player->wall_side == 0) return 0xFF0000;  // Red
//     if (player->wall_side == 1) return 0x00FF00;  // Green
//     if (player->wall_side == 2) return 0x0000FF;  // Blue
//     if (player->wall_side == 3) return 0xFFFF00;  // Yellow
//     return 0xFFFFFF;
// }

