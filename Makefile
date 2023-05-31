# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 12:40:08 by sel-maar          #+#    #+#              #
#    Updated: 2023/05/31 17:50:50 by vmourtia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			cub3D

################################################################################
#                                                                              #
#                              compilation                                     #
#                                                                              #
################################################################################

CC =			cc

CFLAGS =		-Wall -Werror -Wextra -g3

INCLUDES = 		-I/usr/include -I./includes -I./lib/mlx_Linux 

################################################################################
#                                                                              #
#                                sources                                       #
#                                                                              #
################################################################################

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

################################################################################
#                                                                              #
#                              libraries                                       #
#                                                                              #
################################################################################

MLX =			-L./lib/mlx_Linux -L/usr/lib -lmlx_Linux -lXext -lX11 -lm -lz 

################################################################################
#                                                                              #
#                              mandatory                                       #
#                                                                              #
################################################################################

all: title $(NAME) 

${NAME}: ${OBJS}
				@echo "${LIGHT_CYAN}${BOLD}cub3D	${RESET}[${LIGHT_GREEN}info${RESET}] : Objects directory successfully created"
				@echo "${LIGHT_CYAN}${BOLD}cub3D	${RESET}[${LIGHT_GREEN}info${RESET}] : C-files successfully converted to objects-files"
				@mkdir -p logs
				@echo "${LIGHT_CYAN}${BOLD}cub3D	${RESET}[${LIGHT_GREEN}info${RESET}] : Logs directory successfully created\n"
				@${MAKE} -s -C ./lib/mlx_Linux 2> logs/make_mlx_logs.txt 
				@${CC} ${CFLAGS} ${OBJS} ${MLX} -o ${NAME}
				@echo "${LIGHT_CYAN}${BOLD}cub3D	${RESET}${BLUE}${BOLD}${ITALIC}🔥 Ready to fire ! 🔥${RESET}\n\n"

$(OBJS_PATH)%.o: %.c
				@mkdir -p $(dir $@)
				@$(CC) ${INCLUDES} -O3 -c $< -o $@

clean:
				@$(MAKE) clean -s -C ./lib/mlx_Linux
				@$(RM) $(OBJS_PATH) logs

fclean: clean
				@$(RM) $(NAME)

re: 
				$(MAKE) fclean
				$(MAKE) all

.phony: all clean fclean re

################################################################################
#                                                                              #
#                              utilities                                       #
#                                                                              #
################################################################################

title:
				@${CLEAR}
				@echo	
				@echo	
				@echo "${BLUE}    ░█████╗░██╗░░░██╗██████╗░██████╗░██████╗░    ${RESET}"
				@echo "${BLUE}    ██╔══██╗██║░░░██║██╔══██╗╚════██╗██╔══██╗    ${RESET}"
				@echo "${BLUE}    ██║░░╚═╝██║░░░██║██████╦╝░█████╔╝██║░░██║    ${RESET}"
				@echo "${BLUE}    ██║░░██╗██║░░░██║██╔══██╗░╚═══██╗██║░░██║    ${RESET}"
				@echo "${BLUE}    ╚█████╔╝╚██████╔╝██████╦╝██████╔╝██████╔╝    ${RESET}"
				@echo "${BLUE}    ░╚════╝░░╚═════╝░╚═════╝░╚═════╝░╚═════╝░    ${RESET}"
				@echo
				@echo

BOLD =			\033[1m
ITALIC =		\033[3m
RESET =			\033[0m
LIGHT_RED =		\033[91m
LIGHT_GREEN =	\033[92m
LIGHT_CYAN =	\033[96m
BLUE =			\033[34m

CLEAR =			clear

RM =			rm -rf
