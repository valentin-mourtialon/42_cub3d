/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:49:52 by sel-maar          #+#    #+#             */
/*   Updated: 2023/06/13 14:13:45 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int ac, char **av)
{
	t_data	data;

	if (check_input(ac, av) == 0)
		return (1);
	init_data(&data);
	if (retrieve_input(av[1], &data) == 0)
		return (1);
	free_data(&data);
	return (0);
}
