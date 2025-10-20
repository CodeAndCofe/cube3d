/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:06:27 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:01 by aferryat         ###   ########.fr       */
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
	{
		return (1);
	}
	return (0);
}

void	pixel_putter(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	if (the_limit(x, y) == 1)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(int *)dst = color;
}
