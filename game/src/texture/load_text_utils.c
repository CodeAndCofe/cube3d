/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:19:41 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/25 20:04:32 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

int	load_text_animation(t_player *player)
{
	int		i;
	char	frames[3][50];
	mlx_texture_t	*texture;

	i = 0;
	ft_strcpy1(frames[0], "textures/frame1.xpm");
	ft_strcpy1(frames[1], "textures/frame2.xpm");
	ft_strcpy1(frames[2], "textures/frame3.xpm");
	while (i < 3)
	{
		texture = load_xpm(frames[i]);
		if (!texture)
			return (1);
		player->data->frames[i] = mlx_texture_to_image(player->mlx->mlx,
				texture);
		mlx_delete_texture(texture);
		if (!player->data->frames[i])
			return (1);
		player->data->frame_with = player->data->frames[i]->width;
		player->data->frame_height = player->data->frames[i]->height;
		mlx_image_to_window(player->mlx->mlx, player->data->frames[i], 0, 0);
		player->data->frames[i]->instances[0].z = 2;
		player->data->frames[i]->enabled = false;
		i++;
	}
	player->data->frame_count = 3;
	return (0);
}

void	display_animation(t_player *player, int *counter)
{
	int	pos_x;
	int	pos_y;

	if (!player->data->start_animation)
		return ;
	pos_x = WIDTH / 2;
	pos_y = HEIGHT - player->data->frame_height + 15;
	if (!player->data->frames[player->data->cur_frame])
		return ;
	player->data->frames[player->data->cur_frame]->enabled = true;
	player->data->frames[player->data->cur_frame]->instances[0].x = pos_x;
	player->data->frames[player->data->cur_frame]->instances[0].y = pos_y;
	(*counter)++;
	if (*counter >= 10)
	{
		player->data->frames[player->data->cur_frame]->enabled = false;
		player->data->cur_frame++;
		if (player->data->cur_frame >= player->data->frame_count)
		{
			player->data->cur_frame = 0;
			player->data->start_animation = 0;
		}
		*counter = 0;
	}
}
