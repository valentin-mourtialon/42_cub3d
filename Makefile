# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 12:40:08 by sel-maar          #+#    #+#              #
#    Updated: 2023/05/22 15:34:42 by sel-maar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			cub3D

CC =			cc

CFLAGS =		-Wall -Werror -Wextra 

SRCS =			cub3d.c \
				parser/parse_arg.c

SRCS_LIBFT	=	libft/ft_strlen.c \
				libft/ft_strncmp.c \
				libft/ft_putstr_fd.c

OBJS =			$(SRCS:.c=.o) $(SRCS_LIBFT:.c=.o)

RM =			rm -rf

INCLUDES = 		-I/usr/include -I./includes -Imlx_linux 

MLX =			-Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz -o 

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(NAME)

%.o: %.c
	$(CC) ${INCLUDES} -O3 -c $< -o $@

clean:

	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: 
		$(MAKE) fclean
		$(MAKE) all

.PHONY :		all clean fclean re
