/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:47:22 by mdelforg          #+#    #+#             */
/*   Updated: 2022/08/10 17:16:54 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_raycast(t_data *data, t_hero *hero)
{
	int		x;
	t_rcst	rcst;

	x = 0;
	while (x < WIDTH)
	{
		ft_rcst_init(x, hero, &rcst);
		ft_rcst_delta(&rcst);
		ft_rcst_side(&rcst, hero);
		ft_rcst_trace(x, &rcst, data);
		ft_camera_init(&rcst);
		ft_put_texture(x, &rcst, data);
		x++;
	}
	return (0);
}

void	ft_update_pos(t_data *data, t_move *move)
{
	if (move->forward)
		ft_move_player_straight(UP, data, data->hero);
	if (move->back)
		ft_move_player_straight(DOWN, data, data->hero);
	if (move->left)
		ft_move_player_side(LEFT, data, data->hero);
	if (move->right)
		ft_move_player_side(RIGHT, data, data->hero);
	if (move->turn_l)
		ft_turn_player(L_ARROW, data->hero);
	if (move->turn_r)
		ft_turn_player(R_ARROW, data->hero);
	return ;
}

int	ft_launch(t_data *data)
{
	t_hero	*hero;
	t_libx	*libx;
	t_img	*img;

	hero = data->hero;
	libx = data->libx;
	img = libx->img;
	ft_update_pos(data, data->move);
	ft_raycast(data, hero);
	mlx_put_image_to_window(libx->mlx_ptr, libx->mlx_win, img->ptr, 0, 0);
	return (0);
}
