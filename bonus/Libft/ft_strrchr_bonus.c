/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:49:06 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:14 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

char	*ft_strrchr(const char *s, int c)
{
	char	target;
	int		len;

	target = (char)c;
	len = ft_strlen(s);
	if (target == '\0')
		return ((char *)&s[len]);
	while (len--)
	{
		if (s[len] == target)
			return ((char *)&s[len]);
	}
	return (NULL);
}
