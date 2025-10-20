/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:18:03 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 13:21:43 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	store_data(int type, t_data *data, char *path)
{
	if (!data || !path)
		return (1);
	if (store_no_so_path(type, data, path) == 1)
		return (1);
	else if (store_we_ea_path(type, data, path) == 1)
		return (1);
	else if (store_f_c_path(type, data, path) == 1)
		return (1);
	else if (type == 9)
	{
		if (data->found.found_door == 1)
			return (1);
		data->found.found_door = 1;
		data->door_path = ft_strdup(path);
		if (!data->door_path)
			return (1);
	}
	return (0);
}

int	is_valid_extension(char *path, char *extension)
{
	int	len;
	int	fd;

	if (!path || !extension)
		return (1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	len = ft_strlen(path);
	if (ft_strncmp(&path[len - 4], extension, 4) != 0)
		return (1);
	close(fd);
	return (0);
}

int	get_type(char *line)
{
	if (!line)
		return (1);
	if (line[0] == '\0')
		return (10);
	else if (ft_strncmp("NO", line, 2) == 0 && ft_strlen(line) == 2)
		return (2);
	else if (ft_strncmp(line, "SO", 2) == 0 && ft_strlen(line) == 2)
		return (3);
	else if (ft_strncmp(line, "WE", 2) == 0 && ft_strlen(line) == 2)
		return (4);
	else if (ft_strncmp(line, "EA", 2) == 0 && ft_strlen(line) == 2)
		return (5);
	else if (ft_strncmp(line, "F", 1) == 0 && ft_strlen(line) == 1)
		return (6);
	else if (ft_strncmp(line, "C", 1) == 0 && ft_strlen(line) == 1)
		return (7);
	else if (ft_strncmp(line, "DOOR", 4) == 0 && ft_strlen(line) == 4)
		return (9);
	else if (!valid_chars(line, NULL, 0))
		return (8);
	else
		return (1);
}

void	remove_newline(char *line)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i])
		i++;
	if (i > 0 && line[i - 1] == '\n')
		line[i - 1] = '\0';
}

int	count_comma(char *line)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (line[i])
	{
		if (line[i] == ',')
			counter++;
		i++;
	}
	if (counter != 2)
		return (1);
	return (0);
}
