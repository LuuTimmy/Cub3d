/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:27:32 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/18 16:17:39 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}
