# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tluu <tluu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 16:56:01 by mdelforg          #+#    #+#              #
#    Updated: 2022/09/21 10:44:11 by tluu             ###   ########.fr        #
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
	   srcs/gnl/get_next_line.c \
	   srcs/gnl/get_next_line_sl.c \
	   srcs/gnl/get_next_line_utils.c \
	   libft/ft_bzero.c \
	   libft/ft_calloc.c \
	   libft/ft_memcpy.c \
	   libft/ft_memset.c \
	   libft/ft_strchr.c \
	   libft/ft_strdup.c \
	   libft/ft_strlen.c \
	   libft/ft_split.c \
	   libft/ft_strjoin.c \
	   libft/ft_strncmp.c \
	   libft/ft_substr.c \
	   libft/ft_strtrim.c \
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
				${MAKE} -C libft
				$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(LINKS) -o $(NAME)

$(MLX):
			make -C mlx

all:		$(NAME)

exe:		all clean

clean:
			make clean -C libft
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C libft
			$(RM) $(NAME)

re:			fclean all

.PHONY:		exe clean fclean re
