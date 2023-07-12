/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:03:32 by valentin          #+#    #+#             */
/*   Updated: 2023/07/12 14:41:40 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	count_map_lines(t_data *data, char **filetab, int x)
{
	int	start_map_index;
	int	y;

	start_map_index = x;
	while (filetab[x])
	{
		y = 0;
		while (is_space(filetab[x][y], 0))
			y++;
		if (filetab[x][y] != '1')
			break ;
		x++;
	}
	data->input_infos.index_end_of_map = x;
	return (x - start_map_index);
}

static int	fill_map(t_input_infos *input_infos, char **map, int file_index)
{
	int		x;
	int		y;

	input_infos->width = longest_line_length(input_infos, file_index);
	x = 0;
	while (x < input_infos->height)
	{
		y = 0;
		map[x] = malloc(sizeof(char) * (input_infos->width + 1));
		if (!map[x])
			return (FAILURE);
		while (input_infos->filetab[file_index][y] &&
				input_infos->filetab[file_index][y] != '\n')
		{
			map[x][y] = input_infos->filetab[file_index][y];
			y++;
		}	
		while (y < input_infos->width)
			map[x][y++] = '\0';
		x++;
		file_index++;
	}
	map[x] = NULL;
	return (SUCCESS);
}

static int	get_map_info(t_data *data, char **filetab, int x)
{
	data->input_infos.height = count_map_lines(data, filetab, x);
	data->map = malloc(sizeof(char *) * (data->input_infos.height + 1));
	if (!data->map)
		return (FAILURE);
	if (fill_map(&data->input_infos, data->map, x) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static void	fill_spaces(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (is_space(data->map[x][y], 0))
			y++;
		while (data->map[x][++y])
		{
			if (data->map[x][y] == ' ' && y !=
					data->map[x][ft_strlen(data->map[x]) - 1])
				data->map[x][y] = '1';
		}
		x++;
	}
}

static int	check_around(t_data *data, int x, int y)
{
	if (y < data->input_infos.height && data->map[x][y + 1] != '1' &&
		data->map[x][y + 1] != '0' && data->map[x][y + 1] != 'N' &&
		data->map[x][y + 1] != 'S' && data->map[x][y + 1] != 'W'
		&& data->map[x][y + 1] != 'E')
		return (0);
	if (y > 0 && data->map[x][y - 1] != '1' && data->map[x][y - 1] != '0'
		&& data->map[x][y - 1] != 'N' && data->map[x][y - 1] != 'S' &&
		data->map[x][y - 1] != 'W' && data->map[x][y - 1] != 'E')
		return (0);
	if (x < data->input_infos.width && data->map[x + 1][y] != '1'
		&& data->map[x + 1][y] != '0' && data->map[x + 1][y] != 'N'
		&& data->map[x + 1][y] != 'S' && data->map[x + 1][y] != 'W'
		&& data->map[x + 1][y] != 'E')
		return (0);
	if (x > 0 && data->map[x - 1][y] != '1' && data->map[x - 1][y] != '0'
		&& data->map[x - 1][y] != 'N' && data->map[x - 1][y] != 'S'
		&& data->map[x - 1][y] != 'W' && data->map[x - 1][y] != 'E')
		return (0);
	return (1);
}

static int	check_if_map_is_closed(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if ((data->map[x][y] == '0' || data->map[x][y] == 'N'
				|| data->map[x][y] == 'S' || data->map[x][y] == 'W'
				|| data->map[x][y] == 'E')
				&& check_around(data, x, y) == 0)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	create_map(t_data *data, char **filetab, int x)
{
	if (get_map_info(data, filetab, x) == FAILURE)
		return (FAILURE);
	if (check_if_map_is_closed(data) == 0)
		return (FAILURE);
	fill_spaces(data);
	return (SUCCESS);
}
