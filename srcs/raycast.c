/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:48:02 by mdelforg          #+#    #+#             */
/*   Updated: 2022/09/21 10:40:07 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
//				retirer so_long.h

void	ft_camera_init(t_rcst *rcst)
{
	rcst->line_height = (int)(HEIGHT / rcst->perp);
	rcst->draw_start = (-(rcst->line_height) / 2) + (HEIGHT / 2);
	if (rcst->draw_start < 0)
		rcst->draw_start = 0;
	rcst->draw_end = (rcst->line_height / 2) + (HEIGHT / 2);
	if (rcst->draw_end > HEIGHT)
		rcst->draw_end = HEIGHT - 1;
	return ;
}

void	ft_trace_perp(int x, t_rcst *rcst, t_data *data)
{
	double	angle_x;

	if (x < WIDTH / 2)
		angle_x = atan(rcst->raydir_x / rcst->raydir_y);
	else
		angle_x = -atan(rcst->raydir_x / rcst->raydir_y);
	if (!(rcst->face_wall))
		rcst->perp = fabs((rcst->map_x - data->hero->pos_x
					+ (1 - rcst->step_x) / 2) / rcst->raydir_x);
	else
		rcst->perp = fabs((rcst->map_y - data->hero->pos_y
					+ (1 - rcst->step_y) / 2) / rcst->raydir_y);
	return ;
}

void	ft_rcst_trace(int x, t_rcst *rcst, t_data *data)
{
	while (!(rcst->hit))
	{
		if (rcst->side_x < rcst->side_y)
		{
			rcst->side_x += rcst->delta_x;
			rcst->map_x += rcst->step_x;
			rcst->face_wall = 0;
		}
		else
		{
			rcst->side_y += rcst->delta_y;
			rcst->map_y += rcst->step_y;
			rcst->face_wall = 1;
		}
		if (data->map[rcst->map_y][rcst->map_x] > '0')
			rcst->hit = 1;
	}
	ft_trace_perp(x, rcst, data);
	return ;
}

void	ft_rcst_side(t_rcst *rcst, t_hero *hero)
{
	if (rcst->raydir_x < 0)
	{
		rcst->step_x = -1;
		rcst->side_x = (hero->pos_x - rcst->map_x) * rcst->delta_x;
	}
	else
	{
		rcst->step_x = 1;
		rcst->side_x = (rcst->map_x + 1.0 - hero->pos_x) * rcst->delta_x;
	}
	if (rcst->raydir_y < 0)
	{
		rcst->step_y = -1;
		rcst->side_y = (hero->pos_y - rcst->map_y) * rcst->delta_y;
	}
	else
	{
		rcst->step_y = 1;
		rcst->side_y = (rcst->map_y + 1.0 - hero->pos_y) * rcst->delta_y;
	}
	return ;
}

void	ft_rcst_delta(t_rcst *rcst)
{
	if (!(rcst->raydir_x))
		rcst->delta_x = DBL_MAX;
	else
		rcst->delta_x = sqrt(1.0 + ((rcst->raydir_y * rcst->raydir_y)
					/ (rcst->raydir_x * rcst->raydir_x)));
	if (!(rcst->raydir_y))
		rcst->delta_y = DBL_MAX;
	else
		rcst->delta_y = sqrt(1.0 + ((rcst->raydir_x * rcst->raydir_x)
					/ (rcst->raydir_y * rcst->raydir_y)));
	return ;
}
