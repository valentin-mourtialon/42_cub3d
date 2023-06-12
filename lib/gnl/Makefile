# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valentin <valentin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 17:47:11 by valentin          #+#    #+#              #
#    Updated: 2023/06/12 17:37:24 by valentin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libgnl.a

CC =			cc

CFLAGS =		-Wall -Werror -Wextra -g3

INCLUDES = 		-I./includes

SRCS_FILES =	get_next_line.c \
				clear.c \
				extract.c \
				memory.c \

SRCS_PATH =		mandatory/

OBJS_PATH =		objects/

OBJS_FILES =	${SRCS:.c=.o}

OBJS =			${addprefix ${OBJS_PATH}, ${OBJS_FILES}}

SRCS = 			${addprefix ${SRCS_PATH}, ${SRCS_FILES}}

all: ${NAME} 

${NAME}: ${OBJS}
				@ar -r ${NAME} ${OBJS}

${OBJS_PATH}%.o: %.c
				@mkdir -p ${dir $@}
				@${CC} ${INCLUDES} -O3 -c $< -o $@

clean:
				@${RM} ${OBJS_PATH} ${NAME}

re: 
				@${MAKE} all

.PHONY: all clean fclean re

RM =			rm -rf
