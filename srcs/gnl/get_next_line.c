/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:08:16 by mdelforg          #+#    #+#             */
/*   Updated: 2022/02/23 15:06:38 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_free_str(char **str)
{
	free(*str);
	*str = NULL;
	return (1);
}

static char	*ft_get_rtn(size_t i, char *tmp_str)
{
	char	*rtn_line;

	rtn_line = ft_substr_gnl(tmp_str, 0, i);
	if (!rtn_line)
		return (NULL);
	if (!*rtn_line)
	{
		free(rtn_line);
		return (NULL);
	}
	return (rtn_line);
}

static int	ft_read_buf(int fd, char **tmp_str)
{
	long	nb_crt;
	char	*buf_str;

	buf_str = ft_calloc_gnl(BUFFER_SIZE + 1);
	if (!buf_str)
		return (0);
	nb_crt = 1;
	while (nb_crt && !ft_strchr_gnl(buf_str, '\n'))
	{
		nb_crt = read(fd, buf_str, BUFFER_SIZE);
		if (nb_crt == -1)
		{
			free(buf_str);
			return (0);
		}
		buf_str[nb_crt] = '\0';
		*tmp_str = ft_strjoin_gnl(*tmp_str, buf_str, 0);
		if (!*tmp_str)
		{
			free(buf_str);
			return (0);
		}
	}
	free(buf_str);
	return (1);
}

static size_t	ft_get_i(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	size_t		i;
	char		*rtn_line;
	static char	*tmp_str;

	if ((fd < 0 || BUFFER_SIZE < 1) && ft_free_str(&tmp_str))
		return (NULL);
	if (!ft_strchr_gnl(tmp_str, '\n'))
	{
		if (!ft_read_buf(fd, &tmp_str) && ft_free_str(&tmp_str))
			return (NULL);
	}
	if (!tmp_str)
		return (NULL);
	i = ft_get_i(tmp_str);
	rtn_line = ft_get_rtn(i, tmp_str);
	if (!rtn_line && ft_free_str(&tmp_str))
		return (NULL);
	tmp_str = ft_substr_gnl(tmp_str, i, (ft_strlen_gnl(tmp_str) - i));
	if (!tmp_str)
		ft_free_str(&rtn_line);
	if (!*tmp_str)
		ft_free_str(&tmp_str);
	return (rtn_line);
}
