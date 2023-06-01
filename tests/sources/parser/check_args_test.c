/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3023/05/23 23:14:59 by vmourtia          #+#    #+#             */
/*   Updated: 2023/06/01 16:40:37 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Testing all the functions of the file "check_file.c"
*/ 

#include <cub3d_test.h>

void	check_args_test(void)
{
	t_check_args_test	test1 = { 2, { "./cub3D", "fichier.cub" }, 1 };
	t_check_args_test	test2 = { 3, { "./cub3D", "fichier.cub" }, 0 };
	t_check_args_test	test3 = { 2, { "./cub3D", "fichier.cu" }, 0 };
	t_check_args_test	test4 = { 2, { "./cub3D", "fichier.cu b" }, 0 };
	t_check_args_test	test5 = { 2, { "./cub3D", "fichier.cube" }, 0 };
	t_check_args_test	test6 = { 2, { "./cub3D", "fichiercub" }, 0 };
	t_check_args_test	test7 = { 2, { "./cub3D", "" }, 0 };
	t_check_args_test	test8 = { 2, { "./cub3D", "?fichiercub" }, 0 };
	t_check_args_test	test9 = { 2, { "./cub3D", "fichiercub/" }, 0 };
	t_check_args_test	test10 = { 2, { "./cub3D", ".cub" }, 0 };

	printf("\nTesting "LIGHT_CYAN"check_args(int ac, char **av)"RESET" cf sources/parser/\n\n");
	printf("\ttest 1:		%s\n", test1.expected == check_args(test1.ac, test1.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 2:		%s\n", test2.expected == check_args(test2.ac, test2.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 3:		%s\n", test3.expected == check_args(test3.ac, test3.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 4:		%s\n", test4.expected == check_args(test4.ac, test4.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 5:		%s\n", test5.expected == check_args(test5.ac, test5.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 6:		%s\n", test6.expected == check_args(test6.ac, test6.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 7:		%s\n", test7.expected == check_args(test7.ac, test7.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 8:		%s\n", test8.expected == check_args(test8.ac, test8.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 9:		%s\n", test9.expected == check_args(test9.ac, test9.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 10:	%s\n\n", test10.expected == check_args(test10.ac, test10.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
}
