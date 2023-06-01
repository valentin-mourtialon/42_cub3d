/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:58:40 by vmourtia          #+#    #+#             */
/*   Updated: 2023/06/01 14:54:56 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEST_H
# define CUB3D_TEST_H

# include <cub3d.h>

# define BOLD "\033[1m"
# define ITALIC "\033[3m"
# define RESET "\033[0m"
# define LIGHT_RED "\033[91m"
# define LIGHT_GREEN "\033[92m"
# define LIGHT_CYAN "\033[96m"
# define BLUE "\033[34m"

typedef struct s_check_args_test
{
		int		ac;
		char	*input[2];
		int		expected;
}	t_check_args_test;

void	check_args_test(void);

#endif