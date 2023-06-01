# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 14:10:48 by vmourtia          #+#    #+#              #
#    Updated: 2023/06/01 15:44:02 by vmourtia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			test

CC =			cc

CFLAGS =		-Wall -Wextra -Werror

INCLUDES =		-I./includes -I../includes -I../lib/mlx_Linux -I../lib/std_libft/includes

SRCS_FILES =	parser/check_args_test.c \
				main.c

OBJS_FILES =	${SRCS:.c=.o}

SRCS_PATH =		sources/

OBJS_PATH =		objects/

SRCS =			${addprefix ${SRCS_PATH}, ${SRCS_FILES}}

OBJS =			${addprefix ${OBJS_PATH}, ${OBJS_FILES}}

RM =			rm -rf

CUB =			-L.. -lcub3D

LIBFT =			-L../lib/std_libft -lstd_libft

MLX =			-L../lib/mlx_Linux/ -lmlx_Linux 

all: ${NAME}

${NAME}: ${OBJS}
				@${CC} ${CFLAGS} ${OBJS} ${CUB} ${LIBFT} ${MLX} -o ../${NAME}

${OBJS_PATH}%.o: %.c
				@mkdir -p $(dir $@)
				@$(CC) ${INCLUDES} -O3 -c $< -o $@

clean:
				@${RM} ${OBJS_PATH} ../${NAME}

re: 
				@${MAKE} all -s

.PHONY: all clean fclean re
