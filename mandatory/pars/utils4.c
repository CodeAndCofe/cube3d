/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:52:31 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/21 19:42:35 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	free_data(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = 0;
	if (data->maps)
	{
		while (i < data->map_lines && data->maps[i])
		{
			free(data->maps[i]);
			i++;
		}
		free(data->maps);
	}
	free(data->no_path);
	free(data->so_path);
	free(data->ea_path);
	free(data->we_path);
	free(data);
}

int	map_start(t_data *data, int type)
{
	static int	empty_line;

	if (data->map_start == 1)
	{
		if (type == 10)
			empty_line = 1;
		if (empty_line && type == 8)
			return (1);
		if (type != 8 && type != 10)
			return (1);
	}
	return (0);
}

int	init_map(t_data *data)
{
	if (data->map_index == 0)
	{
		data->maps = ft_calloc((data->map_lines + 1), sizeof(char *));
		if (!data->maps)
			return (1);
	}
	return (0);
}

int	map_closed_helper(int x, int y, t_data *data)
{
	if (first_last_line(x, data) == 1)
		return (1);
	if ((check_surrounded(data, x, y) == 1)
		|| (is_out_of_bounds(data, x, y) == 1)
		|| (zero_next_to_space(data, x, y) == 1))
	{
		if (data->maps[x][y] == '0')
			return (1);
		if (data->maps[x][y] == 'N' || data->maps[x][y] == 'E'
			|| data->maps[x][y] == 'S' || data->maps[x][y] == 'W')
			return (1);
	}
	return (0);
}
