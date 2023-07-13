# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valentin <valentin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 12:40:08 by sel-maar          #+#    #+#              #
#    Updated: 2023/07/13 19:01:43 by valentin         ###   ########.fr        #
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

CFLAGS =		-Wall -Werror -Wextra -g -Wno-unused-function

INCLUDES = 		-I/usr/include -I./includes -I./lib/mlx_Linux -I./lib/std_libft/includes -I./lib/gnl/includes

################################################################################
#                                                                              #
#                                sources                                       #
#                                                                              #
################################################################################

SRCS_FILES =	cub3d.c \
				init/init_mlx.c \
				init/init_ray.c \
				init/init_data.c \
				init/init_input_infos.c \
				init/init_textures_infos.c \
				init/init_textures.c \
				init/init_player.c \
				init/init_player_direction.c \
				parser/input_check.c \
				parser/input_retrieve.c \
				parser/input_parse.c \
				parser/map_flood_fill.c \
				parser/map_build_walls.c \
				parser/map_create.c \
				parser/map_check.c \
				parser/map_borders_check.c \
				parser/textures_cardinals.c \
				parser/textures_check.c \
				parser/textures_colors.c \
				parser/parser_utils.c \
				render_val/ray.c \
				render_val/render.c \
				render_val/textures.c \
				render_val/render_utils.c \
				movement/move.c \
				movement/check_move.c \
				movement/rotate.c \
				movement/listener.c \
				utils/update_join.c \
				exit/free.c \
				exit/exit.c \
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
				@${CC} ${OBJS} ${MLX} ${GNL} ${LIBFT} -o ${NAME}
				@echo "${LIGHT_CYAN}${BOLD}cub3D	${RESET}${BLUE}${BOLD}${ITALIC}🔥 Ready to fire ! 🔥${RESET}\n\n"

${OBJS_PATH}%.o: %.c
				@mkdir -p ${dir $@}
				@${CC} ${CFLAGS} -MMD ${INCLUDES} -c $< -o $@

clean:
				@${MAKE} clean -s -C ./lib/mlx_Linux
				@${MAKE} clean -s -C ./lib/std_libft
				@${MAKE} clean -s -C ./lib/gnl
				@${RM} ${OBJS_PATH} logs

fclean: clean
				@${RM} ${NAME} ${NAME_LIB}

re: 
				@${MAKE} fclean -s
				@${MAKE} all -s

-include {OBJS_FILES:.o=.d}

.PHONY: all clean fclean re

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

BOLD =			\033[1m
ITALIC =		\033[3m
RESET =			\033[0m
LIGHT_RED =		\033[91m
LIGHT_GREEN =	\033[92m
LIGHT_CYAN =	\033[96m
BLUE =			\033[34m

CLEAR =			clear

RM =			rm -rf
