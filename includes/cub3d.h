/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:13:08 by sel-maar          #+#    #+#             */
/*   Updated: 2023/06/28 13:29:13 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/******************************************************************************/
/*                                                                            */
/*                                includes                                    */
/*                                                                            */
/******************************************************************************/

# include <mlx.h>
# include <get_next_line.h>
# include <libft.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>

/******************************************************************************/
/*                                                                            */
/*                                defines                                     */
/*                                                                            */
/******************************************************************************/

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 900
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 900
# endif

# define CUB ".cub"
# define XPM ".xpm"

# define STDERR 2

# define INCLUDE_LINE_BREAK 1

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define FAILURE 0
# define SUCCESS 1
# define ERROR 2
# define BREAK 3
# define CONTINUE 4

# define INVALID_ARG "Invalid argument"
# define INVALID_FILENAME "Invalid filename"
# define INVALID_EXTENSION "Invalid extension"
# define DIRECTORY "Input argument should be a filename not a directory"
# define SHORT_FILENAME "Filename should have valid ext and should not be empty"
# define SPECIAL_CHARACTERS "A filename cannot contain special characters"

/******************************************************************************/
/*                                                                            */
/*                              structures                                    */
/*                                                                            */
/******************************************************************************/

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_textures_infos {
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	int				*F;
	int				*C;
	unsigned int	hex_floor;
	unsigned int	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_textures_infos;

typedef struct s_input_infos {
	char		**filetab;
	char		*filepath;
	int			fd;
	int			nb_of_lines;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_input_infos;

typedef struct s_player {
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_data {
	void				*mlx;
	void				*win;
	int					win_height;
	int					win_width;
	char				**map;
	int					**textures;
	t_textures_infos	textures_infos;
	t_input_infos		input_infos;
	t_player			player;
}	t_data;

/******************************************************************************/
/*                                                                            */
/*                                  init                                      */
/*                                                                            */
/******************************************************************************/

void	init_data(t_data *data);
void	init_input_infos(t_input_infos *input_infos);
void	init_textures_infos(t_textures_infos *textures_infos);
void	init_player(t_player *player);
void	init_player_direction(t_data *data);
void	init_textures(t_data *data);
void	init_mlx(t_data *data);

/******************************************************************************/
/*                                                                            */
/*                                  parser                                    */
/*                                                                            */
/******************************************************************************/

int		check_input(int ac, char **av);
int		is_valid_filename(char *filename);
int		is_valid_char(char c);
int		is_directory(char *arg);
int		retrieve_input(char *filepath, t_data *data);
int		cardinals_textures(t_textures_infos *textures_infos, char *line, int y);
int		colors_textures(t_data *data, t_textures_infos *textures_infos, char *line, int y);
int		parse(t_data *data, char **filetab);
int		create_map(t_data *data, char **filetab, int x);
int		check_map(t_data *data, char **map);
int		check_map_sides(t_input_infos *infos, char **map);
int		check_textures(t_data *data, t_textures_infos *textures);
int		is_space(char c, int include_line_break);
void	skip_spaces(char **filetab, int x, int *y);
int		longest_line_length(t_input_infos *input_infos, int start_index);

/******************************************************************************/
/*                                                                            */
/*                                  error                                     */
/*                                                                            */
/******************************************************************************/

void	throw_error_msg(char *header, char *details, char *body);

/******************************************************************************/
/*                                                                            */
/*                                  exit                                      */
/*                                                                            */
/******************************************************************************/

void	free_ptr(void *ptr);
void	free_tab(void **tab);
void	free_data(t_data *data);
void	exit_program(t_data *data, int status);

/******************************************************************************/
/*                                                                            */
/*                                  utils                                     */
/*                                                                            */
/******************************************************************************/

char	*update_join_string(char *to_be_updated, char *to_be_joined);

#endif
