/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:08:15 by tluu              #+#    #+#             */
/*   Updated: 2022/01/10 11:08:15 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nword(char const *s, char c)
{
	int	i;
	int	nbword;

	i = 0;
	nbword = 0;
	while (s[i])
	{
		if (s[i + 1] == '\0')
		{
			if (s[i] != c)
				nbword++;
			return (nbword);
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nbword++;
		i++;
	}
	return (nbword);
}

void	free_split(char **fstr)
{
	int	i;

	i = 0;
	while (fstr[i])
	{
		free(fstr[i]);
		i++;
	}
	free(fstr);
}

static char	**putword(char **fstr, const char *s, char c)
{
	int		nword;
	size_t	len;
	int		i;

	nword = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] != c && s[i + len] != '\0')
				len++;
			fstr[nword] = ft_substr(s, i, len);
			if (!fstr[nword])
				free_split(fstr);
			i += len;
			nword++;
		}
	}
	return (fstr);
}

char	**ft_split(char const *s, char c)
{
	char	**fstr;
	int		nbword;

	if (s == NULL)
		return (NULL);
	nbword = nword(s, c);
	fstr = (char **) malloc (sizeof (char *) * (nbword + 1));
	if (!fstr)
		return (NULL);
	fstr[nbword] = 0;
	putword(fstr, s, c);
	return (fstr);
}
