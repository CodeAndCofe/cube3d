/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:38:24 by aferryat          #+#    #+#             */
/*   Updated: 2025/10/24 17:49:09 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_CUB_H
# define EX_CUB_H
# include "cub.h"
# include <mlx.h>
# include <math.h>

typedef struct s_wall_info
{
	double	height;
	int		id;
}	t_wall_info;

typedef struct s_pixel
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_pixel;

typedef struct s_mini_data
{
	int	color;
	int	size;
}	t_mini_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win_mlx;
}	t_mlx;

typedef struct s_wall
{
	double	top;
	double	bottom;
	double	tex_step;
	double	tex_pos;
	double	tex_height;
	char	*text_side;
	int		text_x;
	int		text_y;
	int		color;
	int		x;
}	t_wall;

typedef struct s_mini
{
	int		map_y;
	int		map_x;
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	char	tile;
}	t_mini;

typedef struct s_player
{
	t_pixel	*new_pixel;
	t_data	*data;
	t_mlx	*mlx;
	t_pixel	*pixel;
	double	hit_point;
	int		wall_side;
	double	radiant;
	double	x;
	double	y;
	double	distance;
	double	hitx;
	double	hity;
	double	v_interx;
	double	v_intery;
	double	h_interx;
	double	h_intery;
	int		direction;
	int		h_wall;
	int		v_wall;
	double	v_wall_hit_x;
	double	v_wall_hit_y;
	double	h_wall_hit_x;
	double	h_wall_hit_y;
	double	v_xsteps;
	double	v_ysteps;
	double	h_xsteps;
	double	h_ysteps;
	int		facing_down;
	int		facing_up;
	int		facing_right;
	int		facing_left;
	int		p_pos_x;
	int		p_pos_y;
	int		w;
	int		s;
	int		d;
	int		a;
	int		left;
	int		right;
	int		is_door;
	int		line_len;
	int		bpp;
}	t_player;

# define COLLISION_RADIUS 0.2
# define MINI_RADIUS 6 
# define M_SIZE 170
# define TILE_SIZE 12
# define NORTH 0
# define WEAST 1
# define SOTH  2
# define EAST  3
# define MAX_DEST 70.0
# define VIEW  60.0
# define SPEED 0.18
# define WIDTH 800
# define HEIGHT 500
# define OBJECT 24
# define WIDTH_PER_PIXEL 1.5
# define M_INT_MAX 2147483646

int		free_text(t_player *player);
void	pixels_free(t_pixel *pixels, t_mlx *mlx);
int		draw_map_bonus(t_pixel *pixel, t_mlx *new_mlx,
			t_player *player, t_pixel *new_pixel);
int		draw_map(t_pixel *pixel, t_mlx *new_mlx, t_player *player);
int		render(t_player *player);
void	turn(t_player	*player, int rl);
void	go_backward(t_player *player);
void	go_forward(t_player *player);
int		render(t_player *player);
void	find_player_position(t_player *player);
void	set_zero(t_player *player);
int		action(t_player *player);
int		event_realise(int keycode, t_player *player);
int		event_listener(int keycode, t_player *player);
void	pixel_putter(t_pixel *data, int x, int y, int color);
double	degree_to_radiant(double n);
void	vertical_ray(t_player *player);
void	the_intersects_vertical(double ray_angle, t_player *player);
void	player_view(t_pixel *pixel, t_player *player);
double	reset_radiant(double angle);
void	where_is_facing(double angle, t_player *player);
int		the_limit(int x, int y);
int		cordinate_limit(int x, int y, t_data *data);
void	the_intersects_horizontal(double ray_angle, t_player *player);
void	horizontal_ray(t_player *player);
void	draw_ray(t_pixel *pixel, int ray_x, int ray_y, int color);
void	drawing_wall(t_player *player, t_pixel *pixel, int i, double ray_angle);
double	calculate_distance(double px, double py, double dx, double dy);
void	exit_all(t_player *player, int f);
int		is_wall(t_data *data, double x, double y);

int		load_texture(t_player *player);
int		load_text_animation(t_player *player);
void	init_tex_side(char **tex_side, int wall_side, t_player *player);
double	get_top(double wall_height);
double	get_bottom(double wall_height);
int		get_texture_pixel(char *addr, int x, int y, t_player *player);

void	draw_ceilling(double top, t_pixel *pixel, int x, t_player *player);
void	draw_floor(double bottom, t_pixel *pixel, int x, t_player *player);
int		get_text_x(t_player *player, double hit_point);
int		get_text_y(double tex_height, double text_pos, t_player *player);
int		mouse_move(int x, int y, void *param);
int		event(int keycode, t_player *player);
int		open_door(int keycode, void *param);
void	display_animation(t_player *player, int *counter);
int		load_door(t_player *player);
int		get_pixel_color(char *text_side, int text_x,
			int text_y, t_player *player);
int		door_next_space(t_data *data, int x, int y);
int		animation_click(int button, int x, int y, t_player *player);

#endif