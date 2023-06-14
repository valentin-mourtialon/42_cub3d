/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:28:47 by valentin          #+#    #+#             */
/*   Updated: 2023/06/14 11:42:15 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	no_digit_found(char *str)
{
	int		i;
	int		no_digit_found;

	i = 0;
	no_digit_found = 1;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			no_digit_found = 0;
		i++;
	}
	return (no_digit_found);
}

static int	*copy_into_rgb_array(char **rgb_to_convert, int *rgb)
{
	int		i;

	i = -1;
	while (rgb_to_convert[++i])
	{
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		if (rgb[i] == -1 || no_digit_found(rgb_to_convert[i]))
			return (free_tab((void **)rgb_to_convert), free(rgb), NULL);
	}
	return (free_tab((void **)rgb_to_convert), rgb);
}

static int	*set_rgb_colors(char *line)
{
	char	**rgb_to_convert;
	int		*rgb;
	int		count;

	rgb_to_convert = ft_split(line, ',');
	count = 0;
	while (rgb_to_convert[count])
		count++;
	if (count != 3)
		return(free_tab((void **)rgb_to_convert), NULL);
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		return (0);
	return (copy_into_rgb_array(rgb_to_convert, rgb));
}

int	colors_textures(t_data *data, t_textures_infos *textures_infos, char *line, int y)
{
	if (line[y + 1] && ft_isprint(line[y + 1]))
		return (throw_error_msg(data->input_infos.filepath, NULL, NULL), ERROR);
	if (!textures_infos->C && line[y] == 'C')
	{
		textures_infos->C = set_rgb_colors(line + y + 1);
		if (textures_infos->C == 0)
			return (printf("-- C : y = %i --\n", y), ERROR);
	}
	else if (!textures_infos->F && line[y] == 'F')
	{
		textures_infos->F = set_rgb_colors(line + y + 1);
		if (textures_infos->F == 0)
			return (printf("-- F : y = %i --\n", y), ERROR);
	}
	else
		return (ERROR);
	return (SUCCESS);
}