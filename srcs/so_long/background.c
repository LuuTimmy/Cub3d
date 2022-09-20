/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:19:17 by mdelforg          #+#    #+#             */
/*   Updated: 2022/07/31 13:44:21 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_sprites(t_mini *mini, t_sprite *sprite)
{
	mini->y = 0;
	while (mini->y < mini->map_size)
	{
		mini->x = 0;
		while (mini->x < mini->map_len)
		{
			if (mini->map[mini->y][mini->x] == 'C' || mini->map[mini->y]
				[mini->x] == 'E' || mini->map[mini->y][mini->x] == 'P')
			{
				if (mini->map[mini->y][mini->x] == 'C')
					sprite->img = mlx_xpm_file_to_image(mini->mlx, COLLECTIBLE,
							&sprite->img_size, &sprite->img_size);
				else if (mini->map[mini->y][mini->x] == 'E')
					sprite->img = mlx_xpm_file_to_image(mini->mlx, OUT,
							&sprite->img_size, &sprite->img_size);
				else
					sprite->img = mlx_xpm_file_to_image(mini->mlx, HERO,
							&sprite->img_size, &sprite->img_size);
				mlx_put_image_to_window(mini->mlx, mini->win, sprite->img,
					mini->x * sprite->img_size, mini->y * sprite->img_size);
			}
			mini->x++;
		}
		mini->y++;
	}
}

void	ft_put_background(t_mini *mini, t_sprite *sprite)
{
	mini->moves = 0;
	mini->collect = 0;
	mini->y = 0;
	while (mini->y < mini->map_size)
	{
		mini->x = 0;
		while (mini->x < mini->map_len)
		{
			if (mini->map[mini->y][mini->x] == '1')
				sprite->img = mlx_xpm_file_to_image(mini->mlx, WALLS,
						&sprite->img_size, &sprite->img_size);
			else
				sprite->img = mlx_xpm_file_to_image(mini->mlx, GROUND,
						&sprite->img_size, &sprite->img_size);
			mlx_put_image_to_window(mini->mlx, mini->win, sprite->img,
				mini->x * sprite->img_size, mini->y * sprite->img_size);
			mini->x++;
		}
		mini->y++;
	}
}
