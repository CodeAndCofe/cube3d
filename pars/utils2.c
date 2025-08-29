/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:18:12 by zyahansa          #+#    #+#             */
/*   Updated: 2025/08/29 14:44:17 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void init_data(t_data *data)
{
    data->ea_path = NULL;
    data->so_path = NULL;
    data->we_path = NULL;
    data->no_path = NULL;
    data->c_color = 0;
    data->f_color = 0;
}
int count_word(char **holder)
{
    int i;

    i = 0;
    if (!holder)
        return (0);
    while (holder[i])
        i++;
    return (i);
}

int convert_to_rgb(char *color)
{
    char **holder;
    int r;
    int g;
    int b;

    holder = ft_split(color, ',');
    if (!holder)
        return (0);
    if (count_word(holder) != 3)
    {
        //freee_holder
        return (1);
    }
    r = ft_atoi(holder[0]);
    g = ft_atoi(holder[1]);
    b = ft_atoi(holder[2]);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    {
        // free_holder(holder);
        return (1);
    }
    // free_holder(holder);
    return ((r << 16) | (g << 8) | b);
} 
