/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeopark <hyeopark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:17:09 by hyeopark          #+#    #+#             */
/*   Updated: 2020/12/27 22:16:32 by hyeopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	temp = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
		{
			while (temp)
			{
				new = temp->next;
				(*del)(temp->content);
				free(temp);
				temp = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&temp, new);
		lst = lst->next;
	}
	return (temp);
}
