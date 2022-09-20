/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:09:52 by mdelforg          #+#    #+#             */
/*   Updated: 2022/08/05 23:46:55 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_sl(t_mini *mini)
{
	mlx_destroy_window(mini->mlx, mini->win);
	ft_free_tab_sl(mini->map, ft_map_size(mini->map));
	exit(0);
	return (0);
}

void	ft_player_move(t_mini *mini, t_sprite *sprt, int x, int y)
{
	sprt->img_p = mlx_xpm_file_to_image(mini->mlx, HERO, &sprt->img_size,
			&sprt->img_size);
	sprt->img_g = mlx_xpm_file_to_image(mini->mlx, GROUND, &sprt->img_size,
			&sprt->img_size);
	sprt->img_e = mlx_xpm_file_to_image(mini->mlx, OUT, &sprt->img_size,
			&sprt->img_size);
	if (mini->map[y][x] == 'C')
		mini->collect--;
	if (mini->map[y][x] == 'E')
		mini->map[y][x] = 'G';
	else
		mini->map[y][x] = 'P';
	mlx_put_image_to_window(mini->mlx, mini->win, sprt->img_p, x * 32, y * 32);
	mlx_put_image_to_window(mini->mlx, mini->win, sprt->img_g, mini->x * 32,
		mini->y * 32);
	if (mini->map[mini->y][mini->x] == 'G')
	{
		mlx_put_image_to_window(mini->mlx, mini->win, sprt->img_e,
			mini->x * 32, mini->y * 32);
		mini->map[mini->y][mini->x] = 'E';
	}
	mini->x = x;
	mini->y = y;
	mini->moves++;
	return ;
}

int	ft_key_hook(int keycode, t_mini *mini, t_sprite *sprite)
{
	int	past_moves;

	past_moves = mini->moves;
	if (keycode == 53)
		ft_close_sl(mini);
	else if (keycode == 13 && mini->map[mini->y - 1][mini->x] != '1')
		ft_player_move(mini, sprite, mini->x, mini->y - 1);
	else if (keycode == 0 && mini->map[mini->y][mini->x - 1] != '1')
		ft_player_move(mini, sprite, mini->x - 1, mini->y);
	else if (keycode == 1 && mini->map[mini->y + 1][mini->x] != '1')
		ft_player_move(mini, sprite, mini->x, mini->y + 1);
	else if (keycode == 2 && mini->map[mini->y][mini->x + 1] != '1')
		ft_player_move(mini, sprite, mini->x + 1, mini->y);
	if (mini->map[mini->y][mini->x] == 'G' && mini->collect == 0)
		ft_close_sl(mini);
	if (past_moves != mini->moves)
		printf("Mooncake has done %d moves\n", mini->moves);
	return (0);
}

void	ft_position(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while (mini->map[i])
	{
		j = 0;
		while (mini->map[i][j])
		{
			if (mini->map[i][j] == 'P')
			{
				mini->y = i;
				mini->x = j;
			}
			else if (mini->map[i][j] == 'C')
				mini->collect++;
			j++;
		}
		i++;
	}
	return ;
}
