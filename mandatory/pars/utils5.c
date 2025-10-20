/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:11:31 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 13:15:24 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ex_cub.h"

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
