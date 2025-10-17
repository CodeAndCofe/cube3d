/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:02:32 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/16 18:51:51 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_surrounded(t_data *data, int x, int y)
{
	if (x == 0 || y == 0)
		return (1);
	if (!data->maps[x + 1])
		return (1);
	if (!data->maps[x][y + 1])
		return (1);
	return (0);
}

static int	is_out_of_bounds(t_data *data, int x, int y)
{
	if (y >= (int)ft_strlen(data->maps[x - 1]))
		return (1);
	if (y >= (int)ft_strlen(data->maps[x + 1]))
		return (1);
	return (0);
}

static int	zero_next_to_space(t_data *data, int x, int y)
{
	if (((x > 0) && (ft_isspace(data->maps[x - 1][y])))
		|| ft_isspace(data->maps[x + 1][y]))
		return (1);
	if (((y > 1) && (ft_isspace(data->maps[x][y - 1]))) ||
		ft_isspace(data->maps[x][y + 1]))
		return (1);
	return (0);
}

int	valid_chars(char *line, int *player, int flag)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if ((line[i] != '0') && (line[i] != '1')
			&& (line[i] != ' ') && (line[i] != 'N')
			&& (line[i] != 'S') && (line[i] != 'E')
			&& (line[i] != 'W') && line[i] != 'D')
			return (1);
		if (flag == 1)
		{
			if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
				|| line[i] == 'W')
				(*player)++;
		}
		if (flag == 2)
		{
			if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W')
				return (1);
		}
	}
	return (0);
}

int	map_closed(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (data->maps[++x])
	{
		y = 0;
		if (data->maps[x][0] != '1' && data->maps[x][0] != ' ')
			return (1);
		if (data->maps[x][ft_strlen(data->maps[x]) - 1] != '1'
			&& data->maps[x][ft_strlen(data->maps[x]) - 1] != ' ')
			return (1);
		while (data->maps[x][y])
		{
			if (first_last_line(x, data) == 1)
				return (1);
			if ((check_surrounded(data, x, y) == 1)
				|| (is_out_of_bounds(data, x, y) == 1)
				|| (zero_next_to_space(data, x, y) == 1))
				if (data->maps[x][y] == '0')
					return (1);
			y++;
		}
	}
	return (0);
}
