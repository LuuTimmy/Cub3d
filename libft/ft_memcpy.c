/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:40:05 by tluu              #+#    #+#             */
/*   Updated: 2022/09/21 10:50:17 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*fdest;

	str = (unsigned char *)src;
	fdest = (unsigned char *)dest;
	i = 0;
	if (dest == NULL && str == NULL)
		return (NULL);
	while (i < n)
	{
		fdest[i] = str[i];
		i++;
	}
	return (fdest);
}
