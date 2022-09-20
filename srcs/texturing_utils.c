/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:44:37 by mdelforg          #+#    #+#             */
/*   Updated: 2022/09/20 15:51:38 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_my_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->sz_line + x * (img->bits_ppxl / 8));
	*(unsigned int *)dst = color;
	return ;
}

int	ft_get_pixel(t_img *img, int x, int y)
{
	char	*ptr;

	ptr = img->addr + (y * img->sz_line + x * (img->bits_ppxl / 8));
	return (*(int *)ptr);
}

int	ft_get_index(t_rcst *rcst)
{
	if (rcst->face_wall)
	{
		if (rcst->raydir_y < 0)
			return (0);
		return (1);
	}
	if (rcst->raydir_x < 0)
		return (2);
	return (3);
}
