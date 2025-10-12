/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:52:31 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/07 12:06:48 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

int valid_dor(t_data *data)
{
    int i;
    int j;
    int len_line;
    i = 0;


    while (i < data->map_lines && data->maps[i])
    {
        j = 0;
        len_line = ft_strlen(data->maps[i]);
        while (j < len_line && data->maps[i][j])
        {
            if (data->maps[i][j] == 'D')
            {
                if (i == 0 || i == data->map_lines - 1)// check dor f top/botton
                    return (1);
                if (j == 0 || j == len_line - 1)// dor f left /right edge    
                    return (1);
                // if ((( i > 0 && data->maps[i][j - 1] != '1') ||  (j > 0 && data->maps[i][j + 1] != '1')) || ((data->maps[i + 1][j] != '1') && (data->maps[i - 1][j] != '1')))
                //     return (1);
                // printf("ssssssss\n");
            }
            j++;
        }
        i++;
    }

    return (0);
}

void free_data(t_data *data)
{
    if (!data)
        return ;

    int i;

    i = 0;
    if (data->maps)
    {
        while (i < data->map_lines)
        {
            free(data->maps[i]);
            i++;
        }
        free(data->maps);
    }
    free(data->no_path);
    free(data->so_path);
    free(data->ea_path);
    free(data->we_path);
    free(data);
}
