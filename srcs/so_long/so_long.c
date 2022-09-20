/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:41:17 by mdelforg          #+#    #+#             */
/*   Updated: 2022/08/05 23:47:12 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_so_long(int ac, char **av)
{
	t_mini		mini;
	t_sprite	sprite;

	if (ac < 2)
		ft_error_sl("Please provide the map as argument");
	else if (ac > 2)
		ft_error_sl("Please provide only one argument");
	else
	{
		sprite.img_size = 32;
		ft_check_exten(av[1]);
		mini.map = ft_map_init(av[1]);
		mini.mlx = mlx_init();
		mini.map_len = ft_strlen(mini.map[0]);
		mini.map_size = ft_map_size(mini.map);
		mini.win = mlx_new_window(mini.mlx, mini.map_len * sprite.img_size,
				mini.map_size * sprite.img_size, "so_long");
		ft_put_background(&mini, &sprite);
//		ft_put_sprites(&mini, &sprite);
//		ft_position(&mini);
		mlx_key_hook(mini.win, ft_key_hook, &mini);
		mlx_hook(mini.win, 17, 0L, ft_close_sl, &mini);
		mlx_loop(mini.mlx);
	}
	return (0);
}
