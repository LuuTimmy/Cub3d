/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:30:31 by tluu              #+#    #+#             */
/*   Updated: 2022/01/10 14:19:14 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rest;
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	rest = NULL;
	while (lst != NULL)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&rest, del);
			return (NULL);
		}
		ft_lstadd_back(&rest, temp);
		lst = lst->next;
	}
	return (rest);
}
