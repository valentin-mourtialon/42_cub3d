/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:54:11 by valentin          #+#    #+#             */
/*   Updated: 2023/06/13 13:55:36 by valentin         ###   ########.fr       */
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