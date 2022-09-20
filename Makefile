# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 16:56:01 by mdelforg          #+#    #+#              #
#    Updated: 2022/09/20 15:45:27 by tluu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = srcs/main.c \
	   srcs/init.c \
	   srcs/raycast.c \
	   srcs/keyhook.c \
	   srcs/move.c \
	   srcs/texturing.c \
	   srcs/texturing_utils.c \
	   srcs/launch.c \
	   srcs/exit.c \
	   srcs/so_long/so_long.c \
	   srcs/so_long/background.c \
	   srcs/so_long/error.c \
	   srcs/so_long/map_check.c \
	   srcs/so_long/map_check_elem.c \
	   srcs/so_long/map_init.c \
	   srcs/so_long/move.c \
	   srcs/so_long/gnl/get_next_line.c \
	   srcs/so_long/gnl/get_next_line_sl.c \
	   srcs/so_long/gnl/get_next_line_utils.c \
	   srcs/so_long/libft/ft_bzero.c \
	   srcs/so_long/libft/ft_calloc.c \
	   srcs/so_long/libft/ft_memcpy.c \
	   srcs/so_long/libft/ft_memset.c \
	   srcs/so_long/libft/ft_strchr.c \
	   srcs/so_long/libft/ft_strdup.c \
	   srcs/so_long/libft/ft_strlen.c \
	   srcs/so_long/libft/ft_split.c \
	   srcs/so_long/libft/ft_strjoin.c \
	   srcs/so_long/libft/ft_strncmp.c \
	   srcs/so_long/libft/ft_substr.c \
	   srcs/parsing.c \
	   srcs/parsing_map.c \
	   srcs/parsing_info.c \
	   srcs/parsing_utils.c \
	   srcs/parsing_txtr_color.c \

MLX = mlx

OBJS = $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

#CFLAGS = -Wall -Wextra -Werror

LINKS = -L ./mlx -lmlx -framework OpenGL -framework AppKit

$(NAME):	$(MLX) $(OBJS)
				$(CC) $(CFLAGS)  -fsanitize=address $(OBJS) $(LINKS) -o $(NAME)

$(MLX):
				make -C mlx

all:		$(NAME)

exe:		all clean

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		exe clean fclean re
