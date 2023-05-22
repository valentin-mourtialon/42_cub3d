/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:13:08 by sel-maar          #+#    #+#             */
/*   Updated: 2023/05/22 15:36:43 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_Linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

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

size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
t_bool	is_cub_file(char *file);

#endif
