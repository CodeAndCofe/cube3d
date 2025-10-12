/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:19:41 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/12 15:46:09 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"


void load_text_animation(t_player *player)
{
    player->data->frame1 = mlx_xpm_file_to_image(player->mlx->mlx,
    "texture/frame1.xpm", &player->data->frame_with, &player->data->frame_height);
    
    player->data->frame2 = mlx_xpm_file_to_image(player->mlx->mlx,
    "texture/frame2.xpm", &player->data->frame_with, &player->data->frame_height);    
    player->data->cur_frame = 0;
}

void display_animation(t_player *player, int *counter)
{
    if (!player->data->frame1 || !player->data->frame2)
        return; 
    int pos_x;
    int pos_y;
    void *frame;
    static int cur_frame = 0;

    pos_x = WIDTH / 4;
    pos_y = WIDTH / 3;

    (*counter)++;
    if (*counter >= 20)
    {
        cur_frame = !cur_frame;
        *counter = 0;
    }
    if (cur_frame == 0)
        frame = player->data->frame1;
    else
        frame = player->data->frame2;
    mlx_put_image_to_window(player->mlx->mlx, player->mlx->win_mlx,
        frame, pos_x, pos_y);
}
