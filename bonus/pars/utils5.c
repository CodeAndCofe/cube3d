/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:11:31 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/16 19:59:49 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

int	check_num(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

void	extract_rgb(char **holder, int *r, int *g, int *b)
{
	*r = ft_atoi(holder[0]);
	*g = ft_atoi(holder[1]);
	*b = ft_atoi(holder[2]);
	free_holder(holder);
}

int	first_last_line(int x, t_data *data)
{
	if (x == 0 && (valid_chars(data->maps[x], NULL, 2) != 0))
		return (1);
	if (x + 1 == data->map_index
		&& (valid_chars(data->maps[x], NULL, 2) != 0))
		return (1);
	return (0);
}

int	door_validation(t_data *data, int i, int j, int len_line)
{
	int	left_right;
	int	top_bottom;

	left_right = 0;
	top_bottom = 0;
	len_line = ft_strlen(data->maps[i]);
	if (i == 0 || i == data->map_lines - 1)
		return (1);
	if (j == 0 || j == len_line - 1)
		return (1);
	if (data->maps[i][j - 1] == '1'
		&& data->maps[i][j + 1] == '1')
		left_right = 1;
	if ((i > 0) && data->maps[i - 1][j] == '1'
		&& data->maps[i + 1][j] == '1')
		top_bottom = 1;
	if ((top_bottom && left_right) || (!top_bottom && !left_right))
		return (1);
	return (0);
}
