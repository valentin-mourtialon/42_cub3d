/* ************************************************************************** */ /*                                                                            */ /*                                                        :::      ::::::::   */ /*   retrieve_input_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:19:01 by sel-maar          #+#    #+#             */
/*   Updated: 2023/06/14 12:04:36 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Testing all the functions of the file "parser/input_retireve.c"
*/ 

#include <cub3d_test.h>

void	retrieve_input_test(void)
{
	t_data data[10];

	t_retrieve_input_test	test1 = { "maps/valid/subject.cub", {1, 21} };
	t_retrieve_input_test	test2 = { "maps/valid/mapstest.cub", {1, 34} };
	t_retrieve_input_test	test3 = { "maps/nonvalid/biglinemap.cub", {0, 5733} };
	t_retrieve_input_test	test4 = { "maps/nonvalid/emptymap.cub", {0, 0} };
	t_retrieve_input_test	test5 = { "maps/valid/tinymap.cub", {1, 11} };

	printf("\nTesting "LIGHT_CYAN"retrieve_inputs(char *pathfile, t_data data)"RESET" cf sources/parser/\n\n");
	printf("\ttest 1:		%s\n", (test1.expected[1] == retrieve_input(test1.input, &data[0]) && test1.expected[1] == data[0].input_infos.nb_of_lines )? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 2:		%s\n", (test2.expected[1] == retrieve_input(test2.input, &data[1]) && test1.expected[1] == data[1].input_infos.nb_of_lines )? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 3:		%s\n", (test3.expected[1] == retrieve_input(test3.input, &data[2]) && test1.expected[1] == data[2].input_infos.nb_of_lines )? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 4:		%s\n", (test4.expected[1] == retrieve_input(test4.input, &data[3]) && test1.expected[1] == data[3].input_infos.nb_of_lines )? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
	printf("\ttest 5:		%s\n\n", (test5.expected[1] == retrieve_input(test5.input, &data[4]) && test1.expected[1] == data[4].input_infos.nb_of_lines )? LIGHT_GREEN"OK"RESET : LIGHT_RED"KO"RESET);
}
