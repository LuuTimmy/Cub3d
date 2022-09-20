/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:55:09 by mdelforg          #+#    #+#             */
/*   Updated: 2022/08/06 00:43:54 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_key_press(int keycode, t_data *data)
{
	t_move	*move;

	move = data->move;
	if (keycode == EXIT)
		ft_close(data);
	if (keycode == UP)
		move->forward = 1;
	if (keycode == DOWN)
		move->back = 1;
	if (keycode == LEFT)
		move->left = 1;
	if (keycode == RIGHT)
		move->right = 1;
	if (keycode == L_ARROW)
		move->turn_l = 1;
	if (keycode == R_ARROW)
		move->turn_r = 1;
	return (0);
}

int	ft_key_release(int keycode, t_data *data)
{
	t_move	*move;

	move = data->move;
	if (keycode == EXIT)
		ft_close(data);
	if (keycode == UP)
		move->forward = 0;
	if (keycode == DOWN)
		move->back = 0;
	if (keycode == LEFT)
		move->left = 0;
	if (keycode == RIGHT)
		move->right = 0;
	if (keycode == L_ARROW)
		move->turn_l = 0;
	if (keycode == R_ARROW)
		move->turn_r = 0;
	return (0);
}
