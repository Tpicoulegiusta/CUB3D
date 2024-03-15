# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 15:51:24 by tpicoule          #+#    #+#              #
#    Updated: 2024/03/15 14:35:11 by tpicoule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3d

SOURCES		= cub3d.c \
			  parsing.c \
			  parsing_2.c \
			  ft_utils.c \
			  get_next_line.c \
			  get_next_line_utils.c \
			  ft_utils_2.c \
			  parsing_3.c
OBJECTS		= ${SOURCES:.c=.o}
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g
#MLX			= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJECTS}
	${CC} ${CFLAGS} ${MLX} ${OBJECTS} -o ${NAME}

all:		${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re