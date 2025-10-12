/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:01:48 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/12 13:59:12 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ex_cub.h"

static void load_door(t_player *player)
{
    void *img;

    img = mlx_xpm_file_to_image(player->mlx->mlx, "texture/door.xpm", &player->data->door_tex_width, &player->data->door_tex_height);
    if (!img)
        return ;
    player->data->door_texture = img;
    player->data->door_address = mlx_get_data_addr(img, &player->data->door_tex_bpp, 
    &player->data->door_tex_line_len, &player->data->door_tex_endian);
}

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
    load_door(player);
    load_text_animation(player);

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
    else if (wall_side == 4)
        *tex_side = player->data->door_address;
        
}

double get_top(double wall_height)
{
    double top;

    top = (HEIGHT / 2) - (wall_height / 2);
    if(top < 0)
        top = 0;
    return (top);
}

double get_bottom(double wall_height)
{
    double bottom;

    bottom = (HEIGHT / 2) + (wall_height / 2);
    if (bottom >= HEIGHT)
        bottom = HEIGHT - 1;
    return (bottom);
}


int get_texture_pixel(char *addr, int x, int y, int tex_line_len, int tex_bpp)
{
    int offset;
    offset = (y * tex_line_len) + (x * (tex_bpp / 8));
    return (*(int*)(addr + offset));
}
