/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:54:20 by tluu              #+#    #+#             */
/*   Updated: 2022/01/14 10:34:00 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	if (c == 0 && n == 0)
		return (NULL);
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		i++;
	}
	if ((unsigned char)c == '\0')
		return (str);
	return (NULL);
}
