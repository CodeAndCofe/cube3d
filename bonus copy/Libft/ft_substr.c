/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:40:12 by zyahansa          #+#    #+#             */
/*   Updated: 2025/08/26 16:02:19 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
