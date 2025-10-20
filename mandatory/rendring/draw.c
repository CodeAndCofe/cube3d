/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:55:07 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:01 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

int	draw_map(t_pixel *pixel, t_mlx *new_mlx, t_player *player)
{
	pixel->img = mlx_new_image(new_mlx->mlx, WIDTH, HEIGHT);
	pixel->addr = mlx_get_data_addr(pixel->img, &pixel->bits_per_pixel,
			&pixel->line_length, &pixel->endian);
	load_texture(player);
	player_view(pixel, player);
	mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, pixel->img, 0, 0);
	return (1);
}
