#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 15:51:24 by tpicoule          #+#    #+#              #
#    Updated: 2024/03/13 16:27:42 by tpicoule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

SOURCES		= cub3d.c \
			  parsing.c \
			  win_manage.c
OBJECTS		= ${SOURCES:.c=.o}
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLX			= -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

.c.o:
	${CC} ${CFLAGS} -I/usr/include -Imlx -O3 -c $< -o ${<:.c=.o}

${NAME}:	minilibx ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} ${MLX} -o ${NAME}

all:		${NAME}

minilibx:
	${MAKE} -C mlx/

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}
	${MAKE} clean -C mlx/

re: fclean all

.PHONY: all clean fclean re
