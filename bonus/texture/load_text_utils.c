/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:19:41 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/19 17:14:18 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ex_cub.h"

int	load_text_animation(t_player *player)
{
	int		i;

	i = 0;
	char	*frames[3] =
    {
		"texture/frame1.xpm", "texture/frame2.xpm", "texture/frame3.xpm"
    };
	while (i < 3)
	{
		player->data->frames[i] = mlx_xpm_file_to_image(player->mlx->mlx,
			frames[i], &player->data->frame_with, &player->data->frame_height);
		if (!player->data->frames[i])
			return (1);
		i++;
	}
	player->data->frame_count = 3;
	return (0);
}

void display_animation(t_player *player, int *counter)
{
    int pos_x = WIDTH / 2;
    int pos_y = HEIGHT - player->data->frame_height + 15;
    
    printf("DEBUG - cur_frame: %d, frame_count: %d, counter: %d, frame_ptr: %p\n", 
           player->data->cur_frame, 
           player->data->frame_count, 
           *counter,
           player->data->frames[player->data->cur_frame]);
    
    (*counter)++;
    if (*counter >= 1)
    {
        player->data->cur_frame = (player->data->cur_frame + 1) % player->data->frame_count;
        *counter = 0;
        printf("FRAME CHANGED to: %d\n", player->data->cur_frame);
    }
    
    mlx_put_image_to_window(player->mlx->mlx, 
                           player->mlx->win_mlx,
                           player->data->frames[player->data->cur_frame], 
                           pos_x, 
                           pos_y);
}
