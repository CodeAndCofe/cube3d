/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:02:56 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/14 16:52:37 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

// int	check_num(char *num)
// {
// 	int	i;

// 	i = 0;
// 	while (num[i])
// 	{
// 		if (!ft_isdigit(num[i]))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_isspace(char c)
// {
// 	return (c == ' ' || c == '\t');
// }

void	extract_path(char *line, int *i, int *j)
{
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	*j = *i;
	while (line[*j] && line[*j] != ' ' && line[*j] != '\t')
		(*j)++;
}

// int	valid_file(t_data *data)
// {
// 	if (!data->found.found_c || !data->found.found_f
// 		|| !data->found.found_ea || !data->found.found_no
// 		|| !data->found.found_so || !data->found.found_we)
// 		return (1);
// 	return (0);
// }
