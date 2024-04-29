# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 15:51:24 by tpicoule          #+#    #+#              #
#    Updated: 2024/04/24 18:38:59 by tpicoule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

SOURCES		= cub3d.c \
			  parsing.c \
			  parsing_2.c \
			  ft_utils.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  ft_utils_2.c \
			  ft_utils_3.c \
			  parsing_3.c \
			  parsing_4.c \
			  parsing_5.c \
			  parsing_colors.c \
			  parsing_colors_2.c \
			  parsing_colors_2_save.c \
			  parsing_colors_2_save_2.c \
			  parsing_map.c \
			  parsing_map_2.c \
			  parsing_map_3.c \
			  parsing_map_4.c \
			  parsing_reunion.c \
			  repair.c \
			  algo.c \
			  colors.c \
			  inits.c \
			  inputs.c \
			  inputs2.c \
			  mlx_utils.c \
			  multitouch.c \
			  raycasting.c \
			  win_manage.c \
			  innit_obj.c
			  
			  
OBJECTS		= ${SOURCES:.c=.o}
RM			= rm -f
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
MLX			= -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
MLX_LIB		= mlx/libmlx.a

.c.o:
	${CC} ${CFLAGS} -I/usr/include -Imlx -O3 -c $< -o ${<:.c=.o}

${NAME}:	${MLX_LIB} ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} ${MLX} -o ${NAME}

all:		${NAME}

${MLX_LIB}:
	@${MAKE} -C mlx/

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}
	${MAKE} clean -C mlx/

re: fclean all

.PHONY: all clean fclean re
