/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 23:51:48 by hyeopark          #+#    #+#             */
/*   Updated: 2020/12/29 19:05:22 by hyeopark         ###   ########.fr       */
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

static int		ft_intlen(unsigned int n)
{
	int cnt;

	cnt = 0;
	while (n > 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char			*ft_itoa(int n)
{
	char			*temp;
	unsigned int	nb;
	int				i;

	nb = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	if (!(temp = (char*)malloc(sizeof(char) * (ft_intlen(nb) + 2))))
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
	temp[i] = 0;
	return (ft_strrev(temp));
}
