/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 23:51:48 by hyeopark          #+#    #+#             */
/*   Updated: 2020/12/28 15:51:37 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strrev(char *s)
{
	int			len;
	int			i;
	char		temp;

	i = 0;
	len = ft_strlen(s);
	while (i < len / 2)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
		i++;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	char			*temp;
	unsigned int	nb;
	int				i;

	nb = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	if (!(temp = (char*)malloc(sizeof(char) * 12)))
		return (NULL);
	i = 0;
	while (1)
	{
		temp[i++] = nb % 10 + '0';
		nb /= 10;
		if (!nb)
			break ;
	}
	if (n < 0)
		temp[i++] = '-';
	while (i < 12)
		temp[i++] = 0;
	return (ft_strrev(temp));
}
