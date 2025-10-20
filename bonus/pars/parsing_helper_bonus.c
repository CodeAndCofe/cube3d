/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:59:45 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:01 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ex_cub.h"

int	start_parsing(char *line, t_data *data, int fd, int flag)
{
	(void)fd;
	remove_newline(line);
	if (flag == 1)
	{
		if (pars_line(line, data) == 1)
			return (1);
	}
	else if (flag == 2)
	{
		if (pars_map(line, data) == 1)
			return (1);
	}
	return (0);
}

int	store_no_so_path(int type, t_data *data, char *path)
{
	if (type == 2)
	{
		if (data->found.found_no == 1)
			return (1);
		data->found.found_no = 1;
		data->no_path = ft_strdup(path);
		if (!data->no_path)
			return (1);
	}
	else if (type == 3)
	{
		if (data->found.found_so == 1)
			return (1);
		data->found.found_so = 1;
		data->so_path = ft_strdup(path);
		if (!data->so_path)
			return (1);
	}
	return (0);
}

int	store_we_ea_path(int type, t_data *data, char *path)
{
	if (type == 4)
	{
		if (data->found.found_we == 1)
			return (1);
		data->found.found_we = 1;
		data->we_path = ft_strdup(path);
		if (!data->we_path)
			return (1);
	}
	else if (type == 5)
	{
		if (data->found.found_ea == 1)
			return (1);
		data->found.found_ea = 1;
		data->ea_path = ft_strdup(path);
		if (!data->ea_path)
			return (1);
	}
	return (0);
}

int	store_f_c_path(int type, t_data *data, char *path)
{
	if (type == 6)
	{
		if (data->found.found_f == 1)
			return (1);
		data->found.found_f = 1;
		data->f_color = convert_to_rgb(path);
		if (data->f_color == -1)
			return (1);
	}
	else if (type == 7)
	{
		if (data->found.found_c == 1)
			return (1);
		data->found.found_c = 1;
		data->c_color = convert_to_rgb(path);
		if (data->c_color == -1)
			return (1);
	}
	return (0);
}
