/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:19:41 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/16 18:25:28 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ex_cub.h"

// void	display_animation(t_player *player, int *counter)
// {
// 	static int	cur_frame = 0;
// 	int			pos_x;
// 	int			pos_y;
// 	void		*frame;

// 	if (!player->data->frame1 || !player->data->frame2)
// 		return ;
// 	pos_x = WIDTH / 4;
// 	pos_y = WIDTH / 3;
// 	(*counter)++;
// 	if (*counter >= 2)
// 	{
// 		cur_frame = (player->data->cur_frame + 1) % player->data->frame_count;
// 		*counter = 0;
// 	}
// 	mlx_put_image_to_window(player->mlx->mlx, player->mlx->win_mlx,
// 		frames[player->data->cur_frame], pos_x, pos_y);
// }
// void	load_text_animation(t_player *player)
// {
// 	char	*frames[20];
// 	int		i;

// 	i = 0;
// 	*frames[20] = {
// 		"texture/frame1.xpm", "texture/frame2.xpm", "texture/frame3.xpm",
// 		"texture/frame4.xpm", "texture/frame5.xpm", "texture/frame6.xpm",
// 		"texture/frame7.xpm", "texture/frame8.xpm", "texture/frame9.xpm",
// 		"texture/frame10.xpm", "texture/frame11.xpm", "texture/frame12.xpm",
// 		"texture/frame13.xpm", "texture/frame14.xpm", "texture/frame15.xpm",
// 		"texture/frame16.xpm", "texture/frame17.xpm", "texture/frame18.xpm",
// 		"texture/frame19.xpm", "texture/frame20.xpm"
// 	};
// 	while (i < 20)
// 	{
// 		player->data->frames[i] = mlx_xpm_file_to_image(player->mlx->mlx,
// 		frames[i], &player->data->frame_with, &player->data->frame_height);
// 		i++;
// 	}
// 	player->data->frame_count = 20;
// 	player->data->cur_frame = 0;
// }
