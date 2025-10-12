/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:02:32 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/03 10:39:01 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int check_num(char *num)
{
    int i;

    i = 0;
    while (num[i])
    {
        if (!ft_isdigit(num[i]))
            return (1);
        i++;
    }
    return (0);
}



static int ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n'
         || c == '\v' || c == '\f' || c == '\r');
}

static int check_surrounded(t_data *data, int x, int y)
{
    if (x == 0 || y == 0)
        return (1);
    if (!data->maps[x + 1])
        return (1);
    if(!data->maps[x][y + 1])
        return (1);
    return (0);
}

static int is_out_of_bounds(t_data *data, int x, int y)
{
    if (y >= (int)ft_strlen(data->maps[x - 1]))
        return (1);
    if (y >= (int)ft_strlen(data->maps[x + 1]))
        return (1);
    return (0);
}

static int zero_next_to_space(t_data *data, int x, int y)
{
    if (((x > 0) && (ft_isspace(data->maps[x - 1][y]))) || ft_isspace(data->maps[x + 1][y]))
        return (1);
    if (((y > 1 )&& (ft_isspace(data->maps[x][y - 1]))) ||
        ft_isspace(data->maps[x][y + 1]))
        return (1);
    return (0);
}

int map_closed(t_data *data)
{
    int x;
    int y;

    x = 0;
    while (data->maps[x])
    {
        y = 0;
        if (data->maps[x][0] != '1' && data->maps[x][0] != ' ')
            return (1);
        if (data->maps[x][ft_strlen(data->maps[x]) - 1] != '1' && data->maps[x][ft_strlen(data->maps[x]) - 1] != ' ')
            return (1);
        while(data->maps[x][y])
        {
            if (x == 0 && (valid_chars(data->maps[x], NULL, 2) != 0))
                return (1);
            if (x + 1 == data->map_index && 
                (valid_chars(data->maps[x], NULL, 2) != 0))
                return (1);
            if (check_surrounded(data, x , y) || is_out_of_bounds(data, x, y)
                || zero_next_to_space(data, x, y))
                if (data->maps[x][y] == '0')
                    return (1);
            y++;
        }
        x++;
    }
    return (0);
}


int valid_chars(char *line, int *player, int flag)
{
    int i;

    i = -1;
    while (line[++i])
    {
        if ((line[i] != '0') && (line[i] != '1') && 
            (line[i] != ' ') && (line[i] != 'N') &&
            (line[i] != 'S') && (line[i] != 'E') &&
            (line[i] != 'W'))
            return (1);
        if (flag == 1)
        {
            if (line[i] == 'N' || line[i] == 'S' ||
                line[i] == 'E' || line[i] == 'W')
                (*player)++;
        }
        if (flag == 2)
        {
            if (line[i] == 'N' || line[i] == 'S' ||
                line[i] == 'E' || line[i] == 'W')
                return (1);
        }
    }
    return (0);
}
