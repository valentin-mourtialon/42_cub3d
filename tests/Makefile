# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valentin <valentin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 14:10:48 by vmourtia          #+#    #+#              #
#    Updated: 2023/06/26 09:22:22 by valentin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			test

CC =			cc

CFLAGS =		-Wall -Wextra -Werror

INCLUDES =		-I./includes -I../includes -I../lib/mlx_Linux -I../lib/std_libft/includes -I../lib/gnl/includes

SRCS_FILES =	parser/check_input_test.c \
				parser/retrieve_input_test.c \
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

GNL =			-L../lib/gnl/ -lgnl 

all: ${NAME}

${NAME}: ${OBJS}
				@${CC} ${CFLAGS} ${OBJS} ${CUB} ${LIBFT} ${GNL} ${MLX} -o ../${NAME}
				@chmod 000 testfilechmod000

${OBJS_PATH}%.o: %.c
				@mkdir -p $(dir $@)
				@$(CC) ${INCLUDES} -O3 -c $< -o $@

clean:
				@${RM} ${OBJS_PATH} ../${NAME}
				@chmod 777 testfilechmod000

re: 
				@${MAKE} all -s

.PHONY: all clean fclean re
