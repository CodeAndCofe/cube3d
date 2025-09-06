/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:08:38 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/06 15:48:36 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"


int close_window(t_mlx *vars)
{
    mlx_destroy_window(vars->mlx, vars->win_mlx);
    exit(0);
    return (0);   
}


t_pixel    *draw_map(t_pixel *pixel, t_mlx *new_mlx, t_player *player)
{
    t_pixel *wlk;
    int     i;
    int     j;

    wlk = pixel;
    i = 0;
    j = 0;
    while (player->data->maps[i])
    {
        j = 0;
        while (player->data->maps[i][j])
        {
            wlk->next = draw_object(player, i, j, new_mlx);
            wlk = wlk->next;
            if (wlk == NULL)
                return (NULL);// free pixels!
            mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, wlk->img, j * 51, i * 51);
            j++;
        }
        i++;
    }
    wlk->next = NULL;
    pixel = pixel->next;
    return (pixel);
}



void    start(t_data *data)
{
    t_player    player;
    t_mlx       new_mlx;
    t_pixel     *pixel;// fucose on this in fauture!

    player.data = data;
    pixel = malloc(sizeof (t_pixel));
    if (!pixel)
        return ;
    new_mlx.mlx = mlx_init();
    new_mlx.win_mlx = mlx_new_window(new_mlx.mlx, 1920, 1080, "CUB3d");
    pixel = draw_map(pixel, &new_mlx, &player);
    // free_pixel and set to NULL;
    while (pixel->next != NULL)
        pixel = pixel->next;
    // just the test
    player.pixel = pixel;
    player.mlx = &new_mlx;
    mlx_key_hook(new_mlx.win_mlx, event_listener, &player);
    mlx_hook(new_mlx.win_mlx, 17, 0, close_window, &new_mlx);
    mlx_loop(new_mlx.mlx);
}
