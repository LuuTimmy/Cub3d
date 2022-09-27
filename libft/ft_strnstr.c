/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:45:09 by tluu              #+#    #+#             */
/*   Updated: 2022/01/05 17:45:30 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str2;
	char	*to_find2;

	i = 0;
	j = 0;
	str2 = (char *)str;
	to_find2 = (char *)to_find;
	if (*to_find2 == 0)
		return (str2);
	while (str2[i] != '\0')
	{	
		j = 0;
		while (str2[i + j] == to_find2[j] && (i + j) < len)
		{
			if (to_find2[j + 1] == '\0')
				return (str2 + i);
			j++;
		}
		i++;
	}
	return (0);
}
