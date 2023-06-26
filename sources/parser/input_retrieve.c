/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_retrieve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:28:27 by valentin          #+#    #+#             */
/*   Updated: 2023/06/26 12:17:02 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_lines(char *filepath)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(filepath, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static int	fill_filetab(t_data *data)
{
	char	*line;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	line = get_next_line(data->input_infos.fd);
	while (line != NULL)
	{
		data->input_infos.filetab[x] = calloc(ft_strlen(line) + 1, sizeof(char));
		if (data->input_infos.filetab[x] == NULL)
			return (free_tab((void **)data->input_infos.filetab), 0);
		while (line[i] != '\0')
		{
			//printf("%d", data->input_infos.filetab[x][y]);
			data->input_infos.filetab[x][y++] = line[i++];
		}	
		data->input_infos.filetab[x++][y] = '\0';
		//printf("\nx = %d | y = %d", x, y);
		y = 0;
		i = 0;
		free(line);
		line = get_next_line(data->input_infos.fd);
	}
	data->input_infos.filetab[x] = NULL;
	return (1);
}

int	retrieve_input(char *filepath, t_data *data)
{
	data->input_infos.nb_of_lines = count_lines(filepath);
	data->input_infos.filepath = filepath;
	printf("\nNb of lines = %d\n", data->input_infos.nb_of_lines);
	data->input_infos.filetab = calloc(data->input_infos.nb_of_lines + 1, sizeof(char *));
	if (data->input_infos.filetab == NULL)
		return (0);
	data->input_infos.fd = open(filepath, O_RDONLY);
	if (fill_filetab(data) == 0)
		return (0);
	close(data->input_infos.fd);
	return (1);
}
