/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:01:48 by zyahansa          #+#    #+#             */
/*   Updated: 2025/09/28 13:33:26 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

int load_texture(t_player *player)
{
    if (!player || !player->data || !player->mlx || !player->mlx->mlx)
        return 1;

    player->data->no_texture = mlx_xpm_file_to_image(player->mlx->mlx, 
    player->data->no_path, &player->data->tex_with, &player->data->tex_height);
    
    player->data->so_texture = mlx_xpm_file_to_image(player->mlx->mlx, 
    player->data->so_path, &player->data->tex_with, &player->data->tex_height);

    player->data->we_texture = mlx_xpm_file_to_image(player->mlx->mlx, 
    player->data->we_path, &player->data->tex_with, &player->data->tex_height);

    player->data->ea_texture = mlx_xpm_file_to_image(player->mlx->mlx, 
    player->data->ea_path, &player->data->tex_with, &player->data->tex_height);
    
    if (!player->data->no_texture || !player->data->so_texture || 
        !player->data->we_texture || !player->data->ea_texture)
            return (1);
    player->data->no_address = mlx_get_data_addr(player->data->no_texture,
    &player->data->tex_bpp, &player->data->tex_line_len, &player->data->tex_endian);

    player->data->so_address = mlx_get_data_addr(player->data->so_texture, 
    &player->data->tex_bpp, &player->data->tex_line_len, &player->data->tex_endian);
    
    player->data->we_address = mlx_get_data_addr(player->data->we_texture, 
    &player->data->tex_bpp, &player->data->tex_line_len, &player->data->tex_endian);
    
    player->data->ea_address = mlx_get_data_addr(player->data->ea_texture, 
    &player->data->tex_bpp, &player->data->tex_line_len, &player->data->tex_endian);
    
    if (!player->data->no_address || !player->data->so_address ||
        !player->data->we_address || !player->data->ea_address)
            return (1);
    return (0);
}

void init_tex_side(char **tex_side, int wall_side, t_player *player)
{
    if (wall_side == 0)
        *tex_side = player->data->no_address;
        
    else if (wall_side == 1)
        *tex_side = player->data->so_address;

    else if (wall_side == 2)
        *tex_side = player->data->we_address;
        
    else if (wall_side == 3)
        *tex_side = player->data->ea_address;
        
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


int get_texture_pixel(char *addr, int x, int y, int tex_line_len, int tex_bpp, int tex_width, int tex_height)
{
    if (!addr || x >= tex_width || y >= tex_height || x < 0 || y < 0)
        return (0x808080);
    
    int offset = (y * tex_line_len) + (x * (tex_bpp / 8));
    return (*(int*)(addr + offset));
}