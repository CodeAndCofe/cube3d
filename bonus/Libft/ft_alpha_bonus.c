/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:00:48 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:14 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

static int	ft_checker(char s, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t		start;
	size_t		end;
	char		*tab;
	size_t		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_checker(s1[start], set))
		start++;
	end = start;
	while (s1[end])
		end++;
	if (start == end)
		return (ft_strdup(""));
	end--;
	while (end >= start && ft_checker(s1[end], set))
		end--;
	tab = (char *)malloc((end - start + 2));
	if (!tab)
		return (NULL);
	i = 0;
	while (start <= end)
		tab[i++] = s1[start++];
	return (tab[i] = '\0', tab);
}
