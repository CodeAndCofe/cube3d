/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:40:29 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/21 18:11:09 by aferryat         ###   ########.fr       */
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
