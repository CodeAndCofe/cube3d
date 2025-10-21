/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:18:12 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/21 15:35:26 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	pars_line_helper(char *line, int *type, char **path, t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	(void)data;
	extract_path(line, &i, &j);
	tmp = malloc(j - i + 1);
	if (!tmp)
		return (1);
	ft_strncpy(tmp, &line[i], j - i);
	tmp[j - i] = '\0';
	*type = get_type(tmp);
	free(tmp);
	if (*type != 8)
	{
		while (line[j] == ' ' || line[j] == '\t')
			if (line[++j] == '\0')
				return (1);
	}
	*path = ft_strdup(&line[j]);
	if (!*path)
		return (1);
	return (0);
}

int	valid_space(char **holder)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	if (!holder)
		return (0);
	while (holder[i])
	{
		j = 0;
		flag = 0;
		while (holder[i][j] == ' ')
			j++;
		while (holder[i][j])
		{
			if (holder[i][j] == ' ')
				flag = 1;
			else if (flag == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_holder(char **holder)
{
	int	i;

	if (!holder)
		return ;
	i = 0;
	while (holder[i])
	{
		free(holder[i]);
		i++;
	}
	free(holder);
}

int	valid_file(t_data *data)
{
	if (!data->found.found_c || !data->found.found_f
		|| !data->found.found_ea || !data->found.found_no
		|| !data->found.found_so || !data->found.found_we)
		return (1);
	return (0);
}

int	convert_to_rgb(char *color)
{
	char	**holder;
	t_color	rgb;

	(1) && (rgb.i = -1, holder = ft_split(color, ','));
	if (!holder)
		return (1);
	if (count_comma(color) == 1)
		return (-1);
	if (count_word(holder) != 3 || valid_space(holder) == 1)
	{
		free_holder(holder);
		return (-1);
	}
	while (++rgb.i < 3)
		remove_space(holder[rgb.i]);
	if (check_num(holder[0]) || check_num(holder[1]) || check_num(holder[2]))
	{
		free_holder(holder);
		return (-1);
	}
	extract_rgb(holder, &rgb.r, &rgb.g, &rgb.b);
	if (rgb.r < 0 || rgb.r > 255 || rgb.g < 0
		|| rgb.g > 255 || rgb.b < 0 || rgb.b > 255)
		return (-1);
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}
