/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:58:05 by hyeopark          #+#    #+#             */
/*   Updated: 2020/12/29 19:13:06 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	if (!c)
		return ((char*)s + ft_strlen(s));
	else if (!(*s))
		return (NULL);
	temp = (char*)s;
	while (*temp)
		temp++;
	while (--temp && *temp != c)
	{
		if (s == temp)
			return (NULL);
	}
	return (temp);
}
