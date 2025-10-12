/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:18:12 by zyahansa          #+#    #+#             */
/*   Updated: 2025/09/02 14:00:31 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <string.h>

void init_data(t_data *data)
{
    data->ea_path = NULL;
    data->so_path = NULL;
    data->we_path = NULL;
    data->no_path = NULL;
    data->maps = NULL;
    data->map_index = 0;
    data->c_color = 0;
    data->f_color = 0;
    data->map_lines = 0;
    data->found.found_c = 0;
    data->found.found_f = 0;
    data->found.found_so = 0;
    data->found.found_we = 0;
    data->found.found_ea = 0;
    data->found.found_no = 0;
}

int pars_line_helper(char *line, int *type, char **path, t_data *data)
{
    int i;
    int j;

    i = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    j = i;
    while (line[j] && line[j] != ' ' && line[j] != '\t')
        j++;
    char *tmp = malloc(j - i + 1);
    if (!tmp)
        return (1);
    strncpy(tmp, &line[i], j - i);
    tmp[j - i] = '\0';
    *type = get_type(tmp, data);
    free(tmp);
    while (line[j] == ' ' || line[j] == '\t')
    {
        j++;
        if (line[j] == '\0')
            return 1;
    }
    *path = ft_strdup(&line[j]);
    if (!*path)
        return 1;  
    return (0); 
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
        return (1);
    if (count_word(holder) != 3)
    {
        //freee_holder
        return (1);
    }
    if (check_num(holder[0]) || check_num(holder[1]) || check_num(holder[2]))
        return (1);
    r = ft_atoi(holder[0]);
    g = ft_atoi(holder[1]);
    b = ft_atoi(holder[2]);
        // free_holder(holder);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        return (1);
    return ((r << 16) | (g << 8) | b);
} 
void free_holder(char **holder)
{
    int i;

    if (!holder)
        return;
    i = 0;
    while (holder[i])
    {
        free(holder[i]);
        i++;
    }
    free(holder);
}

int valid_file(t_data *data)
{
    if (!data->found.found_c || !data->found.found_f ||
       !data->found.found_ea || !data->found.found_no ||
       !data->found.found_so || !data->found.found_we)
        return (1);
    return (0);
}
