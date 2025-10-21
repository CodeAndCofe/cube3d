/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:40:29 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/21 16:06:48 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

int	door_next_space(t_data *data, int x, int y)
{
	if (x > 0 && y >= (int)ft_strlen(data->maps[x - 1]))
		return (1);
	if (y >= (int)ft_strlen(data->maps[x + 1]))
		return (1);
	if (ft_isspace(data->maps[x][y - 1]))
		return (1);
	if (ft_isspace(data->maps[x][y + 1]))
		return (1);
	if (ft_isspace(data->maps[x - 1][y]))
		return (1);
	if (ft_isspace(data->maps[x + 1][y]))
		return (1);
	return (0);
}


// #include "../../include/cub.h"

// int	is_walkable(char c)
// {
// 	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'D');
// }

// int	check_surrounded(t_data *data, int x, int y)
// {
// 	if (!is_walkable(data->maps[x][y]))
// 		return (0);
// 	if (x == 0 || y == 0)
// 		return (1);
// 	if (!data->maps[x + 1])
// 		return (1);
// 	if (!data->maps[x][y + 1])
// 		return (1);
// 	return (0);
// }

// int	is_out_of_bounds(t_data *data, int x, int y)
// {
// 	if (!is_walkable(data->maps[x][y]))
// 		return (0);
// 	if (x > 0 && y >= (int)ft_strlen(data->maps[x - 1]))
// 		return (1);
// 	if (data->maps[x + 1] && y >= (int)ft_strlen(data->maps[x + 1]))
// 		return (1);
// 	return (0);
// }

// int	zero_next_to_space(t_data *data, int x, int y)
// {
// 	if (!is_walkable(data->maps[x][y]))
// 		return (0);
// 	if (x > 0 && y < (int)ft_strlen(data->maps[x - 1])
// 		&& ft_isspace(data->maps[x - 1][y]))
// 		return (1);
// 	if (data->maps[x + 1] && y < (int)ft_strlen(data->maps[x + 1])
// 		&& ft_isspace(data->maps[x + 1][y]))
// 		return (1);
// 	if (y > 0 && ft_isspace(data->maps[x][y - 1]))
// 		return (1);
// 	if (data->maps[x][y + 1] && ft_isspace(data->maps[x][y + 1]))
// 		return (1);
// 	return (0);
// }

// int	map_closed(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = -1;
// 	while (data->maps[++x])
// 	{
// 		y = 0;
// 		if (data->maps[x][0] != '1' && !ft_isspace(data->maps[x][0]))
// 			return (1);
// 		if (data->maps[x][ft_strlen(data->maps[x]) - 1] != '1'
// 			&& !ft_isspace(data->maps[x][ft_strlen(data->maps[x]) - 1]))
// 			return (1);
// 		while (data->maps[x][y])
// 		{
// 			if (map_closed_helper(x, y, data) == 1)
// 				return (1);
// 			y++;
// 		}
// 	}
// 	return (0);
// }

// int	map_closed_helper(int x, int y, t_data *data)
// {
// 	if (first_last_line(x, data) == 1)
// 		return (1);
// 	if (check_surrounded(data, x, y) == 1)
// 		return (1);
// 	if (is_out_of_bounds(data, x, y) == 1)
// 		return (1);
// 	if (zero_next_to_space(data, x, y) == 1)
// 		return (1);
// 	return (0);
// }