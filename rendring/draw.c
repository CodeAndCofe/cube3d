/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:48:01 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/10 12:21:10 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

int	draw_line(t_player *player)
{
	t_pixel *pixel;
	
	pixel = malloc (sizeof (t_pixel));
	if (pixel == NULL)
		return (-1);
	pixel->next = NULL;
	line(pixel, 200, 0x0000FF, player);
	free(pixel);
	return (1);
}

int	draw_player(t_mlx *new_mlx, t_player *player)
{
	t_pixel *pixel;
	t_pixel *wlk;

	
	pixel = malloc (sizeof (t_pixel));
	if (pixel == NULL)
		return (-1);
	wlk = pixel;
	wlk->next = NULL;
	player_pixel(new_mlx, wlk, 20, 0xFF00FF);
	mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, wlk->img, player->x, player->y);
	pixels_free(pixel);
	draw_line(player);
	return (0);
}


int    draw_map(t_mlx *new_mlx, t_player *player)
{
	t_pixel *pixel;
	t_pixel *wlk;
	int     i;
	int     j;
	
	pixel = malloc (sizeof (t_pixel));
	if (pixel == NULL)
		return (-1);
	(1) && (wlk = pixel, i = 0, j = 0);
	while (player->data->maps[i])
	{
	    j = 0;
	    while (player->data->maps[i][j])
		{
			wlk->next = draw_object(player, i, j, new_mlx);
            wlk = wlk->next;
            if (wlk == NULL)
                return (pixels_free(pixel), -1);
            mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, wlk->img, j * 51, i * 51);
            j++;
		}
		i++;
	}
	wlk->next = NULL;
	return (pixels_free(pixel), draw_player(new_mlx, player));
}
