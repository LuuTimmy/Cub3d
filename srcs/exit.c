/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:07:48 by mdelforg          #+#    #+#             */
/*   Updated: 2022/08/10 18:01:52 by mdelforg         ###   ########.fr       */
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

void	ft_free_txtr(t_libx *libx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(libx->mlx_ptr, libx->txtr[i].ptr);
		i++;
	}
	return ;
}

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
	return ;
}

int	ft_close(t_data *data)
{
	t_libx	*libx;

	libx = data->libx;
	ft_free_txtr(libx);
	mlx_destroy_image(libx->mlx_ptr, libx->img->ptr);
	ft_free_tab(data->map);
	mlx_do_key_autorepeatoff(libx->mlx_ptr);
	mlx_destroy_window(libx->mlx_ptr, libx->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}
