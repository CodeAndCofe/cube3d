/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:06:27 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/22 16:44:29 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

int	the_limit(int x, int y)
{
	if (x < 0 || x > WIDTH - 1 || y < 0 || y > HEIGHT - 1)
		return (1);
	return (0);
}

int	cordinate_limit(int x, int y, t_data *data)
{
	if (y < 0 || y >= data->map_lines
		|| x < 0 || x >= (int)ft_strlen(data->maps[y]))
		return (1);
	return (0);
}

void	pixel_putter(t_pixel *data, int x, int y, int color)
{
	uint32_t	mlx_color;
	uint8_t	*pixel;

	if (the_limit(x, y) == 1)
		return ;
	mlx_color = (uint32_t)color;
	if (mlx_color <= 0xFFFFFF)
		mlx_color = (mlx_color << 8) | 0xFF;
	pixel = &data->img->pixels[(y * data->img->width + x) * 4];
	pixel[0] = mlx_color >> 24;
	pixel[1] = mlx_color >> 16;
	pixel[2] = mlx_color >> 8;
	pixel[3] = mlx_color;
}
