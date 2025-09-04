/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:08:38 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/02 17:11:03 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"


int close_window(t_mlx *vars)
{
    mlx_destroy_window(vars->mlx, vars->win_mlx);
    exit(0);
    return (0);   
}

void    draw_map(t_pixel *pixel, t_mlx *new_mlx, t_data *data)
{
    t_pixel *wlk;
    int     i;
    int     j;
    // static  int f;

    wlk = pixel;
    i = 0;
    j = 0;

    while (i < 8)
    {
        if (data->maps[i][j] == '1')
        {
            my_square(new_mlx, wlk, 10, 0x00FF0000);
            if (wlk->img == NULL)
                printf("yes\n");
            mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, pixel->img, j * 10, i * 10);
        }
        if (data->maps[i + 1])
        {
            wlk = new_pixel(wlk);
            if (wlk == NULL)
                return ;
            wlk = wlk->next;
        }
        i++;
    }
}


void    start(t_data *data)
{
    t_mlx   new_mlx;
    t_pixel *pixel;

    int i = 0;
    int j = 0;
    while (data->maps[i])
    {
        j  = 0;
        while (data->maps[i][j])
        {
            printf("%c", data->maps[i][j]);
            j++;
        }
        i++;
    }
    printf("end\n");
    pixel = malloc(sizeof (t_pixel));
    if (!pixel)
        return ;
    new_mlx.mlx = mlx_init();
    new_mlx.win_mlx = mlx_new_window(new_mlx.mlx, 1920, 1080, "CUB3d");
    // draw_map(pixel, &new_mlx, data);
    mlx_hook(new_mlx.win_mlx, 17, 0, close_window, &new_mlx);
    mlx_loop(new_mlx.mlx);
}
