/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:08:06 by vmourtia          #+#    #+#             */
/*   Updated: 2023/07/11 13:56:21 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	throw_error_msg(char *header, char *details, char *body)
{
	char	*msg;

	if (header != NULL && details == NULL && body == NULL)
	{
		ft_putendl_fd(header, STDERR);
		return ;
	}
	msg = ft_strdup(header);
	if (msg != NULL)
		msg = update_join_string(msg, ": ");
	if (details != NULL)
	{
		msg = update_join_string(msg, details);
		msg = update_join_string(msg, ": ");
	}
	if (body != NULL)
		msg = update_join_string(msg, body);
	ft_putendl_fd(msg, STDERR);
	free_ptr(msg);
}
