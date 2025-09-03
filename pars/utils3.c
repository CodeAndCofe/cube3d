/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:02:32 by zyahansa          #+#    #+#             */
/*   Updated: 2025/09/02 13:54:21 by zyahansa         ###   ########.fr       */
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

int all_walls(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1' && line[i] != ' ')
            return (1);
        i++;
    }
    return (0);

}
int map_closed(t_data *data)
{ 
    int i;
    int len;

    i = 0;
    len = 0;
    while (i < data->map_lines)
    {
        if (i == 0 && all_walls(data->maps[i]) != 0)
            return (1);
        if ( i == data->map_lines - 1 && all_walls(data->maps[i]) != 0)
            return (1);
        if (data->maps[i][0] != '1' && data->maps[i][0] != ' ')
            return (1);
        len = ft_strlen(data->maps[i]);
        if (len > 0 && data->maps[i][len - 1] != '1' && data->maps[i][len - 1] != ' ')
            return (1);
        i++;
    }
    return (0);
}

int valid_chars(char *line, int *player, int flag)
{
    int i;

    i = 0;
    while (line[i])
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
                {   
                        (*player)++;
                }
        }
        i++;
    }
    return (0);
}
