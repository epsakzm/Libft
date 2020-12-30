/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:22:53 by hyeopark          #+#    #+#             */
/*   Updated: 2020/12/30 23:32:11 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_charset(char c, char charset)
{
	return (c == charset);
}

int		count_words(char const *str, char charset)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && ft_is_charset(*str, charset))
			str++;
		if (*str && !ft_is_charset(*str, charset))
		{
			count++;
			while (*str && !ft_is_charset(*str, charset))
				str++;
		}
	}
	return (count);
}

char	**ft_free(char **arr)
{
	unsigned int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	*malloc_word(char const *str, char charset)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !ft_is_charset(str[i], charset))
		i++;
	if (!(word = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (str[i] && !ft_is_charset(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**arr;

	if (!s)
		return (0);
	i = 0;
	if (!(arr = ft_calloc(count_words(s, c) + 1, sizeof(char *))))
		return (0);
	while (*s)
	{
		while (*s && ft_is_charset(*s, c))
			s++;
		if (*s && !ft_is_charset(*s, c))
		{
			arr[i] = malloc_word(s, c);
			if (!arr[i])
				return (ft_free(arr));
			i++;
			while (*s && !ft_is_charset(*s, c))
				s++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
