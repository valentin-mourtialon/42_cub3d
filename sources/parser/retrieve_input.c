/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:28:27 by valentin          #+#    #+#             */
/*   Updated: 2023/06/12 17:28:10 by valentin         ###   ########.fr       */
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

static void	fill_filetab(t_data *data)
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
		data->input_infos.filetab[x] = malloc((ft_strlen(line) + 1) * sizeof(char));
		if (data->input_infos.filetab[x] == NULL)
			return (free_tab(data->input_infos.filetab));
		while (line[i] != '\0')
			data->input_infos.filetab[x][y++] = line[i++];
		data->input_infos.filetab[x++][y] = '\0';
		y = 0;
		i = 0;
		free(line);
		line = get_next_line(data->input_infos.fd);
	}
	data->input_infos.filetab[x] = NULL;
}

void	retrieve_input(char *filepath, t_data *data)
{
	data->input_infos.nb_of_lines = count_lines(filepath);
	data->input_infos.filepath = filepath;
	data->input_infos.filetab = malloc((data->input_infos.nb_of_lines + 1) * sizeof(char *));
	if (data->input_infos.filetab == NULL)
		return ;
	data->input_infos.fd = open(filepath, O_RDONLY);
	fill_filetab(data);
	close(data->input_infos.fd);
}