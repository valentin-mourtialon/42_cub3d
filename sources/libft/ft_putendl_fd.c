/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptendl_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:55:35 by sel-maar          #+#    #+#             */
/*   Updated: 2023/05/24 12:04:55 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_putendl_fd(char *str, int fd)
{
	if (str == NULL)
	{
		write(fd, "\n", 1);
		return ;
	}
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}
