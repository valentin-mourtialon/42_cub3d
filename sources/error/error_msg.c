/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:08:06 by vmourtia          #+#    #+#             */
/*   Updated: 2023/06/29 14:09:14 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	throw_error_msg(char *header, char *details, char *body)
{
	char	*msg;

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
