/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_cardinals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:01:18 by valentin          #+#    #+#             */
/*   Updated: 2023/07/11 13:00:46 by vmourtia         ###   ########.fr       */
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
		return (ERROR);
	if (line[y] == 'N' && line[y + 1] == 'O' && !(textures_infos->no))
		textures_infos->no = get_texture_path(line, y + 2);
	else if (line[y] == 'S' && line[y + 1] == 'O' && !(textures_infos->so))
		textures_infos->so = get_texture_path(line, y + 2);
	else if (line[y] == 'W' && line[y + 1] == 'E' && !(textures_infos->we))
		textures_infos->we = get_texture_path(line, y + 2);
	else if (line[y] == 'E' && line[y + 1] == 'A' && !(textures_infos->ea))
		textures_infos->ea = get_texture_path(line, y + 2);
	else
		return (ERROR);
	return (SUCCESS);
}
