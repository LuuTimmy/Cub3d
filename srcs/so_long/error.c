/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:58:18 by mdelforg          #+#    #+#             */
/*   Updated: 2022/08/05 18:17:17 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_tab_sl(char **tab, size_t i)
{
	i++;
	while (i)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return ;
}

void	ft_error_sl(char *msg)
{
	write(2, "Error\n", 6);
	printf("--%s\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_map_error(char *msg, char **map)
{
	ft_free_tab_sl(map, ft_map_size(map));
	write(2, "Error\n", 6);
	printf("--%s\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_error_tab_str(char *msg, char *str, char **map)
{
	free(str);
	ft_free_tab_sl(map, ft_map_size(map));
	write(2, "Error\n", 6);
	printf("--%s\n", msg);
	exit(EXIT_FAILURE);
}
