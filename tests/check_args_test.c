/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:59 by vmourtia          #+#    #+#             */
/*   Updated: 2023/05/25 14:41:46 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/* Testing all the functions of the file "check_file.c" */ 

typedef struct s_test {
	char	*input;
	char	*expected;
}	t_test;

void	check_file_test(void)
{
	t_test	test1;
	
	file_length = ft_strlen(file);
	extension_length = ft_strlen(extension);
	if (ft_strcmp(&file[file_length - extension_length], extension))
		return (false);
	return (true);
}

int	main(void) {
	check_file_test();
	return (0);
}