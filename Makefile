# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valentin <valentin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 12:40:08 by sel-maar          #+#    #+#              #
#    Updated: 2023/06/14 17:01:23 by valentin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			cub3D

NAME_LIB =		libcub3D.a

################################################################################
#                                                                              #
#                              compilation                                     #
#                                                                              #
################################################################################

CC =			cc

CFLAGS =		-Wall -Werror -Wextra -g3

INCLUDES = 		-I/usr/include -I./includes -I./lib/mlx_Linux -I./lib/std_libft/includes -I./lib/gnl/includes

################################################################################
#                                                                              #
#                                sources                                       #
#                                                                              #
################################################################################

SRCS_FILES =	cub3d.c \
				init/init_data.c \
				init/init_input_infos.c \
				init/init_textures_infos.c \
				init/init_player.c \
				parser/input_check.c \
				parser/input_retrieve.c \
				parser/input_parse.c \
				parser/map_create.c \
				parser/map_check.c \
				parser/map_borders_check.c \
				parser/textures_cardinals.c \
				parser/textures_colors.c \
				parser/parser_utils.c \
				utils/update_join.c \
				exit/free.c \
				error/error_msg.c

SRCS_PATH =		sources/

OBJS_PATH =		objects/

OBJS_FILES =	${SRCS:.c=.o}

OBJS =			${addprefix ${OBJS_PATH}, ${OBJS_FILES}}

SRCS = 			${addprefix ${SRCS_PATH}, ${SRCS_FILES}}

################################################################################
#                                                                              #
#                              libraries                                       #
#                                                                              #
################################################################################

MLX =			-L./lib/mlx_Linux -L/usr/lib -lmlx_Linux -lXext -lX11 -lm -lz
LIBFT =			-L./lib/std_libft -lstd_libft
GNL =			-L./lib/gnl -lgnl

################################################################################
#                                                                              #
#                              mandatory                                       #
#                                                                              #
################################################################################

all: title ${NAME} 

${NAME}: make_mlx
				@${CC} ${CFLAGS} ${OBJS} ${MLX} ${GNL} ${LIBFT} -o ${NAME}
				@echo "${LIGHT_CYAN}${BOLD}cub3D	${RESET}${BLUE}${BOLD}${ITALIC}🔥 Ready to fire ! 🔥${RESET}\n\n"

${OBJS_PATH}%.o: %.c
				@mkdir -p ${dir $@}
				@${CC} ${INCLUDES} -O3 -c $< -o $@

clean:
				@${MAKE} clean -s -C ./lib/mlx_Linux
				@${MAKE} clean -s -C ./lib/std_libft
				@${MAKE} clean -s -C ./lib/gnl
				@${MAKE} clean -s -C ./tests
				@${RM} ${OBJS_PATH} logs

fclean: clean
				@${RM} ${NAME} ${NAME_LIB}

re: 
				@${MAKE} fclean -s
				@${MAKE} all -s

.PHONY: all clean fclean re

################################################################################
#                                                                              #
#                                  tests                                       #
#                                                                              #
################################################################################

test: test_title make_cublib
				@./test 2>> logs/test_logs.txt
				@echo "${BOLD}Find test logs in logs/test_logs.txt\n\n${RESET}"

make_cublib: ${NAME_LIB}
				@${MAKE} -s -C ./tests/

${NAME_LIB}: make_mlx
				@ar -r ${NAME_LIB} ${OBJS} 2> logs/make_test_logs.txt

################################################################################
#                                                                              #
#                              utilities                                       #
#                                                                              #
################################################################################

make_mlx: make_gnl
				@${MAKE} -s -C ./lib/mlx_Linux 2> logs/make_mlx_logs.txt 

make_gnl: make_libft
				@${MAKE} -s -C ./lib/gnl 2> logs/make_gnl_logs.txt

make_libft: cub3D_logs
				@${MAKE} -s -C ./lib/std_libft 2> logs/make_libft_logs.txt 

cub3D_logs: success_o2c_files
				@mkdir -p logs
				@echo "${LIGHT_CYAN}${BOLD}cub3D	${RESET}[${LIGHT_GREEN}info${RESET}] : Logs directory successfully created\n"

success_o2c_files: ${OBJS}
				@echo "${LIGHT_CYAN}${BOLD}cub3D	${RESET}[${LIGHT_GREEN}info${RESET}] : Objects directory successfully created"
				@echo "${LIGHT_CYAN}${BOLD}cub3D	${RESET}[${LIGHT_GREEN}info${RESET}] : C-files successfully converted to objects-files"

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

test_title:
				@${CLEAR}
				@echo
				@echo
				@echo "${LIGHT_CYAN}    ████████╗███████╗░██████╗████████╗    ${RESET}"
				@echo "${LIGHT_CYAN}    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝    ${RESET}"
				@echo "${LIGHT_CYAN}    ░░░██║░░░█████╗░░╚█████╗░░░░██║░░░    ${RESET}"
				@echo "${LIGHT_CYAN}    ░░░██║░░░██╔══╝░░░╚═══██╗░░░██║░░░    ${RESET}"
				@echo "${LIGHT_CYAN}    ░░░██║░░░███████╗██████╔╝░░░██║░░░    ${RESET}"
				@echo "${LIGHT_CYAN}    ░░░╚═╝░░░╚══════╝╚═════╝░░░░╚═╝░░░    ${RESET}"
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
