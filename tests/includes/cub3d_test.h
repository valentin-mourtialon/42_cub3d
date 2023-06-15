/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:58:40 by vmourtia          #+#    #+#             */
/*   Updated: 2023/06/15 15:23:23 by sel-maar         ###   ########.fr       */
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

typedef struct s_check_input_test
{
		int		ac;
		char	*input[2];
		int		expected;
}	t_check_input_test;

typedef struct s_retrieve_input_test
{
		char	*input;
		int		expected[2];
}	t_retrieve_input_test;

void	check_input_test(void);
void	retrieve_input_test(void);

#endif
