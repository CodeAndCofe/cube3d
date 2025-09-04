/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:49:18 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/02 17:10:25 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"


char    **create_map()
{
    char    **map;

    map = malloc( sizeof (char *) * 5);
    if (map == NULL)
        return (NULL);
    int i = 0;
    map[i++] = ft_strdup("1111111111111111");
    if (!map[i - 1])
        return (NULL);
    while (i < 4)
    {
        map[i] = ft_strdup("1000100001000001");
        if (!map[i])
            return (NULL);
        i++;
    }
    map[i++] = ft_strdup("1111111111111111");
    if (!map[i - 1])
        return (NULL);
    return (map);
}





int    add_temporary_map(t_data    *data)
{
    char  **map;
    
    map = create_map();
    if (map == NULL)
        return -1;
    data->maps = map;
    return 1;
}