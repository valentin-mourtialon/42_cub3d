/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 20:02:20 by valentin          #+#    #+#             */
/*   Updated: 2023/06/13 15:42:58 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	extract_parts(t_data *data, char **filetab, int x, int *y)
{
	skip_spaces(filetab, x, y);
	if (ft_isprint(filetab[x][*y]) && !ft_isdigit(filetab[x][*y]))
	{
		if (filetab[x][*y + 1] && ft_isprint(filetab[x][*y + 1]))// && !ft_isdigit(filetab[x][*y]))
		{
			if (cardinals_textures(&data->textures_infos, filetab[x], *y) == ERROR)
				return (printf("INVALID TEXTURE\n"), FAILURE);
			return (BREAK);
		}
		else
		{
			if (colors_textures(data, &data->textures_infos, filetab[x], *y) == ERROR)
				return (FAILURE);
			return (printf("INVAID COLOR\n"), BREAK);
		}
	}
	/*else if (ft_isdigit(filetab[x][*y]))
	{
		if (create_map(data, filetab, x) == FAILURE)
			return (printf("INVALID MAP\n"), FAILURE);
		return (SUCCESS);
	}*/
	return (CONTINUE);
}

int	parse(t_data *data, char **filetab)
{
	int	x;
	int	y;
	int	status;

	x = 0;
	while (filetab[x])
	{
		y = 0;
		while (filetab[x][y])
		{
			status = extract_parts(data, filetab, x, &y);
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
