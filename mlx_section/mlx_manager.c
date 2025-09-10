/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:08:38 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/08 08:36:26 by aferryat         ###   ########.fr       */
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
    wlk->next = malloc(sizeof (t_pixel));
    if (wlk == NULL)
        return (NULL);
    wlk = wlk->next;
    player_pixel(new_mlx, wlk, 20, 0xFF00FF);
    mlx_put_image_to_window(new_mlx->mlx, new_mlx->win_mlx, wlk->img, player->x, player->y);
    wlk->next = NULL;
    pixel = pixel->next;
    return (pixel);
}

void    find_player_position(t_player *player)
{
    int i = 0;
    int j = 0;
    while (player->data->maps[i])
    {
        j = 0;
        while (player->data->maps[i][j])
        {
            if (player->data->maps[i][j] == 'N')
            {
                player->degre = degree_to_radiant(0);
                player->x = j * 51 + 15;
                player->y = i * 51 + 15;
                return ;
            }
            j++;
        }
        i++;
    }
}

int    render(t_player *player)
{
    // mlx_key_hook(player->mlx->win_mlx, event_listener, player);
    action(player);
    mlx_hook(player->mlx->win_mlx, 17, 0, close_window, player->mlx);
    return (0);
}

void    start(t_data *data)
{
    t_player    player;
    t_mlx       new_mlx;
    t_pixel     *pixel;// fucose on this in fauture!

    player.data = data;
    set_zero(&player);
    find_player_position(&player);
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
    mlx_hook(player.mlx->win_mlx, 2, 1L<<0, event_listener, &player);
    mlx_hook(player.mlx->win_mlx, 3, 1L<<1, event_realise, &player);
    mlx_loop_hook(new_mlx.mlx, render, &player);
    mlx_loop(new_mlx.mlx);
}
