/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:13:08 by sel-maar          #+#    #+#             */
/*   Updated: 2023/05/23 15:52:09 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/****************************************************/
/*					   INCLUDES  					*/
/****************************************************/

# include "../lib/mlx_Linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>


/****************************************************/
/*					   DEFINES  					*/
/****************************************************/

# define EXTENSION ".cub"

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
/*						LIBFT						*/
/****************************************************/

size_t	ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *str, int fd);

/****************************************************/
/*						PARSER						*/
/****************************************************/

int	check_args(int ac, char **av);

#endif
