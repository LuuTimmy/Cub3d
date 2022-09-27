/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:51:54 by tluu              #+#    #+#             */
/*   Updated: 2022/01/10 10:52:15 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rest;

	rest = malloc (sizeof (t_list));
	if (rest == NULL)
		return (NULL);
	rest->content = content;
	rest->next = NULL;
	return (rest);
}
