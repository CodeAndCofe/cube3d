/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:38:24 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/28 15:51:07 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EX_CUB_H
#define EX_CUB_H
#include "cub.h"
#include <mlx.h>
#include <stdio.h>
#include <math.h>

typedef struct  s_pixel
{
	void    *img;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}t_pixel;


typedef struct s_mlx
{
	void    *mlx;
	void    *win_mlx;  
}t_mlx;

typedef struct  s_player
{
	t_data  *data;
	t_mlx   *mlx;
	t_pixel	*pixel;
	double  radiant;
	double  x;
	double  y;
	// movement
	int  w;
	int  s;
	int  d;
	int  a;
}	t_player;



#define		MAX_DEST 70.0
#define		P_COLOR	0xffFF00
#define		G_COLOR	0xffffff00
#define		W_COLOR	0x222222
#define		L_COLOR 0x0000FF
#define		VIEW  60.0
#define 	SPEED 0.4
#define 	WIDTH 800
#define 	HIGTH 600
#define 	OBJECT 32
void		pixels_free(t_pixel *pixels, t_mlx *mlx);
void   		draw_square(t_pixel *pixel, int i, int j, int color, int size);
int    		draw_map(t_pixel *pixel, t_mlx *new_mlx, t_player *player);
int    		render(t_player *player);
int			action(t_player *player);
void		turn(t_player	*player, int rl);
void		go_backward(t_player *player);
void		go_forward(t_player *player);
int         render(t_player *player);
void        find_player_position(t_player *player);
void        set_zero(t_player *player);
int	        action(t_player *player);
int	        event_realise(int keycode, t_player *player);
int	        event_listener(int keycode, t_player *player);
void	    my_mlx_pixel_put(t_pixel *data, int x, int y, int color);
double      degree_to_radiant(double n);




////////////texture funtction////////////////////////////////
int load_texture(t_player *player);
void init_tex_side(char **tex_side, int wall_side, t_player *player);
double get_top(double wall_height);
double get_bottom(double wall_height);
// int get_texture_pixel(char *addr, int x, int y, int line_len, int bpp);
int get_texture_pixel(char *addr, int x, int y, int line_len, int bpp, int tex_width, int tex_height);


#endif