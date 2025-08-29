/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:08:38 by aferryat          #+#    #+#             */
/*   Updated: 2025/08/29 17:17:08 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"
#include "mlx.h"


int close_window(t_mlx *vars)
{
    mlx_destroy_window(vars->mlx, vars->win_mlx);
    exit(0);
    return (0);   
}



void    start()
{
    t_mlx   new_mlx;
    

    new_mlx.mlx = mlx_init();
    new_mlx.win_mlx = mlx_new_window(new_mlx.mlx, 1920, 1080, "CUB3d");
    mlx_hook(new_mlx.win_mlx, 17, 0, close_window, &new_mlx);
    mlx_loop(new_mlx.mlx);
}
