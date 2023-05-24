/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:50:41 by sel-maar          #+#    #+#             */
/*   Updated: 2023/05/24 13:32:09 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static t_bool	is_valid_char(char c)
{
	char	*invalid_set;

	invalid_set = "/:?<>|*^ ";
	while (*invalid_set)
	{
		if (c == *invalid_set || c == '\0')
			return (false);
		invalid_set++;
	}
	return (true);
}

static t_bool	is_valid_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (!is_valid_char(filename[i]))
			return (false);
		i++;
	}
	return (true);
}

/*
	check_args:
		This function is called before the parsing.
		It takes the program arguments ac and av as input 
		It returns 1 if the file provided is valid.
		It returns 0 otherwise. 
*/
int	check_args(int ac, char **av)
{
	char	*filename;
	int		filename_length;
	int		extension_length;
	
	if (ac != 2)
		return (0);
	filename = av[1];
	filename_length = ft_strlen(filename);
	extension_length = ft_strlen(EXTENSION);
	if (filename_length <= extension_length)	
		return (throw_error_msg(INVALID_FILENAME, filename, SHORT_FILENAME), 0);
	if (ft_strcmp(&filename[filename_length - extension_length], EXTENSION))
		return (throw_error_msg(INVALID_FILENAME, filename, INVALID_EXTENSION), 0);
	if (!is_valid_filename(av[1]))
		return (throw_error_msg(INVALID_FILENAME, filename, SPECIAL_CHARACTERS), 0);
	return (1);
}