/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:50:24 by zyahansa          #+#    #+#             */
/*   Updated: 2025/08/25 16:21:38 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_lstadd_front(t_env **alst, t_env*new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}
