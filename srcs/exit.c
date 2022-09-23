/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:07:48 by mdelforg          #+#    #+#             */
/*   Updated: 2022/09/23 13:07:12 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
	return ;
}

void	*ft_error_char(char *str)
{
	printf("%s\n", str);
	return (NULL);
}

int	ft_error_int(char *str, int i)
{
	printf("%s\n", str);
	return (i);
}

int	ft_close(t_data *data)
{
	t_libx	*libx;

	libx = data->libx;
	mlx_destroy_image(libx->mlx_ptr, libx->img->ptr);
	ft_free_tab(data->map);
	mlx_do_key_autorepeatoff(libx->mlx_ptr);
	mlx_destroy_window(libx->mlx_ptr, libx->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}
