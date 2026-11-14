/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:44:46 by zyahansa          #+#    #+#             */
/*   Updated: 2025/10/20 13:44:14 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static int	count_len_word(const char *s, int start, char c)
{
	int	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*fill_word(const char *s, int *i, char c)
{
	int		length;
	char	*res;
	int		j;

	length = count_len_word(s, *i, c);
	res = malloc(length + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (j < length)
		res[j++] = s[(*i)++];
	res[j] = '\0';
	return (res);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		word_index;
	char	**tab;

	i = 0;
	word_index = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[word_index] = fill_word(s, &i, c);
			if (!tab[word_index])
				return (NULL);
			word_index++;
		}
		else
			i++;
	}
	tab[word_index] = NULL;
	return (tab);
}
