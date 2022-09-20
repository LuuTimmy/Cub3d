/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mini.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:29:23 by mdelforg          #+#    #+#             */
/*   Updated: 2022/08/05 23:47:27 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libc.h>
# include <stdlib.h>
# include "../../mlx/mlx.h"

# include "libft/libft.h"

# define WALLS "srcs/so_long/sprites/mur1.XPM"
# define GROUND "srcs/so_long/sprites/sol1.XPM"
# define COLLECTIBLE "srcs/so_long/sprites/cookie1.XPM"
# define OUT "srcs/so_long/sprites/exit1.XPM"
# define HERO "srcs/so_long/sprites/mooncake1.XPM"

# define MAP_ARG "01CEP"

typedef struct s_elem
{
	int	elem_c;
	int	elem_e;
	int	elem_p;
}				t_elem;

typedef struct s_sprite
{
	void	*img;
	void	*img_p;
	void	*img_g;
	void	*img_e;
	int		img_size;
}	t_sprite;

typedef struct s_mini
{
	char	**map;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		map_len;
	int		map_size;
	int		collect;
	int		moves;
}	t_mini;


int		ft_so_long(int ac, char **av);

//	map_init_check
char	**ft_map_init(char *file);
void	ft_map_check(char **map);
int		ft_map_size(char **map);
void	ft_map_check_elem(char **map);
void	ft_check_exten(char *str);

//	scene_init
void	ft_put_background(t_mini *mini, t_sprite *sprite);
void	ft_put_sprites(t_mini *mini, t_sprite *sprite);

//	movements
void	ft_position(t_mini *mini);
int		ft_key_hook(int keycode, t_mini *mini, t_sprite *sprite);
void	ft_player_move(t_mini *mini, t_sprite *sprt, int x, int y);
int		ft_close_sl(t_mini *mini);

//	error
void	ft_error_sl(char *msg);
void	ft_error_tab_str(char *msg, char *str, char **map);
void	ft_map_error(char *msg, char **map);
void	ft_free_tab_sl(char **tab, size_t i);

//	gnl
char	*get_next_line(int fd);
char	*get_next_line_sl(int fd);

//	libft
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

#endif
