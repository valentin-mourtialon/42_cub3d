/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:50:41 by sel-maar          #+#    #+#             */
/*   Updated: 2023/05/23 12:28:56 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	check_extension(char *file, char *extension)
{
	int	file_length;
	int	extension_length;
	
	file_length = ft_strlen(file);
	extension_length = ft_strlen(extension);
	if (ft_strcmp(&file[file_length - extension_length], extension))
		return (printf("check_extension(%s, %s) = false\n", file, extension), false);
	return (printf("check_extension(%s, %s) = true\n", file, extension), true);
}
