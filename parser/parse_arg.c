/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:50:41 by sel-maar          #+#    #+#             */
/*   Updated: 2023/05/22 17:30:26 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_bool	is_cub_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(&file[len - 5], ".cub", 5) == 0)
		return (printf("is_cub_file -> false\n"), false);
	return (printf("is_cub_file -> true\n"), true);
}
