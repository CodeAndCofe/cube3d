/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:22:14 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/10 20:31:05 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void    pixels_free(t_pixel *pixels, t_mlx *mlx)
{
    mlx_destroy_image(mlx->mlx, pixels->img);
    free(pixels);
}