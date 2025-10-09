/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:05:59 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/09 14:18:54 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"




void	drawing_wall(t_player *player, t_pixel *pixel, int i)
{
	double	projectplane_distnace  = (WIDTH / 2) / tan(degree_to_radiant(VIEW / 2));// project plane distance its (opssite / tan (a) == adjacent)
	double	wall_hieght = ((double)OBJECT / player->distance) * projectplane_distnace;// wall hight in project plane view
	int	wall_start = (HEIGHT / 2) - (wall_hieght / 2);
	if (wall_hieght < 0)
		wall_hieght = 0;
	int	wall_end = (HEIGHT / 2) + (wall_hieght / 2);
	if (wall_end > HEIGHT - 1)
		wall_end = HEIGHT - 1;
	int	x  = 0;
	while (x < wall_start)
	{
		my_mlx_pixel_put(pixel, i, x, W_COLOR);
		x++;
	}
	
	while (wall_start < wall_end)
	{
		my_mlx_pixel_put(pixel, i, wall_start, P_COLOR);
		wall_start++;
	}
}
