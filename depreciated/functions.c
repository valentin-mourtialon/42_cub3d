/*
	file:
		map_create.c
*/
static int	get_map_info(t_data *data, char **filetab, int x)
{
	data->input_infos.height = count_map_lines(data, filetab, x);
	//if (data->input_infos.height < 0)
	//	return (throw_error_msg("Error\nINVALID SIDES", NULL, NULL), FAILURE);
	data->map = malloc(sizeof(char *) * (data->input_infos.height + 1));
	if (!data->map)
		return (FAILURE);
	if (fill_map(&data->input_infos, data->map, x) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/*
	file:
		map_create.c
*/
static int	check_around(t_data *data, int x, int y)
{
	if (y < data->input_infos.width && data->map[x][y + 1] != '1' &&
		data->map[x][y + 1] != '0' && data->map[x][y + 1] != 'N' &&
		data->map[x][y + 1] != 'S' && data->map[x][y + 1] != 'W'
		&& data->map[x][y + 1] != 'E')
		return (0);
	if (y > 0 && data->map[x][y - 1] != '1' && data->map[x][y - 1] != '0'
		&& data->map[x][y - 1] != 'N' && data->map[x][y - 1] != 'S' &&
		data->map[x][y - 1] != 'W' && data->map[x][y - 1] != 'E')
		return (0);
	if (x < data->input_infos.height && data->map[x + 1][y] != '1'
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

/*
	file:
		map_create.c
*/
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