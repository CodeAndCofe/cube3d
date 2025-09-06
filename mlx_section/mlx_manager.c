/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:08:38 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/06 13:00:48 by aferryat         ###   ########.fr       */
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

    wlk = pixel;
    i = 0;
    j = 0;
    while (data->maps[i])
    {
        j = 0;
        while (data->maps[i][j])
        {
            
            if (data->maps[i][j] == '1')
            {
                my_square(new_mlx, wlk, 50, 0x00FF0000);
                if (wlk->img == NULL)
                    printf("NULL\n");
            }
            else if (data->maps[i][j] == '0')
            {
                my_square(new_mlx, wlk, 50, 0x0000FF00);
                if (wlk->img == NULL)
                    printf("NULL\n");
            }
            else
            {
                my_square(new_mlx, wlk, 50, 0x000000FF);
                if (wlk->img == NULL)
                    printf("NULL\n");
            }
            mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, wlk->img, j * 51, i * 51);
            if (data->maps[i][j + 1])
            {
                wlk = new_pixel(wlk);
                if (wlk == NULL)
                    return ;
                wlk = wlk->next;
            }
            j++;
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

    
    pixel = malloc(sizeof (t_pixel));
    if (!pixel)
        return ;
    new_mlx.mlx = mlx_init();
    new_mlx.win_mlx = mlx_new_window(new_mlx.mlx, 1920, 1080, "CUB3d");
    draw_map(pixel, &new_mlx, data);
    // event_listener(pixel, new_mlx);
    mlx_hook(new_mlx.win_mlx, 17, 0, close_window, &new_mlx);
    mlx_loop(new_mlx.mlx);
}
