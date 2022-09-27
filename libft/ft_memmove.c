/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:40:34 by tluu              #+#    #+#             */
/*   Updated: 2022/01/14 10:38:01 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*fdest;
	size_t			i;

	str = (unsigned char *)src;
	fdest = (unsigned char *)dest;
	i = 0;
	if (fdest == NULL && str == NULL)
		return (NULL);
	if (fdest > str)
	{
		while (n-- > 0)
		{
			fdest[n] = str[n];
		}
	}
	else
	{
		while (i < n)
		{
			fdest[i] = str[i];
			i++;
		}
	}
	return (fdest);
}
