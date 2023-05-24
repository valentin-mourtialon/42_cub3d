/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:13:08 by vmourtia          #+#    #+#             */
/*   Updated: 2023/05/24 14:40:16 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*ft_strdup(char *str)
{
	char	*copy;
	int		i;

	if (str == NULL)
		return (NULL);
	copy = malloc(sizeof(*copy) * (ft_strlen(str) + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}