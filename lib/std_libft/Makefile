# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valentin <valentin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 12:40:08 by sel-maar          #+#    #+#              #
#    Updated: 2023/06/13 15:51:54 by valentin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libstd_libft.a

################################################################################
#                                                                              #
#                              compilation                                     #
#                                                                              #
################################################################################

CC =			cc

CFLAGS =		-Wall -Werror -Wextra -g3

INCLUDES = 		-I./includes

################################################################################
#                                                                              #
#                                sources                                       #
#                                                                              #
################################################################################

SRCS_FILES =	ft_strlen.c \
				ft_strcmp.c \
				ft_strchr.c \
				ft_strjoin.c \
				ft_calloc.c \
				ft_bzero.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_atoi.c \
				ft_split.c \
				ft_putendl_fd.c \
				ft_strdup.c

SRCS_PATH =		sources/

OBJS_PATH =		objects/

OBJS_FILES =	${SRCS:.c=.o}

OBJS =			${addprefix ${OBJS_PATH}, ${OBJS_FILES}}

SRCS = 			${addprefix ${SRCS_PATH}, ${SRCS_FILES}}

################################################################################
#                                                                              #
#                              mandatory                                       #
#                                                                              #
################################################################################

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

.phony: all clean fclean re

################################################################################
#                                                                              #
#                              utilities                                       #
#                                                                              #
################################################################################

RM =			rm -rf
