/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_cardinals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:01:18 by valentin          #+#    #+#             */
/*   Updated: 2023/06/14 12:36:25 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static char	*get_texture_path(char *line, int y)
{
	char	*path;
	int		len;
	int		x;

	while (line[y] && is_space(line[y], 0))
		y++;
	len = y;
	while (line[len] && !is_space(line[len], 0))
		len++;
	path = malloc(sizeof(char) * (len - y + 1));
	if (!path)
		return (NULL);
	x = 0;
	while (line[y] && !is_space(line[y], INCLUDE_LINE_BREAK))
		path[x++] = line[y++];
	path[x] = '\0';
	while (line[y] && is_space(line[y], 0))
		y++;
	if (line[y] && line[y] != '\n')
		return (free(path), NULL);
	return (path);
}

int	cardinals_textures(t_textures_infos *textures_infos, char *line, int y)
{
	if (line[y + 2] && ft_isprint(line[y + 2]))
		return (printf("\n-- ERROR : y = %i : line = %s", y, line), ERROR);
	if (line[y] == 'N' && line[y + 1] == 'O' && !(textures_infos->NO))
		textures_infos->NO = get_texture_path(line, y + 2);
	else if (line[y] == 'S' && line[y + 1] == 'O' && !(textures_infos->SO))
		textures_infos->SO = get_texture_path(line, y + 2);
	else if (line[y] == 'W' && line[y + 1] == 'E' && !(textures_infos->WE))
		textures_infos->WE = get_texture_path(line, y + 2);
	else if (line[y] == 'E' && line[y + 1] == 'A' && !(textures_infos->EA))
		textures_infos->EA = get_texture_path(line, y + 2);
	else
		return (printf("\n--2 : y = %i --\n", y), ERROR);
	return (SUCCESS);
}