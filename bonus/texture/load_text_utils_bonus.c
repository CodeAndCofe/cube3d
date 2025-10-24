/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:19:41 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/24 16:58:24 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

int	load_text_animation(t_player *player)
{
	int		i;
	char	frames[3][50];

	i = 0;
	ft_strcpy1(frames[0], "textures/frame1.xpm");
	ft_strcpy1(frames[1], "textures/frame2.xpm");
	ft_strcpy1(frames[2], "textures/frame3.xpm");
	while (i < 3)
	{
		player->data->frames[i] = mlx_xpm_file_to_image(player->mlx->mlx,
				frames[i], &player->data->frame_with,
				&player->data->frame_height);
		if (!player->data->frames[i])
			return (1);
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
	mlx_put_image_to_window(player->mlx->mlx,
		player->mlx->win_mlx,
		player->data->frames[player->data->cur_frame],
		pos_x,
		pos_y);
	(*counter)++;
	if (*counter >= 10)
	{
		player->data->cur_frame++;
		if (player->data->cur_frame >= player->data->frame_count)
		{
			player->data->cur_frame = 0;
			player->data->start_animation = 0;
		}
		*counter = 0;
	}
}

