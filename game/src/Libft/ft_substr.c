/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:40:12 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:14 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

char	*substr(char *str, int *len, char c)
{
	char	*tab;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!str)
		return (NULL);
	while (str[i] != c && str[i])
		i++;
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	while (i2 < i)
	{
		tab[i2] = str[i2];
		i2++;
	}
	tab[i2] = '\0';
	*len = i;
	return (tab);
}

char	*substr1(char *str, int *len, char c)
{
	char	*tab;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!str)
		return (NULL);
	while (str[i] != c && str[i])
		i++;
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	while (i2 < i)
	{
		tab[i2] = str[i2];
		i2++;
	}
	tab[i2] = '\0';
	*len = i;
	return (tab);
}
