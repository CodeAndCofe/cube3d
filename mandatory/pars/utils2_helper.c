/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:02:56 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:01 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

void	init_data(t_data *data)
{
	data->ea_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->no_path = NULL;
	data->maps = NULL;
	data->map_index = 0;
	data->c_color = 0;
	data->f_color = 0;
	data->map_lines = 0;
	data->found.found_c = 0;
	data->found.found_f = 0;
	data->found.found_so = 0;
	data->found.found_we = 0;
	data->found.found_ea = 0;
	data->found.found_no = 0;
}

void	extract_path(char *line, int *i, int *j)
{
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
	*j = *i;
	while (line[*j] && line[*j] != ' ' && line[*j] != '\t')
		(*j)++;
}

int	count_word(char **holder)
{
	int	i;

	i = 0;
	if (!holder)
		return (0);
	while (holder[i])
		i++;
	return (i);
}

void	*remove_space(char *line)
{
	int	i;
	int	j;

	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			line[j++] = line[i];
		i++;
	}
	line[j] = '\0';
	return (line);
}
