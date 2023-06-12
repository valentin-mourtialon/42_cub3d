/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:02:20 by valentin          #+#    #+#             */
/*   Updated: 2023/06/12 20:34:19 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

#include "cub3d.h"

static char	*get_texture_path(char *line, int j)
{
	char	*path;
	int		len;
	int		x;

	while (line[y] && (line[y] == ' ' || line[y] == '\t'))
		y++;
	len = y;
	while (line[len] && (line[len] != ' ' && line[len] != '\t'))
		len++;
	path = malloc(sizeof(char) * (len - y + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[y] && (line[y] != ' ' && line[y] != '\t' && line[y] != '\n'))
		path[x++] = line[y++];
	path[x] = '\0';
	while (line[y] && (line[y] == ' ' || line[y] == '\t'))
		y++;
	if (line[y] && line[y] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

static int	cardinal_textures(t_textures_infos *tx_infos, char *line, int y)
{
	if (line[y + 2] && ft_isprint(line[y + 2]))
		return (ERR);
	if (line[y] == 'N' && line[y + 1] == 'O' && !(tx_infos->NO))
		tx_infos->NO = get_texture_path(line, y + 2);
	else if (line[y] == 'S' && line[y + 1] == 'O' && !(tx_infos->SO))
		tx_infos->SO = get_texture_path(line, y + 2);
	else if (line[y] == 'W' && line[y + 1] == 'E' && !(tx_infos->WE))
		tx_infos->WE = get_texture_path(line, y + 2);
	else if (line[y] == 'E' && line[y + 1] == 'A' && !(tx_infos->EA))
		tx_infos->EA = get_texture_path(line, y + 2);
	else
		return (ERROR);
	return (SUCCESS);
}

static int	retrieve_data(t_data *data, char **filetab, int x, int y)
{
	while (filetab[x][y] == ' ' || filetab[x][y] == '\t' || filetab[x][y] == '\n')
		y++;
	if (ft_isprint(filetab[x][y]) && !ft_isdigit(filetab[x][y]))
	{
		if (filetab[x][y + 1] && ft_isprint(filetab[x][y + 1])
			&& !ft_isdigit(filetab[x][y]))
		{
			if (cardinal_textures(&data->textures_infos, filetab[x], y) == ERROR)
				return (printf("INVALID TEXTURE\n"), FAILURE);
			return (BREAK);
		}	
		else
		{
			if (color_textures(data, &data->textures_infos, filetab[x], y) == ERROR)
				return (FAILURE);
			return (BREAK);
		}	
	}
	else if (ft_isdigit(filetab[x][y]))
	{
		if (create_map(data, filetab, x) == FAILURE)
			return (printf("INVALID MAP\n"), FAILURE);
		return (SUCCESS);
	}
	return (CONTINUE);
}

int	parse_file(t_data *data, char **filetab)
{
	int	x;
	int	y;
	int	status;

	i = 0;
	while (filetab[x])
	{
		j = 0;
		while (filetab[x][y])
		{
			status = retrieve_data(data, filetab, x, y);
			if (status == BREAK)
				break ;
			else if (status == FAILURE)
				return (FAILURE);
			else if (status == SUCCESS)
				return (SUCCESS);
			y++;
		}
		x++;
	}
	return (SUCCESS);
}