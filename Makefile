# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 12:40:08 by sel-maar          #+#    #+#              #
#    Updated: 2023/05/22 17:08:23 by vmourtia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			cub3d

CC =			cc

CFLAGS =		-Wall -Werror -Wextra 

SRCS =			cub3d.c \
				parser/parse_arg.c

SRCS_LIBFT	=	libft/ft_strlen.c \
				libft/ft_strncmp.c \
				libft/ft_putstr_fd.c

OBJS_PATH =		objects/

OBJS_FILES =	$(SRCS:.c=.o) $(SRCS_LIBFT:.c=.o)

OBJS =			$(addprefix $(OBJS_PATH), $(OBJS_FILES))

RM =			rm -rf

INCLUDES = 		-I/usr/include -I./includes -Imlx_linux 

MLX =			-Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz 

all: $(NAME) 

$(NAME): $(OBJS)
				$(MAKE) -C mlx_Linux
				$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

$(OBJS_PATH)%.o: %.c
				@mkdir -p $(@D)
				$(CC) ${INCLUDES} -O3 -c $< -o $@

clean:
				$(MAKE) clean -C mlx_Linux
				$(RM) $(OBJS_PATH)

fclean: clean
				$(RM) $(NAME)

re: 
				$(MAKE) fclean
				$(MAKE) all

.PHONY: all clean fclean re
