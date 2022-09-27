/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:19:10 by tluu              #+#    #+#             */
/*   Updated: 2022/01/14 09:50:27 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putnbrb(int i)
{
	int	len;

	len = 1;
	if (i <= -2147483648)
	{
		len = 11;
		return (len);
	}
	if (i < 0)
	{
		len++;
		i *= -1;
	}
	while (i >= 10)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

static int	intchar(int len)
{
	int	i;

	i = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
			i *= 10;
			len--;
	}
	return (i);
}

static char	*fstr(int n, int len, char *str)
{
	int		len2;
	int		i;

	len2 = len;
	i = 0;
	if (n < 0)
	{
		n *= -1;
		str[i] = '-';
		i++;
		len--;
	}
	while (i < len2)
	{
		str[i] = (n / intchar(len)) % 10 + '0';
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = putnbrb(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *) malloc (sizeof (char) * (len + 1));
	if (!str)
		return (NULL);
	str = fstr(n, len, str);
	return (str);
}
