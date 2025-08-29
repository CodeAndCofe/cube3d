/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:18:03 by zyahansa          #+#    #+#             */
/*   Updated: 2025/08/29 15:25:15 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


int store_data(int type, t_data *data, char *path)
{
    if (!data || !path)
        return (1);
        
    if (type == 2) // NO
    {
        
        if (data->found.found_no == 1)
            return(1);
        data->found.found_no = 1;
        data->no_path = ft_strdup(path);
    }
    else if (type == 3) // SO
    {
        
        if (data->found.found_so == 1)
            return(1);
        data->found.found_so = 1;
        data->so_path = ft_strdup(path);
    }
    else if (type == 4) //we
    {
        
        if (data->found.found_we == 1)
            return(1);
        data->found.found_we = 1;
        data->we_path = ft_strdup(path);
    }
    else if (type == 5) // EA
    {
        
        if (data->found.found_ea == 1)
            return(1);
        data->found.found_ea = 1;
        data->ea_path = ft_strdup(path);
    }
    else if (type == 6) // FLOOR COLOR
    {
        
        if (data->found.found_f == 1)
            return(1);
        data->found.found_f = 1;
        data->f_color = convert_to_rgb(path);
    }
    else if (type == 7) // CEILLING COLOR
    {
        
        if (data->found.found_c == 1)
            return(1);
        data->found.found_c = 1;
        data->c_color = convert_to_rgb(path);
    }
    return (0);
}


int is_valid_extension(char *path, char *name)// X 0 1 return 
{
    int len;

    if (!path)
        return (1);
    len = ft_strlen(path);
    if (len < 5)
        return (0);
    if (ft_strncmp(&path[len - 4], name, 4) == 0)
        return (1);
    return (0);
}

int get_type(char *line)
{
    int i;

    i = 0;
    if (!line || line[0] == '\0')
        return (1);
    if (line[0] == '\0')
        return (1);
    while (line[i] == ' ')
        i++;
    if(ft_strncmp("NO", line, 3) == 0)
        return (2);
    else if(ft_strncmp(line, "SO", 3) == 0)
        return (3);
    else if(ft_strncmp(line, "WE", 3) == 0)
        return (4);
    else if(ft_strncmp(line, "EA", 3) == 0)
        return (5);
    else if(ft_strncmp(line, "F", 2) == 0)
        return (6);
    else if(ft_strncmp(line, "C", 2) == 0)
        return (7);
    return (8);
}

void remove_newline(char *line)
{
    int i;

    if (!line)
        return ;
    i = 0;
    while (line[i])
        i++;
    if (i > 0 && line[i - 1] == '\n')
        line[i - 1] = '\0';
}
