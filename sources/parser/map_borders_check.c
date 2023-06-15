/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_borders_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:41:07 by valentin          #+#    #+#             */
/*   Updated: 2023/06/14 17:20:19 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_top_or_bottom(char **map, int i, int j)
{
	if (!map || !map[i] || !map[i][j])
		return (0);
	while (is_space(map[i][j], 0))
		j++;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_map_sides(t_input_infos *infos, char **map)
{
	int	i;
	int	j;

	if (check_top_or_bottom(map, 0, 0) == 0)
		return (0);
	i = 1;
	while (i < (infos->height - 1))
	{
		j = ft_strlen(map[i]) - 1;
		if (map[i][j] != '1')
			return (0);
		i++;
	}
	if (check_top_or_bottom(map, i, 0) == 0)
		return (0);
	return (1);
}