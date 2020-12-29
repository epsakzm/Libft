/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:25:32 by hyeopark          #+#    #+#             */
/*   Updated: 2020/12/29 18:58:39 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*temp;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	if (i == j + 1)
	{
		temp = (char*)malloc(1);
		temp[0] = 0;
		return (temp);
	}
	while (s1[j] && ft_strchr(set, s1[j]) && j >= 0)
		j--;
	temp = ft_substr(s1, i, j - i + 1);
	return (temp);
}
