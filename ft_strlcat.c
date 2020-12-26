/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:57:02 by hyeopark          #+#    #+#             */
/*   Updated: 2020/12/24 22:41:00 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_i;
	size_t	src_i;

	i = 0;
	while (dst[i])
		i++;
	dst_i = i;
	src_i = 0;
	if (dst_i < dstsize)
	{
		while (src[src_i] && i < dstsize - 1)
		{
			dst[i] = src[src_i];
			i++;
			src_i++;
		}
	}
	dst[i] = 0;
	while (src[src_i])
		src_i++;
	return ((dst_i < dstsize ? dst_i : dstsize) + src_i);
}
