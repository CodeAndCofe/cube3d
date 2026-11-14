/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:59:57 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 14:21:02 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	*levels[3];
	int	level;

	(void)av;
	if (ac != 1)
		return (print_error());
	levels[0] = "maps/level1.cub";
	levels[1] = "maps/level2.cub";
	levels[2] = "maps/level3.cub";
	level = 0;
	while (level < 3)
	{
		data = ft_calloc(1, sizeof(t_data));
		if (!data || parsing_part(data, levels[level]) == 1)
			return (free_data(data), print_error());
		data->level = level + 1;
		if (start(data) == 0)
			return (free_data(data), 0);
		free_data(data);
		level++;
	}
	return (0);
}
