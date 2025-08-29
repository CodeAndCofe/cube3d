#include "cub.h"

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
        print_error();
        return (1);
    }
    r = ft_atoi(holder[0]);
    g = ft_atoi(holder[1]);
    b = ft_atoi(holder[2]);
    if (r < 0 || r > 255 || g < 0 || g > 55 || b < 0 || b > 255)
    {
        // free_holder(holder);
        print_error();
        return (1);
    }
    // free_holder(holder);
    return ((r << 16) | (g << 8) | b);
} 

int store_data(int type, t_data *data, char *path)
{
    printf("gggggggggg/n");
    if (!data || !path)
        return (1);
        
    if (type == 2) // NO
    {
        
        if (data->found.found_no == 1)
            return(print_error(), 1);
        data->found.found_no = 1;
        data->no_path = ft_strdup(path);
        printf("==>%s\n", path);
    }
    else if (type == 3) // SO
    {
        
        if (data->found.found_so == 1)
            return(print_error(), 1);
        data->found.found_so = 1;
        data->so_path = ft_strdup(path);
    }
    else if (type == 4) //we
    {
        
        if (data->found.found_we == 1)
            return(print_error(), 1);
        data->found.found_we = 1;
        data->we_path = ft_strdup(path);
    }
    else if (type == 5) // EA
    {
        
        if (data->found.found_ea == 1)
            return(print_error(), 1);
        data->found.found_ea = 1;
        data->ea_path = ft_strdup(path);
    }
    else if (type == 6) // FLOOR COLOR
    {
        
        if (data->found.found_f == 1)
            return(print_error(), 1);
        data->found.found_f = 1;
        data->f_color = convert_to_rgb(path);
    }
    else if (type == 7) // CEILLING COLOR
    {
        
        if (data->found.found_c == 1)
            return(print_error(), 1);
        data->found.found_c = 1;
        data->c_color = convert_to_rgb(path);
    }
    return (0);
}


int is_valid_extension(char *path)// X 0 1 return 
{
    int len;

    if (!path)
        return (1);
    len = ft_strlen(path);
    if (len < 5)
        return (0);
    if (ft_strncmp(&path[len - 4], ".xpm", 4) == 0)
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
    if(ft_strncmp(line, "NO", 3) == 0)
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

int check_file(char *line)
{
    if (is_valid_extension(line) == 0)
        return (0);
    // if (open_file(line) == 0)
    //     return (0);
    return (1);
}

void pars_line(char *line, int type, t_data *data)
{
    char *new_line;
    char *path;
    int i;

    i = 0;
    if (!line || line[0] == '\0')
        return ;
    while (line[i] == ' ')
        i++;
    new_line = ft_strchr(&line[i], ' ');
    if (!new_line)
        return ;
    new_line++;
    while (*new_line == ' ')
        new_line++;
    if (*new_line == '\0')
        return ;
    path = ft_strdup(new_line);
    if (!path)
        return ;
    if (type >= 2 && type <= 7)
    {
        if (is_valid_extension(path))
        {
            print_error();
            return ;
        }
    }
    printf("yoyoyoy\n");
    store_data(type, data, path);
    // if(store_data(type, data, path) != 0)
    // {
    //     free(path);
    //     return ;
    // }
    free(path);
}

void open_read(t_data *data, char *file_name)
{
    int fd;
    char *line;
    int type;

    if (!data || !file_name)
        return ;
    fd = open(file_name, O_RDONLY);
    if(fd == -1)
    {
        
        print_error();
        return ;
    }
    line = get_next_line(fd);
    while (line)
    {
        remove_newline(line);
        if (line[0] != '\0')
        {
            type = get_type(line);
            if (type != 8 && type != 1)
                pars_line(line, type, data);
            //else for map
        }
        free(line);
        line = get_next_line(fd);
    }
    printf("yoyoyoy\n");
    close(fd);
} 



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

int main(int ac, char **av)
{
    t_data *data;

    if (ac != 2)
        return (print_error());
    data = ft_calloc(1, sizeof(t_data));
    if (!data)
        return (print_error());
    open_read(data, av[1]);
    printf("lalalalalalalalalalalalalal\n");
    print_parsed_header(data);
}
