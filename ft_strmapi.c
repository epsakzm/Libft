/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 02:01:20 by hyeopark          #+#    #+#             */
/*   Updated: 2020/12/29 14:34:18 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*temp;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(temp = ft_strdup(s)))
		return (NULL);
	while (temp[i])
	{
		temp[i] = (*f)(i, temp[i]);
		i++;
	}
	return (temp);
}
