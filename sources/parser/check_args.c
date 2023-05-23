/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:50:41 by sel-maar          #+#    #+#             */
/*   Updated: 2023/05/23 15:50:55 by vmourtia         ###   ########.fr       */
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
		return (ft_putstr_fd("Invalid filename: a filename should have a .cub extension and should not be empty !\n", 2), 0);
	if (ft_strcmp(&filename[filename_length - extension_length], EXTENSION))
		return (ft_putstr_fd("Invalid extension in file !\n", 2), 0);
	if (!is_valid_filename(av[1]))
		return (ft_putstr_fd("Invalid filename: a filename cannot contain special characters !\n", 2), 0);
	return (1);
}