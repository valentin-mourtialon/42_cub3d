/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:50:41 by sel-maar          #+#    #+#             */
/*   Updated: 2023/07/11 13:29:29 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_directory(char *arg)
{
	int		fd;

	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
		return (close(fd), 1);
	return (0);
}

int	is_valid_char(char c)
{
	char	*invalid_set;

	invalid_set = ":?<>|*^ ";
	while (*invalid_set)
	{
		if (c == *invalid_set)
			return (0);
		invalid_set++;
	}
	return (1);
}

int	is_valid_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (!is_valid_char(filename[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
	check_input:
		This function is called before the parsing.
		It takes the program arguments ac and av as input 
		It returns 1 if the file provided is valid.
		It returns 0 otherwise. 
*/
int	check_input(int ac, char **av)
{
	char	*filename;
	int		filename_length;
	int		extension_length;
	int		fd;

	if (ac != 2)
		return (throw_error_msg(NB_ARG, NULL, NULL), 0);
	if (is_directory(av[1]))
		return (throw_error_msg(INVALID_ARG, av[1], DIRECTORY), 0);
	filename = av[1];
	filename_length = ft_strlen(filename);
	extension_length = ft_strlen(CUB);
	if (filename_length <= extension_length)
		return (throw_error_msg(INVALID_FILENAME, filename, SHORT_FILENAME), 0);
	if (ft_strcmp(&filename[filename_length - extension_length], CUB))
		return (throw_error_msg(INVALID_FILENAME, filename,
				INVALID_EXTENSION), 0);
	if (!is_valid_filename(filename))
		return (throw_error_msg(INVALID_FILENAME, filename,
				SPECIAL_CHARACTERS), 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (throw_error_msg(NULL, filename, strerror(errno)), 0);
	close(fd);
	return (1);
}
