/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 10:59:54 by zyahansa          #+#    #+#             */
/*   Updated: 2025/08/29 15:27:12 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "string.h"
void print_parsed_header(t_data *data)
{
    printf("🌄 Textures:\n");
    printf("   NO: %s\n", data->no_path);
    printf("   SO: %s\n", data->so_path);
    printf("   WE: %s\n", data->we_path);
    printf("   EA: %s\n", data->ea_path);

    printf("🎨 Colors:\n");
    printf("   Floor: %d\n", data->f_color);
    printf("   Ceiling: %d\n", data->c_color);

    printf("✅ Header Validation:\n");
    printf("   NO found: %d\n", data->found.found_no);
    printf("   SO found: %d\n", data->found.found_so);
    printf("   WE found: %d\n", data->found.found_we);
    printf("   EA found: %d\n", data->found.found_ea);
    printf("   F  found: %d\n", data->found.found_f);
    printf("   C  found: %d\n", data->found.found_c);
}

// int check_file(char *line)
// {
//     if (is_valid_extension(line, "") == 0)
//         return (0);
//     // if (open_file(line) == 0)
//     //     return (0);
//     return (1);
// }

int pars_line(char *line, t_data *data)
{
    char *new_line;
    char *path;
    int type;
    int i;

    i = 0;
    if (!line || line[0] == '\0')
        return 1;
    while (line[i] == ' ')
        i++;
    new_line = ft_strchr(&line[i], ' ');
    if (!new_line)
        return 1;
        
    int index = new_line - &line[i];
    char *tmp = malloc(index + 1);
    strncpy(tmp, &line[i], index);
    tmp[index] = '\0';
    type = get_type(tmp);
    // exit(3);
    while (*new_line == ' ')
        new_line++;
    if (*new_line == '\0')
        return 1;
    path = ft_strdup(new_line);
    if (!path)
        return 1;
    if (type >= 2 && type <= 7)
        if (!is_valid_extension(path, ".xpm"))
            return 1;
    store_data(type, data, path);
    if(store_data(type, data, path) != 0)
    {
        free(path);
        return 1;
    }
    free(path);
    return (0);
}

int open_read(t_data *data, char *file_name)
{
    int fd;
    char *line;

    if (!data || !file_name)
        return  (1);
        //add file extention .cub 
    fd = open(file_name, O_RDONLY);
    if(fd == -1)
        return (1);
    line = get_next_line(fd);// check next_line ila filat
    while (line)
    {
        remove_newline(line);
        if (line[0] != '\0')
            pars_line(line, data);
        free(line);
        line = get_next_line(fd); 
    }
    close(fd);
    return (0);
} 

int parsing_part(t_data *data, char *file_name)
{
    init_data(data);
    if (open_read(data, file_name) == 1)
        return (1);
    return (0);
}
