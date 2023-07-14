/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <sel-maar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:59:49 by valentin          #+#    #+#             */
/*   Updated: 2023/07/14 14:20:50 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	build_top_bottom(t_data *data, int x)
{
	int	y;

	y = 0;
	while (data->map[x][y])
	{
		if (ft_strchr(" 0", data->map[x][y]))
			data->map[x][y] = '1';
		y++;
	}
}

static void	build_left_write(t_data *data, int x)
{
	int	y;

	if (data->map[x][0] != '1')
		data->map[x][0] = '1';
	y = 1;
	while (data->map[x][y] && y < data->input_infos.width - 1)
		y++;
	if (data->map[x][y] && data->map[x][y] != '1')
		data->map[x][y] = '1';
}

int	build_walls(t_data *data)
{
	int	x;

	x = 0;
	while (data->map[x])
	{
		if (x == 0 || x == data->input_infos.height - 1)
			build_top_bottom(data, x);
		else
			build_left_write(data, x);
		x++;
	}
	return (1);
}
//print_map(data->map);