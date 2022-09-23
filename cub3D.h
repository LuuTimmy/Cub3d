/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:12:20 by mdelforg          #+#    #+#             */
/*   Updated: 2022/09/23 13:30:56 by tluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <float.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <fcntl.h>
# include "libft/libft.h"

# define EXIT 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define L_ARROW 123
# define R_ARROW 124

# define WIDTH 1920
# define HEIGHT 1080
# define MOVE 0.1
# define MOVE_SEC 0.11
# define TURN 0.05
# define W_NORTH "textures/Stone3.xpm"
# define W_SOUTH "textures/stone.xpm"
# define W_WEST "textures/mur1.XPM"
# define W_EAST "textures/metal.xpm"

typedef struct s_draw
{
	int		tex_x;					// coordonnee sur la texture en x
	int		tex_y;
	double	wall_x;					// coordonnee sur le mur en x
	double	step;					// coefficient a franchir pour chaque pixel
	double	tex_pos;				// coordonnee du depart de la texture
}	t_draw;

typedef struct s_rcst
{
	double	camera_x;				// coordonnee sur le plan de focale (entre -1 et 1)
	double	raydir_x;				// direction d'un rayon en x
	double	raydir_y;
	int		map_x;					// care dans lequel on se trouve en x
	int		map_y;
	double	side_x;					// distance entre le depart et la 1ere arrete en x
	double	side_y;
	double	delta_x;				// distance pour franchir 1 unite de x
	double	delta_y;
	int		step_x;					// savoir si le rayon en x est + ou - (-1 ou 1)
	int		step_y;
	double	perp;					// distance perpendiculaire du rayon
	int		hit;					// savoir si un mur est atteint
	int		face_wall;				// savoir si c'est un mur en x (0) ou en y (1) qui a ete touche
	int		line_height;			// hauteur du mur en perspective
	int		draw_start;				// arrete basse du mur
	int		draw_end;				// arrete haute du mur
}	t_rcst;

typedef struct s_hero
{
	double	pos_x;					// position de depart en x
	double	pos_y;
	double	dir_x;					// direction de depart en x
	double	dir_y;
	double	plane_x;				// demi-largeur du plan de focale en x
	double	plane_y;
}	t_hero;

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
	char	*addr;
	int		bits_ppxl;
	int		sz_line;
	int		endian;

}	t_img;

typedef struct s_libx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	txtr[4];
    char	*txtr_w_north;
    char	*txtr_w_south;
    char	*txtr_w_east;
    char	*txtr_w_west;

	unsigned int	texture_floor;
	unsigned int	texture_ceiling;
	t_img	*img;
}	t_libx;

typedef struct s_move
{
	int		forward;
	int		back;
	int		left;
	int		right;
	int		turn_l;
	int		turn_r;
}	t_move;

typedef struct s_data
{
	char		**map;
	t_hero		*hero;
	t_move		*move;
	t_libx		*libx;
}	t_data;

/*						init.c							*/
void	ft_hero_init(t_data *data, t_hero *hero);
void	ft_move_init(t_data *data, t_move *move);
void	ft_mlx_init(t_data *data, t_libx *libx, t_img *img);
void	ft_textures_init(t_libx *libx);
void	ft_rcst_init(int x, t_hero *hero, t_rcst *rcst);

/*						raycast.c						*/
void	ft_rcst_delta(t_rcst *rcst);
void	ft_rcst_side(t_rcst *rcst, t_hero *hero);
void	ft_rcst_trace(int x, t_rcst *rcst, t_data *data);
void	ft_camera_init(t_rcst *rcst);

/*						keyhook.c						*/
int		ft_key_press(int keycode, t_data *data);
int		ft_key_release(int keycode, t_data *data);

/*						move.c							*/
void	ft_move_player_straight(int type, t_data *data, t_hero *hero);
void	ft_move_player_side(int type, t_data *data, t_hero *hero);
void	ft_turn_player(int type, t_hero *hero);

/*						texturing.c						*/
void	ft_put_texture(int x, t_rcst *rcst, t_data *data);

/*						texturing_utils.c				*/
void	ft_my_put_pixel(t_img *img, int x, int y, int color);
int		ft_get_pixel(t_img *img, int x, int y);
int		ft_get_index(t_rcst *rcst);

/*						launch.c						*/
int		ft_launch(t_data *data);

/*						exit.c							*/
void	ft_error(char *str);
void	*ft_error_char(char *str);
int		ft_error_int(char *str, int i);
int		ft_close(t_data *data);

/*						parsing							*/
void	invert_map(t_data *data);
char	**parse_file(char *file, t_data *data, t_hero *hero);
char	**search_map_info(int fd, t_data *data, char **info);
void	*parsing_map(t_data *data, char **map_temp, t_hero *hero);
int		parse_texture(char *newline, char *line, char *info, t_libx *libx);
size_t	ft_strlcpy_cub(char *dest, const char *src, size_t size);
int		put_hero(t_data *data, t_hero *hero, int i, int j);

//parsing-utils;
int		verif_is_digit(char **str);
size_t	ft_strlcpy_cub(char *dest, const char *src, size_t size);
int		ft_atoi_v(const char *str, int *is_false);
int		count_char(char *str, char c);

char	*get_next_line(int fd);

#endif
