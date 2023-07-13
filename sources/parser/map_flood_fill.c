/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:13:26 by valentin          #+#    #+#             */
/*   Updated: 2023/07/13 18:20:29 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	*find_starting_position(char **map)
{
	int	*starting_point;
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (ft_strchr("NSEW", map[x][y]))
			{
				starting_point = malloc(sizeof(*starting_point) * 2);
				if (starting_point == NULL)
					return (NULL);
				starting_point[0] = x;
				starting_point[1] = y;
				return (starting_point);
			}
			y++;
		}
		x++;
	}
	return (NULL);
}

static char	**copy_map(t_input_infos input_infos, char **original)
{
	char	**new;
	int		x;
	int		y;

	new = ft_calloc(input_infos.height + 1, sizeof(*new));
	if (new == NULL)
		return (NULL);
	x = 0;
	while (original[x])
	{
		new[x] = ft_calloc(input_infos.width + 1, sizeof(**new));
		if (new[x] == NULL)
			return (NULL);
		y = 0;
		while (original[x][y])
		{
			new[x][y] = original[x][y];
			y++;
		}
		x++;
	}
	return (new);
}

static int	dfs(t_input_infos input_infos, char **map, int x, int y)
{
	if ((x == 0 && map[x][y] == '0')
		|| (x == input_infos.height - 1 && map[x][y] == '0')
		|| (y == 0 && map[x][y] == '0')
		|| (y == input_infos.width - 1 && map[x][y] == '0')
		|| (!ft_strchr("01Z", map[x][y])))
		return (printf("FAIL AT x = %d, y = %d\n", x, y), 0);
	if (map[x][y] == '1' || map[x][y] != '0')
		return (1);
	map[x][y] = 'Z';
	if (dfs(input_infos, map, x + 1, y) == 0)
		return (0);
	if (dfs(input_infos, map, x - 1, y) == 0)
		return (0);
	if (dfs(input_infos, map, x, y + 1) == 0)
		return (0);
	if (dfs(input_infos, map, x, y - 1) == 0)
		return (0);
	return (1);
}

/*
	old = '0';
	new = 'Z';
*/
static int	run_flood_fill(t_input_infos input_infos, char **map, int *start)
{
	if (map[start[0]][start[1]] != '0')
		return (0);
	if (dfs(input_infos, map, start[0], start[1]) == 0)
		return (0);
	return (1);
}

/*
	printf("\ninitial position : x = %d, y = %d\n", starting_point[0],  starting_point[1]);
*/
int	flood_fill(char **map, t_input_infos input_infos)
{
	char	**ff_map;
	int		*starting_point;

	starting_point = find_starting_position(map);
	if (starting_point == NULL)
		return (throw_error_msg(ERR_NO_PLAYER, NULL, NULL), FAILURE);
	ff_map = copy_map(input_infos, map);
	if (!ff_map)
	{
		free_ptr((void *)starting_point);
		return (throw_error_msg(ERR_FF_INIT, NULL, NULL), FAILURE);
	}
	print_map(ff_map);
	ff_map[starting_point[0]][starting_point[1]] = '0';
	if (run_flood_fill(input_infos, ff_map, starting_point) == 0)
	{
		free_ptr((void *)starting_point);
		free_tab((void **)ff_map);
		return (throw_error_msg(ERR_MAP_OPEN, NULL, NULL), FAILURE);
	}
	free_ptr((void *)starting_point);
	free_tab((void **)ff_map);
	return (SUCCESS);
}