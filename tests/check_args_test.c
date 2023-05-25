/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.43.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 3023/05/23 23:14:59 by vmourtia          #+#    #+#             */
/*   Updated: 2023/05/24 15:20:42 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/* Testing all the functions of the file "check_file.c" */ 

typedef struct s_test
{
		int		ac;
		char	*input;
		int		expected;
}	t_test;

void	check_file_test(void)
{
	t_test	test1 = {1; "fichier.cub"; 1};
	t_test	test2 = {3; "fichier.cub"; 1};
	t_test	test3 = {2; "fichier.cu"; 0};
	t_test	test4 = {2; "fichier.cu"; 0};
	t_test	test5 = {2; "fichier.cube"; 0};
	t_test	test6 = {2; "fichiercub"; 0};
	t_test	test7 = {2; ""; 0};
	t_test	test8 = {2; "?fichiercub"; 0};
	t_test	test9 = {2; "fichiercub/"; 0};
	t_test	test10 = {2; ".cub"; 0};

	printf("test 1: %s\n", test1.expected == check_args(test1.ac, test1.input) ? "OK" : "KO");
	printf("test 2: %s\n", test2.expected == check_args(test2.ac, test2.input) ? "OK" : "KO");
	printf("test 3: %s\n", test3.expected == check_args(test3.ac, test3.input) ? "OK" : "KO");
	printf("test 4: %s\n", test4.expected == check_args(test4.ac, test4.input) ? "OK" : "KO");
	printf("test 5: %s\n", test5.expected == check_args(test5.ac, test5.input) ? "OK" : "KO");
	printf("test 6: %s\n", test6.expected == check_args(test6.ac, test6.input) ? "OK" : "KO");
	printf("test 7: %s\n", test7.expected == check_args(test7.ac, test7.input) ? "OK" : "KO");
	printf("test 8: %s\n", test8.expected == check_args(test8.ac, test8.input) ? "OK" : "KO");
	printf("test 9: %s\n", test1.expected == check_args(test9.ac, test9.input) ? "OK" : "KO");
	printf("test 10: %s\n", test1.expected == check_args(test10.ac, test10.input) ? "OK" : "KO");
}

int	main(void)
{
	check_file_test();
	return (0);
}
