/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:56:50 by tluu              #+#    #+#             */
/*   Updated: 2022/09/21 10:44:58 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	verifset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		nset;
	int		nsetend;
	char	*fdest;
	int		j;

	nset = 0;
	nsetend = 0;
	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (verifset(s1[i++], set) == 1)
		nset++;
	i = ft_strlen(s1);
	while ((int)ft_strlen(s1) > nset && verifset(s1[--i], set) == 1)
		nsetend++;
	fdest = ft_substr(s1, nset, (ft_strlen(s1) - nset - nsetend));
	return (fdest);
}
