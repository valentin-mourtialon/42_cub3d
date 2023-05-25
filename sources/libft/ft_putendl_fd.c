/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:50:41 by sel-maar          #+#    #+#             */
/*   Updated: 2023/05/25 14:30:44 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_putendl_fd(char *str, int fd)
{
	int	file_length;
	int	extension_length;
	
	file_length = ft_strlen(file);
	extension_length = ft_strlen(extension);
	if (ft_strcmp(&file[file_length - extension_length], extension))
		return (false);
	return (true);
}
