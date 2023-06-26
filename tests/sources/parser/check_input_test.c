/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3023/05/23 23:14:59 by vmourtia          #+#    #+#             */
/*   Updated: 2023/06/26 09:26:42 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Testing all the functions of the file "parser/input_check.c"
*/ 

#include <cub3d_test.h>

void	check_input_test(void)
{
	t_check_input_test	test1 = { 2, { "./cub3D", "maps/valid/subject.cub" }, 1 };
	t_check_input_test	test2 = { 3, { "./cub3D", "fichier.cub" }, 0 };
	t_check_input_test	test3 = { 2, { "./cub3D", "fichier.cu" }, 0 };
	t_check_input_test	test4 = { 2, { "./cub3D", "fichier.cu b" }, 0 };
	t_check_input_test	test5 = { 2, { "./cub3D", "fichier.cube" }, 0 };
	t_check_input_test	test6 = { 2, { "./cub3D", "fichiercub" }, 0 };
	t_check_input_test	test7 = { 2, { "./cub3D", "" }, 0 };
	t_check_input_test	test8 = { 2, { "./cub3D", "?fichiercub" }, 0 };
	t_check_input_test	test9 = { 2, { "./cub3D", "fichiercub/" }, 0 };
	t_check_input_test	test10 = { 2, { "./cub3D", ".cub" }, 0 };
	t_check_input_test	test11 = { 2, { "./cub3D", "sources" }, 0 };
	t_check_input_test	test12 = { 2, { "./cub3D", "testfilechmod000" }, 0 };

	printf("\nTesting "LIGHT_CYAN"check_args(int ac, char **av)"RESET" cf sources/parser/\n\n");
	printf("\ttest 1:		%s\n", test1.expected == check_input(test1.ac, test1.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 2:		%s\n", test2.expected == check_input(test2.ac, test2.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 3:		%s\n", test3.expected == check_input(test3.ac, test3.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 4:		%s\n", test4.expected == check_input(test4.ac, test4.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 5:		%s\n", test5.expected == check_input(test5.ac, test5.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 6:		%s\n", test6.expected == check_input(test6.ac, test6.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 7:		%s\n", test7.expected == check_input(test7.ac, test7.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 8:		%s\n", test8.expected == check_input(test8.ac, test8.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 9:		%s\n", test9.expected == check_input(test9.ac, test9.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 10:	%s\n", test10.expected == check_input(test10.ac, test10.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 11:	%s\n", test11.expected == check_input(test11.ac, test11.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 12:	%s\n\n", test12.expected == check_input(test12.ac, test12.input) ? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
}
