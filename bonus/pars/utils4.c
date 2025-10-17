/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:52:31 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/16 20:00:17 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void	free_data(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = 0;
	if (data->maps)
	{
		while (i < data->map_lines)
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
		data->maps = malloc(sizeof(char *) * (data->map_lines + 1));
		if (!data->maps)
			return (1);
	}
	return (0);
}

int	valid_dor(t_data *data)
{
	int	i;
	int	j;
	int	len_line;

	i = 0;
	while (i < data->map_lines && data->maps[i])
	{
		j = 0;
		len_line = ft_strlen(data->maps[i]);
		while (j < len_line && data->maps[i][j])
		{
			if (data->maps[i][j] == 'D')
			{
				if (door_validation(data, i, j, len_line) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
