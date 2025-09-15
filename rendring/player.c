/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:36:44 by aferryat          #+#    #+#             */
/*   Updated: 2025/09/14 13:36:31 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_cub.h"

double  degree_to_radiant(double n)
{
    return (n * ((M_PI) / 180.0));   
}

void    set_zero(t_player *player)
{
    player->w = 0;
    player->d = 0;
    player->a = 0;
    player->s = 0;
    player->x = 0;
    player->y = 0;
    player->radiant = 0;
}

void    set_player_position_and_degree(t_player *player, char c, int j , int i)
{
    player->x = j;
    player->y = i;
    if (c == 'N')
        player->radiant = degree_to_radiant(270);
    else if (c == 'S')
        player->radiant = degree_to_radiant(180);
    else if (c == 'W')
        player->radiant = degree_to_radiant(90);
    else if (c == 'E')
        player->radiant = degree_to_radiant(0);
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
            if (player->data->maps[i][j] == 'N' || player->data->maps[i][j] == 'S'
                || player->data->maps[i][j] == 'E' || player->data->maps[i][j] == 'W')
            {
                set_player_position_and_degree(player, player->data->maps[i][j], j, i);
                return ;
            }
            j++;
        }
        i++;
    }
}
