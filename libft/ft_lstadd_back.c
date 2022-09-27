/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:08:44 by tluu              #+#    #+#             */
/*   Updated: 2022/01/10 17:43:40 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*i;

	i = 0;
	if (alst == NULL || new == NULL)
		return ;
	else if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	i = ft_lstlast(*alst);
	i->next = new;
}
