/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:13:08 by sel-maar          #+#    #+#             */
/*   Updated: 2023/06/12 14:56:29 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/****************************************************/
/*					   INCLUDES  					*/
/****************************************************/

# include <mlx.h>
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

/****************************************************/
/*					   DEFINES  					*/
/****************************************************/

# define STDERR 2

# define CUB ".cub"
# define XPM ".xpm"

# define INVALID_ARG "Invalid argument"
# define INVALID_FILENAME "Invalid filename"
# define INVALID_EXTENSION "Invalid extension"
# define DIRECTORY "Input argument should be a filename not a directory."
# define SHORT_FILENAME "A filename should have a .cub extension and should not be empty!"
# define SPECIAL_CHARACTERS "A filename cannot contain special characters!"

/****************************************************/
/*					  STRUCTURES					*/
/****************************************************/

typedef enum e_bool {
	false,
	true,
}	t_bool;

typedef struct s_data_map {
	char	*south;
	char	*north;
	char	*east;
	char	*west;
	int		floor[3];
	int		colors[3];
}	t_data_map;

/****************************************************/
/*						PARSER						*/
/****************************************************/

int		check_args(int ac, char **av);

/****************************************************/
/*						ERROR						*/
/****************************************************/

void	throw_error_msg(char *header, char *details, char *body);

/****************************************************/
/*						EXIT						*/
/****************************************************/

void	free_ptr(void *ptr);

/****************************************************/
/*						UTILS						*/
/****************************************************/

char	*update_join_string(char *to_be_updated, char *to_be_joined);

#endif
