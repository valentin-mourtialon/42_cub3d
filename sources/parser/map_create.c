/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:03:32 by valentin          #+#    #+#             */
/*   Updated: 2023/06/14 15:36:21 by valentin         ###   ########.fr       */
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
		while (input_infos->filetab[file_index][y] && input_infos->filetab[file_index][y] != '\n')
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
			if (data->map[x][y] == ' '
				&& y != data->map[x][ft_strlen(data->map[x]) - 1])
				data->map[x][y] = '1';
		}
		x++;
	}
}

int	create_map(t_data *data, char **filetab, int x)
{
	if (get_map_info(data, filetab, x) == FAILURE)
		return (FAILURE);
	fill_spaces(data);
	return (SUCCESS);
}