/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:59:06 by mdelforg          #+#    #+#             */
/*   Updated: 2022/09/21 15:31:12 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	invert_map(t_data *data)
{
	int		len;
	int		i;
	char	*temp;

	len = 0;
	while (data->map[len])
		len++;
	i = 0;
	while (i < len / 2)
	{
		temp = data->map[i];
		data->map[i] = data->map[len - i - 1];
		data->map[len - i - 1] = temp;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_hero	hero;
	t_move	move;
	t_libx	libx;
	t_img	img;

	if (ac != 2)
		return (1);
	ft_move_init(&data, &move);
	ft_mlx_init(&data, &libx, &img);
	data.map = parse_file(av[1], &data, &hero);
	if (!data.map)
		ft_error("Error: Map");
	ft_textures_init(&libx);
	mlx_do_key_autorepeaton(libx.mlx_ptr);
	mlx_hook(libx.mlx_win, 17, 0L, ft_close, &data);
	mlx_hook(libx.mlx_win, 2, 1L << 0, ft_key_press, &data);
	mlx_hook(libx.mlx_win, 3, 1L << 1, ft_key_release, &data);
	mlx_loop_hook(libx.mlx_ptr, ft_launch, &data);
	mlx_do_key_autorepeatoff(libx.mlx_ptr);
	mlx_loop(libx.mlx_ptr);
	return (0);
}
