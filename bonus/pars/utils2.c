/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:18:12 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/16 15:14:07 by zyahansa         ###   ########.fr       */
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
    data->door_path = NULL;
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
    data->found.found_door = 0;

}

int pars_line_helper(char *line, int *type, char **path, t_data *data)
{
    int i;
    int j;
    char *tmp;

    i = 0;
    (void)data;
	extract_path(line, &i, &j);
    tmp = malloc(j - i + 1);
    if (!tmp)
        return (1);
    strncpy(tmp, &line[i], j - i);
    tmp[j - i] = '\0';
    *type = get_type(tmp);
    free(tmp);   
    while (line[j] == ' ' || line[j] == '\t')
    {
        j++;
        if (line[j] == '\0')
            return 1;
    }
    *path = ft_strdup(&line[j]);
    if (!*path)
        return (1);  
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

int valid_space(char **holder)
{
    int i;
    int j;
    int flag;

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


// int valid_space(char **holder)
// {
//     int i;
//     int j;
//     int found_non_space;

//     i = 0;
//     if (!holder)
//         return (0);
    
//     while (holder[i])
//     {
//         j = 0;
//         found_non_space = 0;
        
//         while (holder[i][j])
//         {
//             if (holder[i][j] != ' ')
//             {
//                 // If we find a non-space character after already finding one and then spaces
//                 if (found_non_space == 1)
//                 {
//                     // We already had a non-space character, then spaces, now another non-space = invalid
//                     return (1);
//                 }
//                 found_non_space = 1;  // Mark that we found the first non-space
//             }
//             j++;
//         }
//         i++;
//     }
//     return (0); 
// }

void *remove_space(char *line)
{
    int i;
    int j;

    
    i = 0;
    j = 0;
    while (line[i])
    {
        if (line[i] != ' ')
            line[j++] = line[i];
        i++;
    }
    line[j] = '\0';

    return (line);
}

int convert_to_rgb(char *color)
{
    char **holder;
    int i;
    int r;
    int g;
    int b;

    i = -1;
    holder = ft_split(color, ',');
    if (!holder)
        return (1);
    if (count_word(holder) != 3 || valid_space(holder) == 1)
    {
        free_holder(holder);
        return (1);
    }
    while (++i < 3)
        remove_space(holder[i]);
    if (check_num(holder[0]) || check_num(holder[1]) || check_num(holder[2]))
    {
        free_holder(holder);
        return (1);
    }
    r = ft_atoi(holder[0]);
    g = ft_atoi(holder[1]);
    b = ft_atoi(holder[2]);
    free_holder(holder);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        return (1);
    return ((r << 16) | (g << 8) | b);
}


void free_holder(char **holder)
{
    int i;

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


int valid_file(t_data *data)
{
    if (!data->found.found_c || !data->found.found_f ||
       !data->found.found_ea || !data->found.found_no ||
       !data->found.found_so || !data->found.found_we)
        return (1);
    return (0);
}














// static int zero_next_to_space(t_data *data, int x, int y)
// {
//     char current;
    
//     current = data->maps[x][y];
    
//     // Skip si c'est un mur ou un espace
//     if (current == '1' || ft_isspace(current))
//         return (0);
    
//     // Check si 0, N, S, E, W, ou D est à côté d'un espace
//     if (current == '0' || current == 'N' || current == 'S' || 
//         current == 'E' || current == 'W' || current == 'D')
//     {
//         if (((x > 0) && (ft_isspace(data->maps[x - 1][y]))) || 
//             ft_isspace(data->maps[x + 1][y]))
//             return (1);
//         if (((y > 0) && (ft_isspace(data->maps[x][y - 1]))) ||
//             ft_isspace(data->maps[x][y + 1]))
//             return (1);
//     }
//     return (0);
// }

// int map_closed(t_data *data)
// {
//     int x;
//     int y;

//     x = 0;
//     while (data->maps[x])
//     {
//         y = 0;
//         if (data->maps[x][0] != '1' && data->maps[x][0] != ' ')
//             return (1);
//         if (data->maps[x][ft_strlen(data->maps[x]) - 1] != '1' && 
//             data->maps[x][ft_strlen(data->maps[x]) - 1] != ' ')
//             return (1);
//         while(data->maps[x][y])
//         {
//             if (x == 0 && (valid_chars(data->maps[x], NULL, 2) != 0))
//                 return (1);
//             if (x + 1 == data->map_index && 
//                 (valid_chars(data->maps[x], NULL, 2) != 0))
//                 return (1);
            
//             // Check pour tous les caractères "walkable"
//             if ((check_surrounded(data, x , y) == 1) || 
//                 (is_out_of_bounds(data, x, y) == 1) ||
//                 (zero_next_to_space(data, x, y) == 1))
//                 return (1);
            
//             y++;
//         }
//         x++;
//     }
//     return (0);
// }

