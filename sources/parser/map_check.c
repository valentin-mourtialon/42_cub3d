/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:40:53 by valentin          #+#    #+#             */
/*   Updated: 2023/06/14 17:14:28 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_map_elements(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = '0';
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			while (is_space(data->map[i][j], 0))
				j++;
			if (!(ft_strchr("10NSEW", map[i][j])))
				return (0);
			if (ft_strchr("NSEW", map[i][j]) && data->player.dir != '0')
				return (0);
			if (ft_strchr("NSEW", map[i][j]) && data->player.dir == '0')
				data->player.dir = map[i][j];
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_position_is_valid(t_data *data, char **map)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (ft_strlen(map[i - 1]) < j || ft_strlen(map[i + 1]) < j
		|| is_space(map[i][j - 1], 1) || is_space(map[i][j + 1], 1)
		|| is_space(map[i - 1][j], 1) || is_space(map[i + 1][j], 1))
		return (0);
	return (1);
}

static int	check_player_position(t_data *data, char **map)
{
	int	x;
	int	y;

	if (data->player.dir == '0')
		return (0);
	x = 0;
	while (map[x])
	{
		x = 0;
		while (map[x][y])
		{
			if (ft_strchr("NSEW", map[x][y]))
			{
				data->player.pos_x = (double)y + 0.5;
				data->player.pos_y = (double)x + 0.5;
				map[x][y] = '0';
			}
			y++;
		}
		x++;
	}
	if (check_position_is_valid(data, map) == 0)
		return (0);
	return (1);
}

static int	check_if_map_is_at_the_end(t_input_infos *infos)
{
	int	x;
	int	y;

	x = infos->index_end_of_map;
	while (infos->filetab[x])
	{
		y = 0;
		while (infos->filetab[x][y])
		{
			if (!is_space(infos->filetab[x][y], INCLUDE_LINE_BREAK))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	check_map(t_data *data, char **map)
{
	if (!data->map)
		return (0);
	if (check_map_sides(&data->input_infos, map) == FAILURE)
		return (0);
	if (data->input_infos.height < 3)
		return (0);
	if (check_map_elements(data, map) == FAILURE)
		return (0);
	if (check_player_position(data, map) == FAILURE)
		return (0);
	if (check_if_map_is_at_the_end(&data->input_infos) == FAILURE)
		return (0);
	return (1);
}