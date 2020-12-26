/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:58:05 by hyeopark          #+#    #+#             */
/*   Updated: 2020/12/25 15:31:39 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int flag;

	flag = 0;
	while (*s)
	{
		if (*s == (char)c)
			flag = 1;
		s++;
	}
	if (c == (char)0)
		return ((char*)s);
	while (*s != (char)c)
		s--;
	return (flag ? (char*)s : NULL);
}
