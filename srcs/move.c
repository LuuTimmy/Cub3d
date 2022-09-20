/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:39:45 by mdelforg          #+#    #+#             */
/*   Updated: 2022/08/08 16:59:37 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_turn_player(int type, t_hero *hero)
{
	double	old_dir;
	double	old_plane;

	if (type == L_ARROW)
	{
		old_dir = hero->dir_x;
		hero->dir_x = (old_dir * cos(TURN)) - (hero->dir_y * sin(TURN));
		hero->dir_y = (old_dir * sin(TURN)) + (hero->dir_y * cos(TURN));
		old_plane = hero->plane_x;
		hero->plane_x = (old_plane * cos(TURN)) - (hero->plane_y * sin(TURN));
		hero->plane_y = (old_plane * sin(TURN)) + (hero->plane_y * cos(TURN));
	}
	else if (type == R_ARROW)
	{
		old_dir = hero->dir_x;
		hero->dir_x = (old_dir * cos(-TURN)) - (hero->dir_y * sin(-TURN));
		hero->dir_y = (old_dir * sin(-TURN)) + (hero->dir_y * cos(-TURN));
		old_plane = hero->plane_x;
		hero->plane_x = (old_plane * cos(-TURN)) - (hero->plane_y * sin(-TURN));
		hero->plane_y = (old_plane * sin(-TURN)) + (hero->plane_y * cos(-TURN));
	}
	return ;
}

void	ft_move_side_up(int cst, t_data *data, t_hero *hero)
{
	if (hero->dir_x >= 0)
	{
		if (data->map[(int)hero->pos_y][(int)(hero->pos_x
			+ cos(asin((float)hero->dir_y) + M_PI_2) * MOVE_SEC * cst)] == '0')
		hero->pos_x += cos(asin((float)hero->dir_y) + M_PI_2) * MOVE * cst;
		if (data->map[(int)(hero->pos_y + sin(asin((float)hero->dir_y) + M_PI_2)
				* MOVE_SEC * cst)][(int)hero->pos_x] == '0')
		hero->pos_y += sin(asin((float)hero->dir_y) + M_PI_2) * MOVE * cst;
	}
	else
	{
		if (data->map[(int)hero->pos_y][(int)(hero->pos_x
			+ cos(acos((float)hero->dir_x) + M_PI_2) * MOVE_SEC * cst)] == '0')
		hero->pos_x += cos(acos((float)hero->dir_x) + M_PI_2) * MOVE * cst;
		if (data->map[(int)(hero->pos_y + sin(acos((float)hero->dir_x) + M_PI_2)
				* MOVE_SEC * cst)][(int)hero->pos_x] == '0')
		hero->pos_y += sin(acos((float)hero->dir_x) + M_PI_2) * MOVE * cst;
	}
	return ;
}

void	ft_move_side_down(int cst, t_data *data, t_hero *hero)
{
	if (hero->dir_x < 0)
	{
		if (data->map[(int)hero->pos_y][(int)(hero->pos_x
			+ cos(acos((float)hero->dir_x * -1) - M_PI_2) * MOVE_SEC * cst)]
			== '0')
			hero->pos_x += cos(acos((float)hero->dir_x * -1) - M_PI_2)
				* MOVE * cst;
		if (data->map[(int)(hero->pos_y + sin(acos((float)hero->dir_x * -1)
					- M_PI_2) * MOVE_SEC * cst)][(int)hero->pos_x] == '0')
			hero->pos_y += sin(acos((float)hero->dir_x * -1) - M_PI_2)
				* MOVE * cst;
	}
	else
	{
		if (data->map[(int)hero->pos_y][(int)(hero->pos_x
			+ cos(asin((float)hero->dir_y) + M_PI_2) * MOVE_SEC * cst)] == '0')
		hero->pos_x += cos(asin((float)hero->dir_y) + M_PI_2) * MOVE * cst;
		if (data->map[(int)(hero->pos_y + sin(asin((float)hero->dir_y) + M_PI_2)
				* MOVE_SEC * cst)][(int)hero->pos_x] == '0')
		hero->pos_y += sin(asin((float)hero->dir_y) + M_PI_2) * MOVE * cst;
	}
	return ;
}

void	ft_move_player_side(int type, t_data *data, t_hero *hero)
{
	int	cst;

	if (hero->dir_x >= 1.0)
	{
		hero->dir_x = 1.0;
		hero->dir_y = 0.0;
	}
	else if (hero->dir_y >= 1.0)
	{
		hero->dir_y = 1.0;
		hero->dir_x = 0.0;
	}
	if (type == LEFT)
		cst = 1;
	else
		cst = -1;
	if (hero->dir_y >= 0)
		ft_move_side_up(cst, data, hero);
	else
		ft_move_side_down(cst, data, hero);
	return ;
}

void	ft_move_player_straight(int type, t_data *data, t_hero *hero)
{
	if (type == UP)
	{
		if (data->map[(int)hero->pos_y]
			[(int)(hero->pos_x + hero->dir_x * MOVE_SEC)] != '1')
			hero->pos_x += hero->dir_x * MOVE;
		if (data->map[(int)(hero->pos_y + hero->dir_y * MOVE_SEC)]
				[(int)hero->pos_x] != '1')
			hero->pos_y += hero->dir_y * MOVE;
	}
	else if (type == DOWN)
	{
		if (data->map[(int)hero->pos_y]
			[(int)(hero->pos_x - hero->dir_x * MOVE_SEC)] != '1')
			hero->pos_x -= hero->dir_x * MOVE;
		if (data->map[(int)(hero->pos_y - hero->dir_y * MOVE_SEC)]
				[(int)hero->pos_x] != '1')
			hero->pos_y -= hero->dir_y * MOVE;
	}
	return ;
}
