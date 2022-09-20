/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:02:00 by mdelforg          #+#    #+#             */
/*   Updated: 2021/10/12 14:22:04 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = malloc(size * count);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (count * size));
	return (&tab[0]);
}
