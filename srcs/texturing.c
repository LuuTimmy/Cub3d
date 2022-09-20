/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:55:56 by mdelforg          #+#    #+#             */
/*   Updated: 2022/09/20 15:25:55 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_draw_line(int x, int y, int draw, t_libx *libx)
{
	int	color;

	if (y == 0)
		color = libx->texture_floor;
	else
		color = libx->texture_ceiling;
	while (y < draw)
	{
		ft_my_put_pixel(libx->img, x, y, color);
		y++;
	}
	return ;
}

void	ft_draw_init(t_draw *draw, t_hero *hero, t_rcst *rcst, t_img *txtr)
{
	if (!rcst->face_wall)
		draw->wall_x = hero->pos_y + rcst->perp * rcst->raydir_y;
	else
		draw->wall_x = hero->pos_x + rcst->perp * rcst->raydir_x;
	draw->wall_x -= floor(draw->wall_x);
	draw->tex_x = (int)(draw->wall_x * (double)txtr->width);
	if (!rcst->face_wall && rcst->raydir_x > 0)
		draw->tex_x = txtr->width - draw->tex_x - 1;
	if (rcst->face_wall && rcst->raydir_y < 0)
		draw->tex_x = txtr->width - draw->tex_x - 1;
	draw->step = 1.0 * txtr->height / rcst->line_height;
	draw->tex_pos
		= (rcst->draw_start - HEIGHT / 2 + rcst->line_height / 2) * draw->step;
	return ;
}

void	ft_draw_texture(int x, t_img *txtr, t_rcst *rcst, t_data *data)
{
	int		y;
	t_draw	draw;
	t_img	*img;
	t_hero	*hero;

	img = data->libx->img;
	hero = data->hero;
	y = rcst->draw_start;
	ft_draw_init(&draw, hero, rcst, txtr);
	while (y < rcst->draw_end - 1)
	{
		draw.tex_y = (int)draw.tex_pos & (txtr->height - 1);
		draw.tex_pos += draw.step;
		ft_my_put_pixel(img, x, y,
			ft_get_pixel(txtr, draw.tex_x, draw.tex_pos));
		y++;
	}
	return ;
}

void	ft_put_texture(int x, t_rcst *rcst, t_data *data)
{
	int		i;
	t_img	*txtr;
	t_img	*img;

	txtr = data->libx->txtr;
	img = data->libx->img;
	i = ft_get_index(rcst);
	ft_draw_line(x, 0, rcst->draw_start, data->libx);
	ft_draw_texture(x, &txtr[i], rcst, data);
	ft_draw_line(x, rcst->draw_end, HEIGHT, data->libx);
	return ;
}
