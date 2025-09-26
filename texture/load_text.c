/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:01:48 by zyahansa          #+#    #+#             */
/*   Updated: 2025/09/26 18:15:21 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"


int load_texture(t_player *player)
{
    player->data->no_texture = mlx_xpm_file_to_image(player->mlx->mlx, 
    player->data->no_path, &player->data->tex_with, &player->data->tex_with);
    player->data->so_texture = mlx_xpm_file_to_image(player->mlx->mlx, 
    player->data->so_path, &player->data->tex_with, &player->data->tex_with);
    player->data->we_texture = mlx_xpm_file_to_image(player->mlx->mlx, 
    player->data->we_path, &player->data->tex_with, &player->data->tex_with);
    player->data->ea_texture = mlx_xpm_file_to_image(player->mlx->mlx, 
    player->data->ea_path, &player->data->tex_with, &player->data->tex_with);
    if (!player->data->no_texture || !player->data->so_texture || 
        !player->data->we_texture || !player->data->ea_texture)
            return (1);
    player->data->no_address = mlx_get_data_addr(player->data->no_texture,
    &player->pixel->bits_per_pixel, &player->pixel->line_length, &player->pixel->endian);
    player->data->so_address = mlx_get_data_addr(player->data->so_texture, 
    &player->pixel->bits_per_pixel, &player->pixel->line_length, &player->pixel->endian);
    player->data->we_address = mlx_get_data_addr(player->data->we_texture, 
    &player->pixel->bits_per_pixel, &player->pixel->line_length, &player->pixel->endian);
    player->data->ea_address = mlx_get_data_addr(player->data->ea_address, 
    &player->pixel->bits_per_pixel, &player->pixel->line_length, &player->pixel->endian);
    if (!player->data->no_address || !player->data->so_address ||
        !player->data->we_address || !player->data->ea_address)
            return (1);
    return (0);
}

void init_tex_side(int *tex_side, int wall_side, t_pixel *pixel)
{
    (void)pixel;
    if (wall_side == 0)
        *tex_side = 0xFF0000;
        
    else if (wall_side == 1)
        *tex_side = 0x409F00;

    else if (wall_side == 2)
        *tex_side =0x08707F;
        
    else if (wall_side == 3)
        *tex_side = 0xFFFF00;
    else
        *tex_side = 0xFFFFFF;
        
}

double get_top(double wall_height)
{
    double top;

    top = (HIGTH / 2) - (wall_height / 2);
    if(top < 0)
        top = 0;
    return (top);
}

double get_bottom(double wall_height)
{
    double bottom;

    bottom = (HIGTH / 2) + (wall_height / 2);
    if (bottom >= HIGTH)
        bottom = HIGTH - 1;
    return (bottom);
}