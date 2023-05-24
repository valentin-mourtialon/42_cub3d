/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:26:41 by vmourtia          #+#    #+#             */
/*   Updated: 2023/05/24 12:48:36 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/*
	update_join_string
		This function take one string "to_be_updated" and updates it by joining
		it with "to_be_joined".
		It frees the initial "to_be_updated".
		
		Example:
		char	*message;

		message = "Warning";
		message = update_join_string(message, ": ");
		message = update_join_string(message, "Please check the man !");
*/
char	*update_join_string(char *to_be_updated, char *to_be_joined)
{
	char	*tmp;

	if (to_be_updated == NULL)
		return (ft_strdup(to_be_joined));
	if (to_be_joined == NULL)
		return (to_be_updated);
	tmp = to_be_updated;
	to_be_updated = ft_strjoin(tmp, to_be_joined);
	free_ptr(tmp);
	return (to_be_updated);
}