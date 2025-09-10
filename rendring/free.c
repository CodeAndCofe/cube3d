/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:22:14 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/09 22:37:56 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

void    pixels_free(t_pixel *pixels)
{
    t_pixel *temp;

    temp = pixels->next;
    while (temp)
    {
        free(pixels);
        pixels = temp;
        temp = temp->next;
    }
    free(pixels);
}