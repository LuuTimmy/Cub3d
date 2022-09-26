/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:29:31 by tluu              #+#    #+#             */
/*   Updated: 2022/09/26 10:59:12 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	put_info(char *line, char **info, int ismap, t_data *data)
{
	int		i;
	char	**new_line;

	new_line = ft_split(line, 32);
	if (!new_line)
		return (ft_error_int("Error: malloc failed", -2));
	if (ft_strncmp(new_line[0], "\n", 2))
	{
		i = 0;
		while (i < 6)
		{
			if (!ft_strncmp(new_line[0], info[i], ft_strlen(info[i]) + 1))
			{
				if (!parse_texture(new_line[1], line, info[i], data->libx))
					return (-2);
				ismap = 1;
				break ;
			}
			else
				ismap = -1;
			i++;
		}
	}
	free_split(new_line);
	return (ismap);
}

char	*putmap2(char *line, char *fline, int *t)
{
	char	*fstr;

	if (ft_strlen(line) == 1)
		*t = 1;
	else if (*t == 1 && ft_strlen(line) - count_char(line, 32) > 1)
		*t = -1;
	fstr = ft_strjoin(fline, line);
	free(line);
	free (fline);
	fline = fstr;
	if (*t == -1)
		return (ft_error_char("Error: map need to be closed"));
	if (!fline)
		return (ft_error_char("Error: malloc failed"));
	return (fline);
}

char	**putmap(int fd, char *fline)
{
	int		t;
	int		temp;
	char	*line;
	char	**map_temp;

	t = 0;
	temp = 1;
	line = 0;
	while (line || temp)
	{
		temp = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		fline = putmap2(line, fline, &t);
		if (!fline)
			return (NULL);
	}
	map_temp = ft_split(fline, '\n');
	free(fline);
	if (!map_temp)
		return (ft_error_char("Error: malloc failed"));
	return (map_temp);
}

int	verif_info(t_libx *libx)
{
	if (!libx->txtr_w_north || !libx->txtr_w_south
		|| !libx->txtr_w_west || !libx->txtr_w_east)
		return (0);
	if (!libx->texture_floor || !libx->texture_ceiling)
		return (0);
	return (1);
}

char	**search_map_info(int fd, t_data *data, char **info)
{
	char	*line;
	int		ismap;
	char	**map_temp;

	ismap = 1;
	while (ismap >= 0)
	{
		line = get_next_line(fd);
		if (!line)
			return (ft_error_char("Error: miss information"));
		ismap = put_info(line, info, ismap, data);
		if (ismap >= 0 || ismap == -2)
			free(line);
		if (ismap == -2)
			return (NULL);
	}
	if (!verif_info(data->libx))
		return (ft_error_char("Error: miss information"));
	map_temp = putmap(fd, line);
	if (!map_temp)
		return (NULL);
	return (map_temp);
}
