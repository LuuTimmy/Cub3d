/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:59:52 by mdelforg          #+#    #+#             */
/*   Updated: 2022/09/21 14:57:08 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_move_init(t_data *data, t_move *move)
{
	move->forward = 0;
	move->back = 0;
	move->left = 0;
	move->right = 0;
	move->turn_l = 0;
	move->turn_r = 0;
	data->move = move;
	return ;
}

char	**ft_textures_tab(t_libx *libx)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 5);
	if (!tab)
		ft_error("Error: Malloc error");
	tab[0] = libx->txtr_w_south;
	tab[1] = libx->txtr_w_north;
	tab[2] = libx->txtr_w_west;
	tab[3] = libx->txtr_w_east;
	tab[4] = NULL;
	return (tab);
}

void	ft_textures_init(t_libx *libx)
{
	int		i;
	char	**tab_txtr;

	i = 0;
	tab_txtr = ft_textures_tab(libx);
	while (i < 4)
	{
		libx->txtr[i].ptr = mlx_xpm_file_to_image(libx->mlx_ptr, tab_txtr[i],
				&(libx->txtr[i].width), &(libx->txtr[i].height));
		if (!libx->txtr[i].ptr)
		{
			free_split(tab_txtr);
			ft_error("Error: mlx_xpm_file_to_image");
		}
		libx->txtr[i].addr = mlx_get_data_addr(libx->txtr[i].ptr,
				&(libx->txtr[i].bits_ppxl), &(libx->txtr[i].sz_line),
				&(libx->txtr[i].endian));
		i++;
	}
	free_split(tab_txtr);
	return ;									// if (!txtr.ptr)
}

void	ft_mlx_init(t_data *data, t_libx *libx, t_img *img)
{
	libx->mlx_ptr = mlx_init();
	libx->mlx_win = mlx_new_window(libx->mlx_ptr, WIDTH, HEIGHT, "oui");
	img->ptr = mlx_new_image(libx->mlx_ptr, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &(img->bits_ppxl), &(img->sz_line),
			&(img->endian));
	libx->img = img;
	data->libx = libx;
	return ;
}

void	ft_rcst_init(int x, t_hero *hero, t_rcst *rcst)
{
	rcst->camera_x = 2 * (double)x / (double)WIDTH - (double)1;
	rcst->raydir_x = hero->dir_x + hero->plane_x * rcst->camera_x;
	rcst->raydir_y = hero->dir_y + hero->plane_y * rcst->camera_x;
	rcst->map_x = (int)hero->pos_x;
	rcst->map_y = (int)hero->pos_y;
	rcst->hit = 0;
	return ;
}
