/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:59:12 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/02 12:00:59 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"


t_pixel *new_pixel(t_pixel *pixel)
{
    t_pixel *new;

    new = malloc(sizeof (t_pixel));
    if (new == NULL)
        return (NULL);
    pixel->next = new;
    return (pixel);
}