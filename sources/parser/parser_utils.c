/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:54:11 by valentin          #+#    #+#             */
/*   Updated: 2023/07/13 18:15:33 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	skip_spaces(char **filetab, int x, int *y)
{
	while (is_space(filetab[x][*y], INCLUDE_LINE_BREAK))
		(*y)++;
}

int	is_space(char c, int include_line_break)
{
	if (include_line_break == 1)
		return (c == ' ' || c == '\t' || c == '\f'
			|| c == '\r' || c == '\v' || c == '\n');
	else
		return (c == ' ' || c == '\t' || c == '\f'
			|| c == '\r' || c == '\v');
}

int	longest_line_length(t_input_infos *input_infos, int start_index)
{
	int	longest_length;
	int	x;

	x = start_index;
	longest_length = ft_strlen(input_infos->filetab[x]);
	while (input_infos->filetab[x])
	{
		if (ft_strlen(input_infos->filetab[x]) > longest_length)
			longest_length = ft_strlen(input_infos->filetab[x]);
		x++;
	}
	return (longest_length);
}

void	print_map(char **map)
{
	int	x;
	int	y;

	printf("\n\nMAP\n\n");
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			printf("%c", map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("\n\n");
}
