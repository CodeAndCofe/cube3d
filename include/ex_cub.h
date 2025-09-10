/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:38:24 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/09 21:40:49 by aferryat         ###   ########.fr       */
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
	struct  s_pixel *next;
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
	double  degre;
	int  x;
	int  y;
	// movement
	int  w;
	int  s;
	int  d;
	int  a;
}t_player;

int			draw_line(t_player *player);
void    	line(t_pixel *data, int size, int color, t_player *player);
int    		render(t_player *player);
int			action(t_player *player);
void		turn(t_player	*player, int rl);
void		go_backward(t_player *player);
void		go_forward(t_player *player);
int         render(t_player *player);
void        pixels_free(t_pixel *pixels);
int    		draw_map(t_mlx *new_mlx, t_player *player);
void        find_player_position(t_player *player);
void        set_zero(t_player *player);
int	        action(t_player *player);
int	        event_realise(int keycode, t_player *player);
void        player_pixel(t_mlx *new_mlx, t_pixel *data, int size, int color);
int	        event_listener(int keycode, t_player *player);
t_pixel     *draw_object(t_player *player, int i , int j, t_mlx *new_mlx);
t_pixel     *new_pixel(t_pixel *pixel);
void        my_square(t_mlx *new_mlx, t_pixel *data, int size, int color);
void	    my_mlx_pixel_put(t_pixel *data, int x, int y, int color);
double      degree_to_radiant(double n);
#endif