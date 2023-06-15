/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:54:11 by valentin          #+#    #+#             */
/*   Updated: 2023/06/14 15:36:42 by valentin         ###   ########.fr       */
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
		return (c == ' ' || c == '\t' || c == '\n');
	else
		return (c == ' ' || c == '\t');
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