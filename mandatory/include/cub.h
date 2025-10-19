/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:39:00 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/18 18:06:08 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB
# define CUB

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

char	*get_next_line(int fd);
char	*ft_strdup1(char *s1);
char	*ft_strchr1(char *s, int c);
char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_strlen1(const char *s);
char	*ft_strcpy1(char *dest, char *src);

typedef struct s_found
{
	int found_so;
	int found_no;
	int found_we;
	int found_ea;
	int found_f;
	int found_c;
	int found_door;

}   t_found;

typedef struct s_data
{
	char **maps;
	int map_start;
	int pre_type;
	int map_lines;
	int map_index;
	char *no_path;
	char *so_path;
	char *we_path;
	char *ea_path;


	int f_color;
	int c_color;
	int height;
	int witth;
	int start_pos_x;
	int start_pos_y;
	int palyer_direction;
	struct s_found  found;
	void *no_texture;
	void *so_texture;
	void *we_texture;
	void *ea_texture;

	char *no_address;
	char *so_address;
	char *we_address;
	char *ea_address;

	int tex_with;
	int tex_height;    

	int tex_bpp;       // Texture bits per pixel
	int tex_line_len;  // Texture line length in bytes  
	int tex_endian;

	char *door_tex;
	int door_tex_width;
	int door_tex_height;
	int door_tex_bpp;
	int door_tex_line_len;
	int door_tex_endian;
}   t_data;


int		main(int ac, char **av);
int		open_read(t_data *data, char *file_name, int flag);
int		check_file(char *line);
int		pars_line(char *line, t_data *data);
int		store_data(int type, t_data *data, char *path);
int		is_valid_extension(char *path, char *name);
void	remove_newline(char *line);
int		print_error(void);
void	*ft_calloc(size_t count, size_t size);
char	*get_nex_line(int fd);
int		convert_to_rgb(char *color);
int		count_word(char **holder);
void	init_data(t_data *data);
int		parsing_part(t_data *data, char *file_name);
int		valid_file(t_data *data);
int		pars_map(char *line, t_data *data);
int		pars_line_helper(char *line, int *type, char **path, t_data *data);
int		valid_map(t_data *data);
int		valid_chars(char *line, int *player, int flag);
int		all_walls(char *line);
int		map_closed(t_data *data);
int		check_num(char *num);
int		valid_space(char **holder);
int		map_start(t_data *data, int type);
int		init_map(t_data *data);
void	free_data(t_data *data);
void	free_holder(char **holder);
void	*remove_space(char *line);
void	extract_path(char *line, int *i, int *j);
int		ft_isspace(char c);
int		start_parsing(char *line, t_data *data, int fd, int flag);
int		store_no_so_path(int type, t_data *data, char *path);
int		store_we_ea_path(int type, t_data *data, char *path);
int		store_f_c_path(int type, t_data *data, char *path);
void	extract_rgb(char **holder, int *r, int *g, int *b);
int 	get_type(char *line);
int		first_last_line(int x, t_data *data);
int		map_closed_helper(int x, int y, t_data *data);
int		check_surrounded(t_data *data, int x, int y);
int		is_out_of_bounds(t_data *data, int x, int y);
int		zero_next_to_space(t_data *data, int x, int y);

////////////////////////////libft////////////////////////////

int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strrchr(const char *s, int c);
char	*substr(char *str, int *len, char c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
char	*ft_strtrim(char *s1, char *set);
void	freemyhomie(char **str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
char	*ft_itoa(int n);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int    start(t_data *data);
int    start();

#endif