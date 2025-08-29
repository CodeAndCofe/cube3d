/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:58:45 by aferryat          #+#    #+#             */
/*   Updated: 2025/08/29 16:55:54 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EX_CUB_H
#define EX_CUB_H
#include "../include/cub.h"

typedef struct s_mlx
{
    void    *mlx;
    void    *win_mlx;  
}t_mlx;
    
void    add_temporary_map(t_data    *data);
#endif