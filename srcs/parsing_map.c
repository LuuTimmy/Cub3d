/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:29:27 by tluu              #+#    #+#             */
/*   Updated: 2022/09/26 11:05:14 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	verif_map2(t_data *d, unsigned int i, unsigned int j, unsigned int len)
{
	if (!verifset(d->map[i][j], " 01NSEW"))
		return (ft_error_int("Error: wrong character", 0));
	if ((i == 0 || j == 0 || i == len - 1 || j == ft_strlen(d->map[i]) - 1)
		&& !verifset(d->map[i][j], " 1"))
		return (ft_error_int("Error: The card must be closed with walls", 0));
	if (d->map[i][j] == ' ')
	{
		if (i > 0 && !verifset(d->map[i - 1][j], " 1"))
			return (ft_error_int("Error: map need to be close", 0));
		if (i < len - 1 && !verifset(d->map[i + 1][j], " 1"))
			return (ft_error_int("Error: map need to be close", 0));
		if (j > 0 && !verifset(d->map[i][j - 1], " 1"))
			return (ft_error_int("Error: map need to be close", 0));
		if (j < ft_strlen(d->map[i]) - 1 && !verifset(d->map[i][j + 1], "1 "))
			return (ft_error_int("Error: map need to be close", 0));
	}
	return (1);
}

int	verif_map(t_data *data, t_hero *hero, int len)
{
	int	i;
	int	j;
	int	isplayer;

	i = 0;
	isplayer = 0;
	while (data->map[i])
	{	
		j = 0;
		while (data->map[i][j])
		{
			if (!verif_map2(data, (size_t)i, (size_t)j, (size_t)len))
				return (0);
			if (data->map[i][j] == 32)
				data->map[i][j] = '1';
			isplayer += put_hero(data, hero, i, j);
			j++;
		}
		i++;
	}
	if (!isplayer)
		return (ft_error_int("Error: not player in the map", 0));
	return (1);
}

int	put_map2(t_data *d, char **map_temp, int len, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		d->map[i] = (char *)malloc(sizeof(char) * len + 1);
		if (!d->map[i])
			return (ft_error_int("Error: wrong malloc", 0));
		d->map[i][len] = '\0';
		ft_memset(d->map[i], 32, len);
		if (map_temp[i][ft_strlen(map_temp[i]) - 1] == '\n')
			ft_strlcpy_cub(d->map[i], map_temp[i], ft_strlen(map_temp[i]));
		else
			ft_strlcpy_cub(d->map[i], map_temp[i], ft_strlen(map_temp[i]) + 1);
		i++;
	}
	return (1);
}

char	**put_map(t_data *data, char **map_temp)
{
	int		i;
	size_t	len;
	int		width;

	i = 0;
	len = 0;
	width = 0;
	while (map_temp[i])
	{
		if (ft_strlen(map_temp[i]) > len)
			len = ft_strlen(map_temp[i]);
		width++;
		i++;
	}
	data->map = (char **)malloc(sizeof(char *) * (width + 1));
	if (!data->map)
	{
		free_split(data->map);
		return (NULL);
	}
	data->map[width] = 0;
	if (!put_map2(data, map_temp, len, width))
		return (NULL);
	return (data->map);
}

void	*parsing_map(t_data *data, char **map_temp, t_hero *hero)
{
	int		len;

	len = 0;
	data->map = put_map(data, map_temp);
	if (!data->map)
	{
		free_split(map_temp);
		return (ft_error_char("Error: malloc failed"));
	}
	while (data->map[len])
		len++;
	invert_map(data);
	free_split(map_temp);
	if (!verif_map(data, hero, len))
	{
		free_split(data->map);
		return (NULL);
	}
	return (data);
}
