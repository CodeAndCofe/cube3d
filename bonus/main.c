/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:59:57 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 08:02:28 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

int print_error(void)
{
    ft_putstr_fd("Error\n", 2);
    return (1);
}

void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
    size_t total_size;

    total_size = count * size;
    ptr = malloc(total_size);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, total_size);
    return (ptr);
}

void g()
{
	system("leaks cub3d");
}
int main(int ac, char **av)
{
    t_data *data;

	atexit(g);
    if (ac != 2)
        return (print_error());
    data = ft_calloc(1, sizeof(t_data));
    if (!data)
        return (print_error());
    if (parsing_part(data, av[1]) == 1)
    {
        return (1);//hna khasni nzid free data
    }
    // print_parsed_header(data);
    start(data);
    return (0);
}
