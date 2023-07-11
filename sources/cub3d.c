/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:49:52 by sel-maar          #+#    #+#             */
/*   Updated: 2023/07/11 14:09:55 by vmourtia         ###   ########.fr       */
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
		return (free_data(&data), 1);
	if (parse(&data, data.input_infos.filetab) == 0)
		return (free_data(&data), 1);
	if (check_map(&data, data.map) == 0)
		return (free_data(&data), 1);
	if (check_textures(&data.textures_infos) == 0)
		return (free_data(&data), 1);
	init_player_direction(&data);
	init_mlx(&data);
	init_textures(&data);
	render_images(&data);
	listen_for_input(&data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
