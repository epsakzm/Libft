/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:22:53 by hyeopark          #+#    #+#             */
/*   Updated: 2020/12/31 01:44:15 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free(char **arr)
{
	size_t i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	if (arr)
		free(arr);
	return (NULL);
}

static int		count_words(char const *s, char c)
{
	int		cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
	}
	return (cnt);
}

static char		*next_word(char const *s, char c)
{
	size_t		i;
	char		*word;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	if (!(word = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		++i;
	}
	word[i] = 0;
	return (word);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	char	**array;

	if (!s)
		return (NULL);
	if (!(array = ft_calloc(count_words(s, c) + 1, sizeof(char*))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
		{
			if (!(array[i] = next_word(s, c)))
				return (ft_free(array));
			++i;
			while (*s && *s != c)
				++s;
		}
	}
	array[i] = NULL;
	return (array);
}
