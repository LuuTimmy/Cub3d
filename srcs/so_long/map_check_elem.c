/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:52:33 by mdelforg          #+#    #+#             */
/*   Updated: 2022/08/05 16:11:53 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_elem_error(char **map, t_elem *elem)
{
	if (!(elem -> elem_c))
		ft_map_error("why are you so mean, \
let at least one cookie for Mooncake", map);
	if (!(elem -> elem_e))
		ft_map_error("Mooncake is trapped, add an exit to let him free", map);
	if (!(elem -> elem_p))
		ft_map_error("where is Mooncake... \
add a player's starting position to see him", map);
	if (elem -> elem_p > 1)
		ft_map_error("this is not a multiplayer game, \
it must be only one player's starting position", map);
}

void	ft_check_elem(char c, t_elem *elem)
{
	if (c == 'C')
		elem -> elem_c++;
	if (c == 'E')
		elem -> elem_e++;
	if (c == 'P')
		elem -> elem_p++;
	return ;
}

void	ft_elem_init(t_elem *elem)
{
	elem -> elem_c = 0;
	elem -> elem_e = 0;
	elem -> elem_p = 0;
	return ;
}

void	ft_map_check_elem(char **map)
{
	int		i;
	int		j;
	t_elem	elem;

	ft_elem_init(&elem);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_check_elem(map[i][j], &elem);
			j++;
		}
		i++;
	}
	if (!(elem.elem_c) || !(elem.elem_e) || !(elem.elem_p) || elem.elem_e > 1
		|| elem.elem_p > 1)
		ft_elem_error(map, &elem);
	return ;
}

void	ft_check_exten(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (!(str[len] == 'r' && str[len - 1] == 'e'
			&& str[len - 2] == 'b' && str[len - 3] == '.'))
		ft_error_sl("the file must have the extension \".ber\"");
	return ;
}
