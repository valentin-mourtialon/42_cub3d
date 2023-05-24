# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 12:40:08 by sel-maar          #+#    #+#              #
#    Updated: 2023/05/24 13:26:37 by vmourtia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			cub3D

CC =			cc

CFLAGS =		-Wall -Werror -Wextra -g3

SRCS_FILES =	cub3d.c \
				parser/check_args.c \
				utils/update_join.c \
				exit/free.c \
				error/error_msg.c \
				libft/ft_strlen.c \
				libft/ft_strcmp.c \
				libft/ft_strjoin.c \
				libft/ft_putendl_fd.c \
				libft/ft_strdup.c

SRCS_PATH =		sources/

OBJS_PATH =		objects/

OBJS_FILES =	$(SRCS:.c=.o)

OBJS =			$(addprefix $(OBJS_PATH), $(OBJS_FILES))

SRCS = 			$(addprefix $(SRCS_PATH), $(SRCS_FILES))

RM =			rm -rf

INCLUDES = 		-I/usr/include -I./includes -I./lib/mlx_Linux 

MLX =			-L./lib/mlx_Linux -L/usr/lib -lmlx_Linux -lXext -lX11 -lm -lz 

all: $(NAME) 

$(NAME): $(OBJS)
				@$(MAKE) -C ./lib/mlx_Linux
				@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

$(OBJS_PATH)%.o: %.c
				@mkdir -p $(@D)
				@$(CC) ${INCLUDES} -O3 -c $< -o $@

clean:
				@$(MAKE) clean -C ./lib/mlx_Linux
				@$(RM) $(OBJS_PATH)

fclean: clean
				@$(RM) $(NAME)

re: 
				@$(MAKE) fclean
				@$(MAKE) all

.PHONY: all clean fclean re
